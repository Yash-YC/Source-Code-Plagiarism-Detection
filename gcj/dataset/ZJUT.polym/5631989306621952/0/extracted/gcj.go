package main

import (
	"fmt"
)

func main() {
	var T int
	var s string
	cas := 1
	fmt.Scanf("%d", &T)
	for cas <= T {
		fmt.Scanf("%s", &s)
		ans := ""
		for k, c := range s {
			if ans == "" {
				ans += s[k : k+1]
			} else {
				if int(c) >= int(ans[0]) {
					ans = s[k:k+1] + ans
				} else {
					ans += s[k : k+1]
				}
			}

		}
		fmt.Printf("Case #%d: %s\n", cas, ans)
		cas++
	}
}
