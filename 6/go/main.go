package main

import "fmt"

func sumsquares(max int,ch chan int){
    ans:=0
    for i:=1;i<=max;i++{
        ans+=(i*i)
    }
    ch <- ans
}
func squaresums(max int,ch chan int){
    ans:=0
    for i:=1;i<=max;i++{
        ans+=i
    }
    ch<-(ans*ans)
}
func main(){
    a:=make(chan int)
    b:=make(chan int)
    go sumsquares(100,a)
    go squaresums(100,b)
    fmt.Println(((<-b)-(<-a)))
}
