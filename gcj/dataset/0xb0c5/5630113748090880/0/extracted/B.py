
def solve(l):
	counts = {}
	for note in l:
		for soldier in note:
			if not soldier in counts:
				counts[soldier] = 1
			else:
				counts[soldier] += 1
	missing = []
	for soldier in counts:
		if counts[soldier] % 2:
			missing.append(soldier)

	return ' '.join(map(str,sorted(missing)))


n_cases = input()
for i in range(1,n_cases+1):
	N = input()
	l = [map(int,raw_input().split(' ')) for _ in range(2*N-1)]
	print 'Case #%d:' % i,
	print solve(l)