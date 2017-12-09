package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
)
const MAX = 80
func findpath(m [][]int) (ret int){
	c := make([][]int,MAX)
	for i:=0; i < MAX; i++{
		c[i] = make([]int,MAX)
		for j:=0; j<MAX; j++{
			c[i][j] = m[i][j]
		}
	}
	for j:=1; j < MAX; j++{
		c[0][j] += c[0][j-1]
		for i:=1; i < MAX; i++{
			if c[i-1][j] < c[i][j-1]{
				c[i][j] += c[i-1][j]
			} else {
				c[i][j] += c[i][j-1]
			}
		}
		for k:=MAX-2; k >= 0; k--{
			if (c[k+1][j]+m[k][j]) < c[k][j] {
				c[k][j] = (c[k+1][j]+m[k][j])
			}
		}
	}
	ret = c[MAX-1][MAX-1]
	for i:=0; i < MAX; i++{
		if c[i][MAX-1] < ret {
			ret = c[i][MAX-1]
		}
	}
	return
}
func main(){
	file, err := os.Open("matrix.txt")
	//file, err := os.Open("test.txt")
	if err != nil {
		fmt.Println(err)
		return
	}
	defer file.Close()
	matrix := make([][]int,MAX)
	for i:=0; i < MAX; i++{
		matrix[i] = make([]int,MAX)
	}
	filebuf := bufio.NewReader(file)
	j:=0
	for line,_,_:=filebuf.ReadLine();line!=nil;line,_,_=filebuf.ReadLine(){
		ss := strings.Split(string(line),",")
		for i:=0; i < MAX; i++{
			fmt.Sscanf(ss[i],"%d",&matrix[j][i])
		}
		j++
	}
	fmt.Println(findpath(matrix))
}
