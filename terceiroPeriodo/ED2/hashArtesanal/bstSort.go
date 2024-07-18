// Alunos: João Victor Lemes e Yasmin Moura
package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
	"time"
)

type Node struct {
	valor    int
	esquerda *Node
	direita  *Node
}

type ArvoreBinariaBusca struct {
	root *Node
}

func (arvore *ArvoreBinariaBusca) inserir(valor int) {
	arvore.root = inserirRecursivo(arvore.root, valor)
}

func inserirRecursivo(node *Node, valor int) *Node {
	if node == nil {
		return &Node{valor: valor}
	}
	if valor < node.valor {
		node.esquerda = inserirRecursivo(node.esquerda, valor)
	} else if valor > node.valor {
		node.direita = inserirRecursivo(node.direita, valor)
	}
	return node
}

func (arvore *ArvoreBinariaBusca) ordem(node *Node, wr *bufio.Writer) {
	if node != nil {
		arvore.ordem(node.esquerda, wr)
		_, err := wr.WriteString(strconv.Itoa(node.valor) + "\n")
		if err != nil {
			log.Fatal("Erro ao escrever no arquivo:", err)
		}
		arvore.ordem(node.direita, wr)
	}
}

func lerNumerosDoArquivo(caminho string) ([]int, error) {
	arquivo, err := os.Open(caminho)
	if err != nil {
		return nil, fmt.Errorf("arquivo não encontrado: %w", err)
	}
	defer arquivo.Close()

	var numeros []int
	scanner := bufio.NewScanner(arquivo)
	for scanner.Scan() {
		numero, err := strconv.Atoi(strings.TrimSpace(scanner.Text()))
		if err == nil {
			numeros = append(numeros, numero)
		}
	}
	if err := scanner.Err(); err != nil {
		return nil, fmt.Errorf("erro ao ler o arquivo: %w", err)
	}

	return numeros, nil
}

func escreverNumerosOrdenados(caminho string, arvore *ArvoreBinariaBusca) error {
	arquivo, err := os.Create(caminho)
	if err != nil {
		return fmt.Errorf("erro ao criar o arquivo: %w", err)
	}
	defer arquivo.Close()

	writer := bufio.NewWriter(arquivo)
	arvore.ordem(arvore.root, writer)
	return writer.Flush()
}

func main() {
	tempoInicial := time.Now()

	arvore := &ArvoreBinariaBusca{}

	numeros, err := lerNumerosDoArquivo("RandomNumbers.txt")
	if err != nil {
		log.Fatal(err)
	}

	for _, numero := range numeros {
		arvore.inserir(numero)
	}

	if err := escreverNumerosOrdenados("SortedNumbers.txt", arvore); err != nil {
		log.Fatal(err)
	}

	tempoDecorrido := time.Since(tempoInicial)

	fmt.Printf("Tempo decorrido: %.3f segundos\n", tempoDecorrido.Seconds())
}
