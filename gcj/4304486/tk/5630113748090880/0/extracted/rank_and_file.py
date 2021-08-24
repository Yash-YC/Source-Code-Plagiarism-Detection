import sys

# WARNING: Assumes all input is squeaky clean.

def main():
	T = int(sys.stdin.readline())

	for case_num in range(1,T+1):
		N = int(sys.stdin.readline())

		lists = []
		for i in range(2*N-1):
			lists.append([int(c) for c in sys.stdin.readline().strip().split(' ')])

		lists.sort()

		rows = [lists[0]]
		cols = []
		for l in lists[1:]:
			if comes_after(rows[-1], l):
			 	rows.append(l)
			elif len(cols) > 0 and comes_after(cols[-1], l):
			 	cols.append(l)
		 	else:
			 	cols.append(l)
		
		longer = rows
		shorter = cols
		if len(longer) < len(shorter):
			longer, shorter = shorter, longer

		n = 0
		for i in range(N):
			if i == len(shorter):
				n = N-1
			elif (longer[0][i] != shorter[i][0]):
				n = i
				break

		result = []
		for i in range(N):
			result.append(longer[i][n])

		print("Case #{0}: {1}".format(case_num, ' '.join([str(i) for i in result])))

def is_clashing(lista, listb):
	for i,elem in enumerate(lista):
		if not elem < listb[i]:
			return True
	return False

def comes_after(lista, listb):
	for i,lista_elem in enumerate(lista):
		if not lista_elem < listb[i]:
			return False
	return True

if __name__ == "__main__":
	main()