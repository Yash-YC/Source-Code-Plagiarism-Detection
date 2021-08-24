import sys

def find(node, link, n, linkedNode):
	q = [(node, 0)]
	head, ret = 0, 0
	checkNode = [0] * n
	while (head < len(q)):
		curr = q[head][0]
		currDis = q[head][1]
		ret = max(ret, currDis)
		checkNode[curr] = 1
		head += 1
		for i in link[curr]:
			if (checkNode[i] == 0 and i != linkedNode):
				q.append((i, currDis + 1))
	return ret

def solve():
	n = int(raw_input())
	edge = [int(x) - 1 for x in raw_input().split(" ")]
	link = [[] for i in range(n)]
	for i in range(n):
		link[edge[i]].append(i)
	
	search = [0] * n
	longest = 0

	for i in range(n):
		if (search[i] == 0):
			dis = [0] * n
			curr, count = i, 0
			while (search[curr] == 0):
				search[curr] = 1
				count += 1
				dis[curr] = count
				curr = edge[curr]
			if (dis[curr] > 0):
				longest = max(longest, count - dis[curr] + 1)

	superNode = 0
	check = [0] * n
	for i in range(n):
		if (check[i] == 0):
			check[i] = 1
			if (edge[edge[i]] == i):	# super node
				check[edge[i]] = 1
				superNode += find(i, link, n, edge[i])
				superNode += find(edge[i], link, n, i)
				superNode += 2

	ret = max(longest, superNode)
	return ret

t = int(raw_input())
for i in range(t):
    print "Case #{}: {}".format(i + 1, solve())
