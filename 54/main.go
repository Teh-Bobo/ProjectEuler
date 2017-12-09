package main

import (
	"fmt"
	"bufio"
	"os"
	"sort"
)

type card struct {
	val, suit int
}
//This method is a lie
//It returns >= to reverse the sort order
func (t *card) Less(c *card) bool{
	if t.val > c.val {
		return true
	}
	return false
}
func (c card) String() string	{ return string(c.val+48) + string(c.suit) }

//First three methods are for sorting
type hand struct {
	cards []card
}
//type hand [5]card
func (h *hand) Len() int		{ return len(h.cards) }
func (h *hand) Swap(i, j int)		{ h.cards[i], h.cards[j] = h.cards[j], h.cards[i] }
func (h *hand) Less(i, j int)	bool	{ return h.cards[i].Less(&h.cards[j]) }
type handtypes func([]card) []card
func pair(h []card) []card {
	if len(h) < 2 { return nil }
	for i:=0; i < len(h)-1; i++ {
		if h[i].val == h[i+1].val {
			return h[i+1:]
		}
	}
	return nil
}
func twopair(h []card) []card {
	if t:=pair(h); t!=nil && pair(t[1:])!=nil{
		return h
	}
	return nil
}
func threekind(h []card) []card {
	if len(h) < 3 { return nil }
	for i:=0; i < len(h)-2; i++{
		if h[i].val == h[i+1].val && h[i+1].val == h[i+2].val {
			return h[i:i]
		}
	}
	return nil
}
func straight(h []card) []card {
	if len(h) < 2 { return nil }
	for i:=0; i < len(h)-1; i++ {
		if h[i].val != (h[i+1].val+1) {
			return nil
		}
	}
	return h
}
func flush(h []card) []card {
	if len(h) < 2 { return nil }
	for i:=0; i < len(h)-1; i++{
		if h[i].suit != h[i+1].suit {
			return nil
		}
	}
	return h
}
func fullhouse(h []card) []card{
	if len(h) != 5 { return nil }
	if p:=pair(h); p==nil || threekind(p[1:]) == nil {
		return nil
	}
	return h
}
func fourkind(h []card) []card{
	if len(h) < 4 {return nil}
	for i:=0; i < len(h)-3; i++{
		if h[i].val==h[i+1].val && h[i+1].val==h[i+2].val && h[i+2].val==h[i+3].val{
			fmt.Println("4 kind:",h)
			return h[i:]
		}
	}
	return nil
}
func stflush(h []card) []card{
	if straight(h) != nil && flush(h) != nil {
		fmt.Println("Straight flush:",h)
		return h
	}
	return nil
}
func (a hand) iswinner(b hand) bool {
	funcs := [8]handtypes{}
	funcs[7] = pair
	funcs[6] = twopair
	funcs[5] = threekind
	funcs[4] = straight
	funcs[3] = flush
	funcs[2] = fullhouse
	funcs[1] = fourkind
	funcs[0] = stflush
	for _,f := range funcs {
		p1 := f(a.cards)
		p2 := f(b.cards)
		if p1==nil && p2==nil {continue}
		if p1!=nil && p2!=nil {return p2[0].val < p1[0].val}
		if p1==nil {return false}
		if p2==nil {return true}
	}
	for i,_ := range a.cards{
		if a.cards[i].val != b.cards[i].val {
			return a.cards[0].val > b.cards[0].val
		}
	}
	//Hands have the exact same values
	//shouldn't happen in this example
	fmt.Println("IS WINNER RETURNED A TIE")
	os.Exit(-1)
	return false
}
func chartoint(b byte) int {
	if b < 58 {
		return int(b - 48)
	}
	switch b {
	case 'T': return 10
	case 'J': return 11
	case 'Q': return 12
	case 'K': return 13
	case 'A': return 14
	default: fmt.Println("Somthing broke real good: " + string(b))
	}
	return -1
}
func main() {
	file, err := os.Open("poker.txt")
	if err != nil {
		return
	}
	defer file.Close()
	p1 := hand{make([]card,5)}
	p2 := hand{make([]card,5)}
	winsforp1 := 0
	buf := bufio.NewReader(file)
	for line,_,_ := buf.ReadLine();line!=nil;line,_,_=buf.ReadLine(){
		for i:=0;i<5;i++{
			p1.cards[i] = card{chartoint(line[i*3]),int(line[i*3+1])}
			p2.cards[i] = card{chartoint(line[i*3+15]),int(line[i*3+16])}
		}
		sort.Sort(&p1)
		sort.Sort(&p2)
		if p1.iswinner(p2) {
			winsforp1++
		}
	}
	fmt.Println(winsforp1)
}

