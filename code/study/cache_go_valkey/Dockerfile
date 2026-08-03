# Etapa de Build (Atualizado para a versão mais recente do Go)
FROM golang:1.24-alpine AS builder
WORKDIR /app
COPY . .

# Permite que o Go baixe automaticamente uma toolchain mais recente se necessário
ENV GOTOOLCHAIN=auto

RUN go mod init benchmark && go mod tidy
RUN CGO_ENABLED=0 GOOS=linux go build -o main .

# Etapa Final (container leve)
FROM alpine:latest
WORKDIR /root/
COPY --from=builder /app/main .
CMD ["./main"]
