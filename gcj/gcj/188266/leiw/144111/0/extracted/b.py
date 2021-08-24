import sys

f = sys.stdin

T = int(f.readline())
for T in range(1, T+1):
	N, M = [int(s) for s in f.readline().split()]
	dp = [[0 for _ in range(2*M)] for _ in range(2*N)]

	light = []
	for n in range(N):
		light.append([])
		cl = []
		for i in [int(s) for s in f.readline().split()]:
			cl.append(i)
			if len(cl) >= 3:
				light[n].append(cl)
				cl = []

	rn = range(2*N)
	rn.reverse()
	rm = range(2*M)

	for j in range(1, 2*M):
		i = 2*N - 1
		if j%2:
			b = 2
		else:
			b = (light[i/2][j/2][0] - (light[i/2][j/2][2])%(light[i/2][j/2][0] + light[i/2][j/2][1]))
			if b < 0:
				b = 0
			b += 1
		dp[i][j] = dp[i][j-1] + b
	for i in rn[1:]:
		j = 0
		if (2*N-i)%2:
			a = 2
		else:
			a = (light[i/2][j/2][0] + light[i/2][j/2][1] - ((light[i/2][j/2][2] + dp[i+1][j])%(light[i/2][j/2][0] + light[i/2][j/2][1])))
			if a > light[i/2][j/2][1]:
				a = 0
			a += 1
		dp[i][j] = dp[i+1][j] + a
	
	for i in rn[1:]:
		for j in rm[1:]:
			if j%2 and not ((2*N-i)%2):
				a = (light[i/2][j/2][0] + light[i/2][j/2][1] - ((light[i/2][j/2][2] + dp[i+1][j])%(light[i/2][j/2][0] + light[i/2][j/2][1])))
				if a > light[i/2][j/2][1]:
					a = 0
				a += 1
				b = (light[i/2][j/2][0] - (light[i/2][j/2][2] + dp[i+1][j])%(light[i/2][j/2][0] + light[i/2][j/2][1]))
				if b < 0:
					b = 0
				b += 1
				if dp[i+1][j] + a > dp[i][j-1] + b:
					dp[i][j] = dp[i][j-1] + b
				else:
					dp[i][j] = dp[i+1][j] + a
			elif j%2 and (2*N-i)%2:
				a = 2
				b = (light[i/2][j/2][0] - (light[i/2][j/2][2] + dp[i+1][j])%(light[i/2][j/2][0] + light[i/2][j/2][1]))
				if b < 0:
					b = 0
				b += 1
				if dp[i+1][j] + a > dp[i][j-1] + b:
					dp[i][j] = dp[i][j-1] + b
				else:
					dp[i][j] = dp[i+1][j] + a
			elif not(j%2) and not ((2*N-i)%2):
				a = (light[i/2][j/2][0] + light[i/2][j/2][1] - ((light[i/2][j/2][2] + dp[i+1][j])%(light[i/2][j/2][0] + light[i/2][j/2][1])))
				if a > light[i/2][j/2][1]:
					a = 0
				a += 1
				b = 2
				if dp[i+1][j] + a > dp[i][j-1] + b:
					dp[i][j] = dp[i][j-1] + b
				else:
					dp[i][j] = dp[i+1][j] + a
			else:
				a = 2
				b = 2
				if dp[i+1][j] + a > dp[i][j-1] + b:
					dp[i][j] = dp[i][j-1] + b
				else:
					dp[i][j] = dp[i+1][j] + a

	print "Case #%s: %s" % (T, dp[0][2*M-1]+1)

