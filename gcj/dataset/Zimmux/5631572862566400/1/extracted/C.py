from collections import deque
import fileinput
stdin = fileinput.input()

def solveCase():
	N = int(next(stdin))
	F = list(map(lambda s:int(s)-1,next(stdin).split()))
	C = [-1]*N
	vis = set()
	for i in range(N):
		p = []
		j = i
		while j not in vis:
			p.append(j)
			vis.add(j)
			j = F[j]
		for d,k in enumerate(p[::-1]):
			if k==j:
				break
		# mark with length of cycle
		if k==j:
			for k in p[::-1]:
				C[k] = d+1
				if k==j:
					break
	M = max(C)

	Frev = [[] for _ in range(N)]
	for i,j in enumerate(F):
		Frev[j].append(i)
	# find distances to 2-cycle
	D = [-1]*N
	T = [-1]*N
	for i in range(N):
		if C[i]==2:
			D[i] = 1
			T[i] = i
	c2 = [i for i in range(N) if C[i]==2]
	q = [(i,i) for i in c2]
	while q:
		i,t = q.pop(0)
		for j in Frev[i]:
			if D[j]==-1 or D[j]>D[i]+1:
				D[j] = D[i]+1
				T[j] = t
				q.append((j,t))
	P = [-1]*N
	for i,d,t in zip(range(N),D,T):
		if P[t]<d:
			P[t] = d
	return max(M,sum(d for d in P if d>=0))


for case in range(int(next(stdin))):
	print("Case #{0}: {1}".format(case+1,solveCase()))