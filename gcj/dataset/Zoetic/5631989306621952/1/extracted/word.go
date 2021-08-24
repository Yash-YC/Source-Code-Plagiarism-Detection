package main

import (
	"fmt"
	"strings"
)

func main() {
  var T int
  fmt.Scanf("%d", &T)
  for t := 1; t <= T; t++ {

    var S string
    fmt.Scanf("%s", &S)
    fmt.Printf("Case #%d: ", t)
    solve(S)
  }
}

func solve(S string) {
	last := ""
	for _, c := range S {
		prepend := string(c) + last
		append := last + string(c)
		if strings.Compare(prepend, append) > 0 {
			last = prepend
		} else {
			last = append
		}
	}
	fmt.Println(last)
}
