package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
)
const MAX = 80
func findpath(m [][]int) int{
	c := make([][]int,MAX)
	for i:=0; i < MAX; i++ {
		c[i] = make([]int,MAX)
		for j:=0; j < MAX; j++{
			c[i][j]= int(^uint(0) >> 1)
		}
	}
	c[0][0] = m[0][0]
	for i:=0; i < MAX; i++{
		for j:=0; j < MAX; j++{
			//right
			if j+1<MAX && (c[i][j]+m[i][j+1])<c[i][j+1]{
				c[i][j+1]=c[i][j]+m[i][j+1]
			}
			//down
			if i+1<MAX && (c[i][j]+m[i+1][j])<c[i+1][j]{
				c[i+1][j]=c[i][j]+m[i+1][j]
			}
			left := false
			up := false
			//left
			if j-1>=0 && (c[i][j]+m[i][j-1])<c[i][j-1]{
				c[i][j-1]=c[i][j]+m[i][j-1]
				left = true
			}
			//up
			if i-1>=0 && (c[i][j]+m[i-1][j])<c[i-1][j]{
				c[i-1][j]=c[i][j]+m[i-1][j]
				up = true
			}
			if left {
				j-=2
			}
			if up {
				i--
				j--
			}
		}
	}
	return c[MAX-1][MAX-1]
}
func main(){
	file, err := os.Open("matrix.txt")
	//file, err := os.Open("test.txt")
	if err != nil {
		fmt.Println(err)
		return
	}
	defer file.Close()
	matrix := make([][]int,80)
	for i:=0; i < 80; i++{
		matrix[i] = make([]int,80)
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
