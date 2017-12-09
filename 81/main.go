package main

import (
	"fmt"
	"os"
	"bufio"
	"strings"
)
const MAX = 80
func findpath(m [][]int) int{
	for i:=MAX-2; i>=0; i--{
		m[i][MAX-1] += m[i+1][MAX-1]
		m[MAX-1][i] += m[MAX-1][i+1]
	}
	for j:=MAX-2; j>=0; j--{
		for i:=MAX-2; i>=0; i--{
			if m[i][j+1] < m[i+1][j] {
				m[i][j] += m[i][j+1]
			} else {
				m[i][j] += m[i+1][j]
			}
		}
	}
	return m[0][0]
}
func main(){
	file, err := os.Open("matrix.txt")
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
		for i:=0; i < 80; i++{
			fmt.Sscanf(ss[i],"%d",&matrix[j][i])
		}
		j++
	}
	fmt.Println(findpath(matrix))
}
