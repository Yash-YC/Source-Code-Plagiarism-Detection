import random

def validate(N,lists):
	for j in range(N,2*N):
		if lists[j]!='zpc':
			for i in range(N):
				if lists[i] != 'zpc':
					if lists[j][i] != lists[i][j-N]:
						return False
	return True
			

def find_list(N,lists):
	result = []
	idx = lists.index('zpc')
	if idx < N:
		for i in range(N):
			result.append(lists[i+N][idx])
	else:
		for i in range(N):
			result.append(lists[i][idx-N])

	return result

def next(lists,k,m):
	if k==m:
		if validate(N,lists):
			return " ".join(find_list(N,lists))
		else:
			return None

	for i in range(k,m+1):
		tmp=lists[k]
		lists[k]=lists[i]
		lists[i]=tmp

		result = next(lists,k+1,m)
		if result != None:
			return result

		tmp=lists[k]
		lists[k]=lists[i]
		lists[i]=tmp

def compute(N,lists):
	mydict = {}
	result = []
	for list in lists:
		for i in list:
			if i in mydict:
				mydict[i] += 1
			else:
				mydict[i] = 1
	for i in mydict:
		if mydict[i]%2 == 1:
			result.append(int(i))
	result.sort()
	result = [str(i) for i in result]
	return " ".join(result)

if __name__ == '__main__':
	input = open('input.txt','r')
	output = open('output.txt','w')

	T = int(input.readline())
	for i in range(1,T+1):
		N = int(input.readline())
		lists = []
		for j in range(2*N-1):
			lists.append(input.readline().split())
		result = compute(N,lists)
		output.write('Case #{}: {}\n'.format(i,result))
	

