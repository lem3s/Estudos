package main

import (
  "fmt"
  "os"
)

func checkError(e error) {
  if e != nil {
    panic(e)
  }
}

func main() {
  entireFile, err := os.ReadFile("RandomNumbers.txt")
  checkError(err)
  fmt.Println(entireFile)
}
