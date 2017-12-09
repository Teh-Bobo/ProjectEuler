package main

import (
	"fmt"
	"strings"
//	"strconv"
)

func main(){
	result := 0
	index := 0.0
	value := ""
	for i:=float64(2.0); i<10; i++{
		a := fmt.Sprintf("%v",1.0/i)
		a = a[2:len(a)-1]
		if a != ""{
			r := srs(a)
			if r > result{
				index = i
				value = a
				result = r
			}
		}
	}
	fmt.Println(index,value,result)
}
func srs(s string) int{
	for j:=0; j < len(s)-1; j++{
		for k:=j+2; k < len(s); k++{
			if strings.Count(s,s[j:k]) > 2{
				fmt.Println(strings.Count(s,s[j:k]),k-j,s,s[j:k])
				return k-j
			}
		}
	}
	return 0
}
