package main

import (
	"context"
	"database/sql"
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"os"
	"time"

	_ "github.com/go-sql-driver/mysql"
	"github.com/valkey-io/valkey-go"
)

type User struct {
	ID    int    `json:"id"`
	Name  string `json:"name"`
	Email string `json:"email"`
}

func main() {
	ctx := context.Background()

	// Lendo variáveis de ambiente do Docker Compose
	dbHost := os.Getenv("DB_HOST")
	valkeyHost := os.Getenv("VALKEY_HOST")

	// 1. Conexão com o MySQL
	dsn := fmt.Sprintf("root:rootpassword@tcp(%s:3306)/testdb?parseTime=true", dbHost)
	var db *sql.DB
	var err error

	log.Println("Conectando ao MySQL...")
	for i := 1; i <= 10; i++ {
		db, err = sql.Open("mysql", dsn)
		if err == nil && db.Ping() == nil {
			break
		}
		log.Printf("Tentativa %d: MySQL ainda não está pronto, aguardando...", i)
		time.Sleep(2 * time.Second)
	}
	if err != nil {
		log.Fatalf("Não foi possível conectar ao MySQL: %v", err)
	}
	defer db.Close()

	// 2. Conexão com o Valkey
	log.Println("Conectando ao Valkey...")
	var valkeyClient valkey.Client
	for i := 1; i <= 10; i++ {
		valkeyClient, err = valkey.NewClient(valkey.ClientOption{InitAddress: []string{valkeyHost}})
		if err == nil {
			break
		}
		log.Printf("Tentativa %d: Valkey ainda não está pronto, aguardando...", i)
		time.Sleep(2 * time.Second)
	}
	if err != nil {
		log.Fatalf("Não foi possível conectar ao Valkey: %v", err)
	}
	defer valkeyClient.Close()

	// Definindo TTL baixo propositalmente para testar a expiração e o Cache Miss depois
	ttlSeconds := 5 * time.Second
	userID := 1

	log.Println("\n==================================================")
	log.Println(" INICIANDO Bateria de Testes (Rodará por 1 minuto) ")
	log.Println("==================================================")

	startTime := time.Now()
	requestCount := 0

	// Loop rodando por exatamente 1 minuto
	for time.Since(startTime) < 60*time.Second {
		requestCount++
		log.Printf("\n--- Requisição #%d ---", requestCount)

		// Medir tempo total da requisição
		reqStart := time.Now()
		_, source, err := GetUser(ctx, db, valkeyClient, userID, ttlSeconds)
		duration := time.Since(reqStart)

		if err != nil {
			log.Printf("[ERRO] Falha ao buscar usuário: %v", err)
		} else {
			log.Printf("[ORIGEM: %s] Tempo de resposta: %d ms", source, duration.Milliseconds())
		}

		// Pausa de 1.5 segundos entre as requisições para observarmos o TTL de 5s expirando
		time.Sleep(1500 * time.Millisecond)
	}

	log.Println("\n==================================================")
	log.Println(" Teste finalizado com sucesso! Encerrando app.     ")
	log.Println("==================================================")
}

func GetUser(ctx context.Context, db *sql.DB, valkeyClient valkey.Client, userID int, ttl time.Duration) (*User, string, error) {
	cacheKey := fmt.Sprintf("user:%d", userID)

	// Tenta buscar no Cache (Valkey)
	cmdGet := valkeyClient.B().Get().Key(cacheKey).Build()
	val, err := valkeyClient.Do(ctx, cmdGet).ToString()

	if err == nil {
		var user User
		if json.Unmarshal([]byte(val), &user) == nil {
			return &user, "CACHE HIT (Valkey)", nil
		}
	}

	// Cache Miss: Busca no MySQL (simulando lentidão opcional de rede/query com um pequeno sleep se quiser, ou direto)
	query := "SELECT id, name, email FROM users WHERE id = ?"
	row := db.QueryRowContext(ctx, query, userID)

	var user User
	err = row.Scan(&user.ID, &user.Name, &user.Email)
	if err != nil {
		return nil, "", err
	}

	// Salva no Cache com o TTL definido
	jsonBytes, err := json.Marshal(user)
	if err == nil {
		cmdSet := valkeyClient.B().Set().Key(cacheKey).Value(string(jsonBytes)).Ex(ttl).Build()
		_ = valkeyClient.Do(ctx, cmdSet).Error()
	}

	return &user, "CACHE MISS (MySQL)", nil
}

// Servidor HTTP básico só para manter o container vivo caso queira testar via curl também
func init() {
	go func() {
		http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
			w.Write([]byte("Benchmark App Running"))
		})
		http.ListenAndServe(":8080", nil)
	}()
}
