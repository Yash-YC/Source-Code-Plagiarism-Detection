for t in range(int(raw_input())):
	N = int(raw_input())
	arr = []
	for n in range(2 * N - 1):
		arr += map(int, raw_input().split())

	# count occurrences
	occ = dict()
	for i in arr:
		if i not in occ:
			occ[i] = 1
		else:
			occ[i] += 1

	res = []
	for h, time in occ.items():
		if time % 2 == 1:
			res.append(h)
	res.sort()

	result = str(res)[1:-1].replace(",", "")

	print "Case #{}: {}".format(t+1, result) 