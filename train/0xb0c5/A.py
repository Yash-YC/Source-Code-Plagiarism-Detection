def solve(s):
	r = ''
	f = ''
	for c in s:
		if c >= f:
			f = c
			r = c + r
		else:
			r = r + c 
	return r

n_cases = input()
for i in range(1,n_cases+1):
	s = raw_input()
	print 'Case #%d:' % i,
	print solve(s)