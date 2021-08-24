import sys

# WARNING: Assumes all input is squeaky clean.

def main():
	T = int(sys.stdin.readline())

	for case_num in range(1,T+1):
		S = sys.stdin.readline()

		last_word_list = [S[0]]
		for c in S[1:]:
			if ord(c) >= ord(last_word_list[0]):
				# prepend if c is a larger letter than the current first
				last_word_list.insert(0, c)
			else:
				last_word_list.append(c)

		print("Case #{0}: {1}".format(case_num, ''.join(last_word_list))),

if __name__ == "__main__":
	main()