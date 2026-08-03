CREATE DATABASE IF NOT EXISTS testdb;
USE testdb;

CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL
);

-- Inserindo um usuário de teste
INSERT INTO users (id, name, email) VALUES (1, 'John Doe', 'john@example.com')
ON DUPLICATE KEY UPDATE name='John Doe';
