def get_ppl_w_bff(bff):
	res = []
	for i in range(len(rec)):
		if rec[i] == bff:
			res.append(i)
	return res

def add(arr):
	bff = rec[arr[-1]]
	if bff not in arr:
		add(arr + [bff])
	elif bff == arr[-2]:
		ppl_w_bff = get_ppl_w_bff(arr[-1])
		ppl_w_bff2 = get_ppl_w_bff(arr[0])
		ppl = ppl_w_bff + ppl_w_bff2
		for psn in ppl:
			if psn not in arr:
				if psn in ppl_w_bff:
					add(arr + [psn])
				elif psn in ppl_w_bff2:
					add([psn] + arr)
		poss.append(arr)
	elif bff == arr[0]:
		poss.append(arr)


		

for t in range(int(raw_input())):
	N = int(raw_input())
	rec = map(int, raw_input().split())
	rec = [0] + rec
	#print rec
	#print get_ppl_w_bff(3)

	poss = []
	for i in range(1,N+1):
		add([i])

	l = map(len, poss)
	res = max(l)

	print "Case #{}: {}".format(t+1, res)