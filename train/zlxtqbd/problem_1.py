for t in range(int(raw_input())):
	s = raw_input()

	ans = s[0]
	for l in s[1:]:
		if ord(l) >= ord(ans[0]):
			ans = l + ans
		else:
			ans = ans + l

	print "Case #{}: {}".format(t+1, ans)