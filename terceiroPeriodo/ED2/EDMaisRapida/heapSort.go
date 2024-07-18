// Alunos: João Victor Lemes e Yasmin Moura
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

	if left < n && arr[left] > arr[largest] {
		largest = left
	}

	if right < n && arr[right] > arr[largest] {
		largest = right
	}

	if largest != i {
		arr[i], arr[largest] = arr[largest], arr[i] // troca

		heapify(arr, n, largest)
	}
}

// Função principal para realizar o heap sort
func heapSort(arr []int) {
	n := len(arr)
	buildMaxHeap(arr, n)

	for i := n - 1; i > 0; i-- {
		arr[i], arr[0] = arr[0], arr[i]

		heapify(arr, i, 0)
	}
}

// Função para construir um heap máximo a partir de um array
func buildMaxHeap(arr []int, n int) {
	for i := n/2 - 1; i >= 0; i-- {
		heapify(arr, n, i)
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
	for scanner.Scan() {
		aSerInserido, err := strconv.Atoi(scanner.Text())
		if err != nil {
			fmt.Printf("Erro ao converter a linha para inteiro: %v\n", scanner.Text())
			continue
		}

		numbers = append(numbers, aSerInserido)
	}

	buildMaxHeap(numbers, len(numbers))

	heapSort(numbers)

	arquivoDeSaida, err := os.Create("SortedNumbers.txt")
	if err != nil {
		fmt.Println("Erro ao criar o arquivo de saída:", err)
		return
	}
	defer arquivoDeSaida.Close()

	writer := bufio.NewWriter(arquivoDeSaida)
	for _, num := range numbers {
		fmt.Fprintln(writer, num)
	}

	if err := writer.Flush(); err != nil {
		fmt.Println("Erro ao salvar os números ordenados:", err)
	}

	tempoDecorrido := time.Since(startTime)
	fmt.Printf("Tempo decorrido: %s\n", tempoDecorrido)
}
