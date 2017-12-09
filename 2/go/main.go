package main

import "fmt"

func evenfib(max int) chan int {
    ch:=make(chan int)
    go func(){
        for a,b:=1,2; a<max;a,b=b,a+b{
            if (a&0x1)==0{
                ch <-a
            }
        }
        close(ch)
    }()
    return ch
}
func main(){
    f:=evenfib(4000000)
    ans:=0
    for !closed(f){
        ans+=<-f
    }
    fmt.Println(ans)
}
