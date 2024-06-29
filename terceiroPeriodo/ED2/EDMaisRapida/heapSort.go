package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"time"
)

// Função para criar um heap máximo
func heapify(arr []int, n int, i int) {
	largest := i
	left := 2*i + 1
	right := 2*i + 2

	// Se o filho esquerdo é maior que o nó pai
	if left < n && arr[left] > arr[largest] {
		largest = left
	}

	// Se o filho direito é maior que o nó pai
	if right < n && arr[right] > arr[largest] {
		largest = right
	}

	// Se o maior valor não é o nó pai
	if largest != i {
		arr[i], arr[largest] = arr[largest], arr[i] // troca

		// Recursivamente heapify a subárvore afetada
		heapify(arr, n, largest)
	}
}

// Função principal para realizar o heap sort
func heapSort(arr []int) {
	n := len(arr)

	// Construir o heap (rearranjar o array)
	for i := n/2 - 1; i >= 0; i-- {
		heapify(arr, n, i)
	}

	// Um por um extrair um elemento do heap
	for i := n - 1; i > 0; i-- {
		// Mover a raiz atual para o final
		arr[i], arr[0] = arr[0], arr[i]

		// Chamar max heapify no heap reduzido
		heapify(arr, i, 0)
	}
}

func main() {
	startTime := time.Now()

	caminhoDoArquivo := "./RandomNumbers.txt"

	leArquivo, err := os.Open(caminhoDoArquivo)
	if err != nil {
		fmt.Println(err)
		return
	}
	defer leArquivo.Close()

	scanner := bufio.NewScanner(leArquivo)
	scanner.Split(bufio.ScanLines)

  numbers := []int{}
  for scanner.Scan(){
    aSerInserido, _ := strconv.Atoi(scanner.Text())
    numbers = append(numbers, aSerInserido);
  }

  heapSort(numbers)

	tempoDecorrido := time.Since(startTime)
	fmt.Printf("Tempo decorrido: %s\n", tempoDecorrido)
}
