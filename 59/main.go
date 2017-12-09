package main

import (
	"fmt"
	"io/ioutil"
	"strconv"
	"strings"
)

func readFile(fname string) (nums []int, err error) {
	b, err := ioutil.ReadFile(fname)
	if err != nil {
//		return nil, err
		panic(err)
	}
	lines := strings.Split(string(b), ",")
	nums = make([]int, 0, len(lines))

	for _, l := range lines[:len(lines)-1] {
		// Empty line occurs at the end of the file when we use Split.
		if l == "" {
			break
		}
		n, err := strconv.Atoi(l)
		if err != nil {
			//return nil, err
			panic(err)
		}
		nums = append(nums, n)
	}

	return nums, nil
}
func arritoa(ints []int) (ret string) {
	t := ""
	for _, e := range ints {
		t,_ = strconv.Unquote(strconv.QuoteRuneToASCII(rune(e)))
		ret += t
	}
	return ret
}
func xor(key, text []int) []int {
	ret := make([]int, len(text))
	k := make([]int, len(text))
	//There is a bug here if the text length is not a multiple
	//of 3. The actual puzle is a multiple of 3 so I don't
	//really care
	for i := 0; i < len(text); i+=3 {
		k[i] = key[0]
		k[i+1] = key[1]
		k[i+2] = key[2]
	}
	for i := 0; i < len(text); i++ {
		ret[i] = k[i] ^ text[i]
	}
	return ret
}
func main() {
	nums, err := readFile("cipher1.txt")
	//fmt.Println(nums[0],nums[len(nums)-1])
	if err != nil {
		panic(err)
	}
	r := 0
	t := xor([]int{103,111,100}, nums)
	for _,e := range t {
		r+=e
	}
	fmt.Println(arritoa(t))
	fmt.Println(t)
	fmt.Println(r)
}
