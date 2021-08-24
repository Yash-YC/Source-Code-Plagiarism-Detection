import sys
sys.setrecursionlimit(1100)

infile = open('A.in', 'r')
outfile = open('A.out', 'w')

def solve(s):
	L = len(s)
	if L <= 1:
		return s
	mrk = 'A'
	pos = -1
	k = 0
	while k < L:
		ch = s[k]
		if ord(ch) >= ord(mrk):
			mrk = ch
			pos = k
		k += 1
	return mrk + solve(s[:pos]) + s[pos+1:]

T = int(infile.readline())

for case_num in range(1, T+1):
	S = infile.readline().strip()
	outfile.write('Case #%d: %s\n' % (case_num, solve(S)))

infile.close()
outfile.close()