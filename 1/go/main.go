package main

import "fmt"

const MAX int = 1000
func jumper(start int,max int) chan int {
    ch := make(chan int)
    go func() {
        for i:=start; i < max; i+=start{
            ch <- i
        }
        close(ch)
    }()
    return ch
}
func main(){
    res := make(chan int)
    go func() {
        threes:= jumper(3,MAX)
        fives:= jumper(5,MAX)
        fifteens:=jumper(15,MAX)
        for temp:=<-threes;temp!=0;temp=<-threes{
            temp += <-fives
            if !closed(fifteens){
                temp -= <-fifteens
            }
            res<-temp
        }
        close(res)
    }()
    tot:=0
    lasttot:=0
    for i:=0; ; i++{
        tot += <-res
        if lasttot == tot{
            break
        }
        lasttot = tot
    }

    fmt.Println(tot)
}
