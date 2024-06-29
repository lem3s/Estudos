package main

import (
    "bufio"
    "fmt"
    "math/rand"
    "os"
    "strconv"
    "time"
)

// Define uma struct para a tabela hash
type HashTable struct {
    keys   []int
    values []int
    size   int
}

// Função de hashing
func hash(key, size int) int {
    return key % size
}

// Função para criar uma nova tabela hash
func NewHashTable(size int) *HashTable {
    return &HashTable{
        keys:   make([]int, size),
        values: make([]int, size),
        size:   size,
    }
}

// Função para adicionar um valor à tabela hash
func (ht *HashTable) Put(value int) {
    index := hash(value, ht.size)
    i := 1

    // Use sondagem quadrática para encontrar uma posição vazia
    for ht.keys[index] != 0 && ht.keys[index] != value {
        index = (index + i*i) % ht.size
        i++
    }

    ht.keys[index] = value
    ht.values[index] = value
}

// Função para buscar um valor na tabela hash
func (ht *HashTable) Get(value int) (int, bool) {
    index := hash(value, ht.size)
    i := 1

    for ht.keys[index] != 0 {
        if ht.keys[index] == value {
            return index, true
        }
        index = (index + i*i) % ht.size
        i++
    }
    return -1, false
}

// Função para ler números do arquivo e armazená-los na tabela hash
func loadNumbers(filename string, ht *HashTable) error {
    file, err := os.Open(filename)
    if err != nil {
        return err
    }
    defer file.Close()

    scanner := bufio.NewScanner(file)
    for scanner.Scan() {
        num, err := strconv.Atoi(scanner.Text())
        if err != nil {
            return err
        }
        ht.Put(num)
    }

    if err := scanner.Err(); err != nil {
        return err
    }

    return nil
}

// Função principal
func main() {
    // Iniciar o cronômetro
    start := time.Now()

    // Criar uma nova tabela hash
    ht := NewHashTable(2000033) // Tamanho primo para reduzir colisões, ajustado para ~2 milhões de slots

    // Carregar números do arquivo na tabela hash
    err := loadNumbers("RandomNumbers.txt", ht)
    if err != nil {
        fmt.Println("Error loading numbers:", err)
        return
    }

    // Gerar 100 números aleatórios e buscar na tabela hash
    rand.Seed(time.Now().UnixNano())
    for i := 0; i < 100; i++ {
        num := rand.Intn(1000000) // Assumindo que os números estão nessa faixa
        if index, found := ht.Get(num); found {
            fmt.Printf("Number %d found at index %d\n", num, index)
        } else {
            fmt.Printf("Number %d not found\n", num)
        }
    }

    // Finalizar o cronômetro e imprimir o tempo de execução total
    elapsed := time.Since(start)
    fmt.Printf("Execution time: %s\n", elapsed)
}
