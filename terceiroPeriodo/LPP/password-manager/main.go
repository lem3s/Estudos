package main

import (
	"bufio"
	"crypto/aes"
	"crypto/cipher"
	"crypto/rand"
	"encoding/hex"
	"flag"
	"fmt"
	"io"
	"log"
	"math/big"
	"os"
	"strings"
)

const tamanhoSenha = 16
const caracteres = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+<>?"

var chave = []byte("uma chave para disciplina de LPP") // 32 bytes
const arquivoSenhas = "senhas.txt"

func gerarSenha(tamanho int) (string, error) {
	senha := make([]byte, tamanho)
	for i := range senha {
		num, err := rand.Int(rand.Reader, big.NewInt(int64(len(caracteres))))
		if err != nil {
			return "", err
		}
		senha[i] = caracteres[num.Int64()]
	}
	return string(senha), nil
}

func criptografar(texto string) (string, error) {
	bloco, err := aes.NewCipher(chave)
	if err != nil {
		return "", err
	}

	textoCriptografado := make([]byte, aes.BlockSize+len(texto))
	iv := textoCriptografado[:aes.BlockSize]
	if _, err := io.ReadFull(rand.Reader, iv); err != nil {
		return "", err
	}

	stream := cipher.NewCFBEncrypter(bloco, iv)
	stream.XORKeyStream(textoCriptografado[aes.BlockSize:], []byte(texto))

	return fmt.Sprintf("%x", textoCriptografado), nil
}

func descriptografar(textoCriptografado string) (string, error) {
	dadosCriptografados, _ := hex.DecodeString(textoCriptografado)
	bloco, err := aes.NewCipher(chave)
	if err != nil {
		return "", err
	}

	if len(dadosCriptografados) < aes.BlockSize {
		return "", fmt.Errorf("texto criptografado muito curto")
	}
	iv := dadosCriptografados[:aes.BlockSize]
	dadosCriptografados = dadosCriptografados[aes.BlockSize:]

	stream := cipher.NewCFBDecrypter(bloco, iv)
	stream.XORKeyStream(dadosCriptografados, dadosCriptografados)

	return string(dadosCriptografados), nil
}

func salvarSenha(servico, senha string) error {
	arquivo, err := os.OpenFile(arquivoSenhas, os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0600)
	if err != nil {
		return err
	}
	defer arquivo.Close()

	senhaCriptografada, err := criptografar(senha)
	if err != nil {
		return err
	}

	_, err = arquivo.WriteString(fmt.Sprintf("%s:%s\n", servico, senhaCriptografada))
	return err
}

func obterSenha(servico string) (string, error) {
	arquivo, err := os.Open(arquivoSenhas)
	if err != nil {
		return "", err
	}
	defer arquivo.Close()

	scanner := bufio.NewScanner(arquivo)
	for scanner.Scan() {
		linha := scanner.Text()
		partes := strings.SplitN(linha, ":", 2)
		if len(partes) != 2 {
			continue
		}
		if partes[0] == servico {
			return descriptografar(partes[1])
		}
	}

	return "", fmt.Errorf("serviço não encontrado")
}

func main() {
	acao := flag.String("acao", "gerar", "Ação a ser realizada: gerar, salvar, obter")
	servico := flag.String("servico", "", "Nome do serviço")
	senha := flag.String("senha", "", "Senha a ser salva")
	tamanho := flag.Int("tamanho", tamanhoSenha, "Comprimento da senha gerada")

	flag.Parse()

	switch *acao {
	case "gerar":
		if *servico == "" {
			log.Fatalf("Serviço deve ser fornecido para salvar a senha gerada")
		}
		senhaGerada, err := gerarSenha(*tamanho)
		if err != nil {
			log.Fatalf("Erro ao gerar senha: %v", err)
		}
		fmt.Printf("Senha gerada para %s: %s\n", *servico, senhaGerada)
		err = salvarSenha(*servico, senhaGerada)
		if err != nil {
			log.Fatalf("Erro ao salvar senha: %v", err)
		}
		fmt.Println("Senha gerada e salva com sucesso")
	case "salvar":
		if *servico == "" || *senha == "" {
			log.Fatalf("Serviço e senha devem ser fornecidos")
		}
		err := salvarSenha(*servico, *senha)
		if err != nil {
			log.Fatalf("Erro ao salvar senha: %v", err)
		}
		fmt.Println("Senha salva com sucesso")
	case "obter":
		if *servico == "" {
			log.Fatalf("Serviço deve ser fornecido")
		}
		senhaObtida, err := obterSenha(*servico)
		if err != nil {
			log.Fatalf("Erro ao obter senha: %v", err)
		}
		fmt.Printf("Senha para %s: %s\n", *servico, senhaObtida)
	default:
		log.Fatalf("Ação desconhecida: %s", *acao)
	}
}
