package main

import (
	"fmt"
	"math/rand"
  "time"
)

// Estrutura do node
type Node struct {
	key     int
	priority int
	left    *Node
	right   *Node
}

// Cria um novo node com uma nova chave e prioridade
func NewNode(key, priority int) *Node {
	return &Node{
		key:      key,
		priority: priority,
	}
}

// Insere um novo node
func (n *Node) Insert(key, priority int) *Node {
	if n == nil {
		return NewNode(key, priority)
	}

	if key < n.key {
		n.left = n.left.Insert(key, priority)
		if n.left.priority > n.priority {
			n = n.rotateRight()
		}
	} else if key > n.key {
		n.right = n.right.Insert(key, priority)
		if n.right.priority > n.priority {
			n = n.rotateLeft()
		}
	}

	return n
}

// Verifica se existe um node com um certo valor
func (n *Node) Search(key int) bool {
	if n == nil {
		return false
	}
	if key < n.key {
		return n.left.Search(key)
	} else if key > n.key {
		return n.right.Search(key)
	}
	return true // key found
}

// Remove um node de uma strutura treap dada uma certa chave.
func (n *Node) Delete(key int) *Node {
	if n == nil {
		return nil
	}
	if key < n.key {
		n.left = n.left.Delete(key)
	} else if key > n.key {
		n.right = n.right.Delete(key)
	} else {
		if n.left == nil {
			return n.right
		} else if n.right == nil {
			return n.left
		}
		if n.left.priority < n.right.priority {
			n = n.rotateLeft()
			n.left = n.left.Delete(key)
		} else {
			n = n.rotateRight()
			n.right = n.right.Delete(key)
		}
	}
	return n
}

// Faz uma rotação a esquerda em um determinado node
func (n *Node) rotateRight() *Node {
	x := n.left
	n.left = x.right
	x.right = n
	return x
}

// Faz uma rotação a esquerda em um determinado node
func (n *Node) rotateLeft() *Node {
	x := n.right
	n.right = x.left
	x.left = n
	return x
}

// Imprime de maneira recursiva em ordema a chave e prioridade dos nodes dado um node raiz
func (n *Node) InOrder() {
	if n == nil {
		return
	}
	n.left.InOrder()
	fmt.Printf("(%d, %d) ", n.key, n.priority)
	n.right.InOrder()
}

func main() {
  // Cria o node raiz
	var root *Node

  // Cria um slice (similar a uma lista) com as chaves que futuramente serão inseridos 
	keys := []int{4, 2, 6, 1, 3, 5, 7}

  // Para cada chave gera um valor aleatório e cria um novo node e já insere-o na estrutura treap 
	for _, key := range keys {
    start := time.Now()

		priority := rand.Intn(100) // generate random priority
		root = root.Insert(key, priority)

    duration := time.Since(start)
    fmt.Printf("# Inserção levou: %v\n", duration)
	}

  // Imprime em ordem a estrutura treap
  fmt.Println("Treap em ordem:")
  root.InOrder()
  fmt.Println()

  // Procura por chaves

  fmt.Println("Procurando por chaves:")
  keysToSearch := []int{2, 5, 8}
  for _, key := range keysToSearch {
    start := time.Now()

    if root.Search(key) {
      fmt.Printf("Chave %d existe na Treap.\n", key)
    } else {
      fmt.Printf("Chave %d não existe na Treap.\n", key)
    }

    duration := time.Since(start)
    fmt.Printf("# Busca levou: %v\n", duration)
  }


  // Remove certas chaves
  keysToDelete := []int{3, 6}
  for _, key := range keysToDelete {
    start := time.Now()

    root = root.Delete(key)

    fmt.Printf("Chave deletada %d.\n", key)
    duration := time.Since(start)
    fmt.Printf("# Deleção levou: %v\n", duration)
  }

  // Imprime a Treap atualizada
  fmt.Println("Treap em ordem após deleção:")
  root.InOrder()
}
