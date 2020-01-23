// Use `go run foo.go` to run your program

package main

import (
	. "fmt"
	"runtime"
	"time"
)

var i = 0

func incrementing() {
	for k := 0; k < 1000000; k++ {
		i = i + 1
	}
}

func decrementing() {
	for k := 0; k < 1000000; k++ {
		i = i - 1
	}
}

func main() {
	runtime.GOMAXPROCS(10) // I guess this is a hint to what GOMAXPROCS does...
	// Try doing the exercise both with and without it!
	go incrementing()
	go decrementing()
	println("NumCPU: ", runtime.NumCPU)
	// TODO: Spawn both functions as goroutines

	// We have no way to wait for the completion of a goroutine (without additional syncronization of some sort)
	// We'll come back to using channels in Exercise 2. For now: Sleep.
	time.Sleep(100 * time.Millisecond)
	Println("The magic number is:", i)
}
