package main

// cgo CFLAGS: -I/home/bobo/Code/include/
// cgo LDFLAGS: -L/home/bobo/Code/lib/
// #include "euler.h"
import "C"
import "fmt"
func main() {

	p:= C.primesieve(100,false,false)
	fmt.Println(p.isprime(11))

}
