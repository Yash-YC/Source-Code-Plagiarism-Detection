
happy = {}
not_happy = {}

def convert2(n, base):
	res = ''
	while (n):
		res = str(n % base) + res
		n /= base
	return res

def check_happy(n, base):
	if (n, base) in happy:
		return True
	elif (n, base) in not_happy:
		if not_happy[(n, base)]:
			return False

	not_happy[(n, base)] = True
	bin = convert2(n, base)
	#print n, base
	sum = 0
	for d in str(bin):
		sum += int(d) * int(d)

	if sum == 1 or check_happy(sum, base):
		#happy[(n, base)] = True
		not_happy[(n, base)] = False
		return True
	else:
		return False

def solve(x, limit):
	#print 'solve', x, limit
	for i in xrange(2, limit+1):
		is_happy = check_happy(i, x)
		#print '%d is happy = %s' % (i, is_happy)
		#print happy

def solve2(bases):
	#print 'solve2', bases

	limit = 10000
	for j in bases:
		solve(j, limit)

	answer = 2
	while True:
		#print answer
		for j in bases:
			if not check_happy(answer, j):
				break
		else:
			return answer
		#print answer
		answer += 1
		if answer > limit:
			limit += limit


def main():
	for i in xrange(2, 11):
		happy[(1, i)] = True
	T = int(raw_input())
	for i in xrange(T):
		print 'Case #%s: %s' % (i+1, solve2(map(int, raw_input().split(' '))))	

if __name__ == '__main__':
	main()