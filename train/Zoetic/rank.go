package main

import (
	"fmt"
	"sort"
	"strings"
)

func main() {
  var T int
  fmt.Scanf("%d", &T)
  for t := 1; t <= T; t++ {

    var N, item int
    fmt.Scanf("%d", &N)
		paired := make(map[int]bool)
		for row := 0; row < 2 * N - 1; row++ {
			for h := 0; h < N; h++ {
				fmt.Scanf("%d", &item)
				it, ok := paired[item]
				if ok {
					delete(paired, item)
				} else {
					paired[item] = it
				}
			}
		}
		keys := make([]int, 0, len(paired))
    for k := range paired {
        keys = append(keys, k)
    }
		sort.Ints(keys)
		res := make([]string, len(keys))
		for i, r := range keys {
			res[i] = fmt.Sprintf("%d", r)
		}
    fmt.Printf("Case #%d: %s\n", t, strings.Join(res, " "))
  }
}
