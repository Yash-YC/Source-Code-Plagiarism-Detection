import numconv

def squared_sum(num, base):
	sum = 0
	for i in num:
		sum = sum + int(i) * int(i) 
	return numconv.int2str(sum, radix=base)

def is_happy_num(num, base):
	cur_number = numconv.int2str(num, radix=base)
	passed_numbers = [ cur_number ]
	while True:
		cur_number = squared_sum(cur_number, base)
		if cur_number == "1":
			return True
		elif cur_number == "0":
			break
		elif cur_number in passed_numbers:
			break
		passed_numbers.append(cur_number)
	return False
	

if __name__ == "__main__":
	FILENAME = "A-small-attempt0.in"
	lines = file(FILENAME).read().splitlines()[1:]
	for i, line in enumerate(lines):
		bases = map(int, line.split())
		
		cur_number = 2
		is_happy = True

		while True:
			for base in bases:
				if not is_happy_num(cur_number, base):
					is_happy = False
					break
			if is_happy:
				break
		  	else:
				cur_number = cur_number + 1
				is_happy = True

		print "Case #%d: %s" % (i+1, cur_number)
