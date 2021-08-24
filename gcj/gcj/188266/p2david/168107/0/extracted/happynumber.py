#file_name = 'happynumber-example'
file_name = 'A-small-attempt1'
input = open(file_name + '.in', 'r')
number_of_test_cases = int(input.readline().strip())
print ('%s' % ( number_of_test_cases))
test_cases = []
for i in xrange(number_of_test_cases):
	bases = [int(n) for n  in input.readline().split()]
	test_cases.append(bases)
#	print bases
input.close()

def to_base(n, b):
	digits = []
	while n > 0:
		digits.insert(0, n%b)
		n //=b
	return digits
def do_it(digits, b, level):
	result = 0
	if level > 30:
		return False
	for digit in digits:
		result+=digit * digit
	if result == 1:
		return True
	else:
		return do_it(to_base(result,b), b, level + 1)	


output = open(file_name +'.out.txt', 'w')
for t in range(0, len(test_cases)):
	bases = test_cases[t]
	for i in range(2, 500000):
		result = True
		for b in bases:
#			print " i %d:base %d : result: %s" % (i,b, to_base(i,b))
			if do_it(to_base(i,b), b, 0):
				continue
			else:
				result = False 
				break 
		if result:
			str_fmt = "Case #%d: %d\n" % (t+1, i)
			print str_fmt
			output.write(str_fmt)
			break

output.close()
