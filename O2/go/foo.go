// Use `go run foo.go` to run your program

package main

import (
	. "fmt"
	"runtime"
)

var i = 0

func incrementing(c chan int) {
	for k := 0; k < 1000000; k++ {
		c <- 1
	}
	close(c)
}

func decrementing(c chan int) {
	for k := 0; k < 1000000; k++ {
		c <- 1
	}
	close(c)
}

func main() {
	runtime.GOMAXPROCS(10) // I guess this is a hint to what GOMAXPROCS does...
	// Try doing the exercise both with and without it!
	c1 := make(chan int)
	c2 := make(chan int)

	go incrementing(c1)
	go decrementing(c2)

	for {
		select {
		case x, ok := <-c1:
			if !ok {
				c1 = nil
				_ = x
			} else {
				i++
			}

		case x, ok := <-c2:
			if !ok {
				c2 = nil
				_ = x
			} else {
				i--
			}
		default:
			Println("The magic number is:", i)
			return
		}
	}

}
