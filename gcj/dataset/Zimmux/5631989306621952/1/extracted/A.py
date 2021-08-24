from collections import deque
import fileinput
stdin = fileinput.input()

def solveCase():
	S = next(stdin)[:-1]
	W = [S[0]]
	for s in S[1:]:
		if s>=W[0]:
			W = [s]+W
		else:
			W.append(s)
	return "".join(W)


for case in range(int(next(stdin))):
	print("Case #{0}: {1}".format(case+1,solveCase()))