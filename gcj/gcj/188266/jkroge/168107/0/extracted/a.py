f = open('A-small-attempt0.in', 'r')

N = int(f.readline())

a = dict()

def base10toN(num,n):
	new_num_string=''
	current=num
	while current!=0:
		remainder=current%n
		remainder_string=str(remainder)
		new_num_string=remainder_string+new_num_string
		current=current/n
	return new_num_string

def is_happy(n, b):
	n = base10toN(n, b)
	
	if (n, b) in a:
		return False
	else:
		n_str = str(n)
		sum = 0
		
		for i in range(len(n_str)):
			m = int(n_str[i])
			sum += m*m
		
		a[(n, b)] = sum
		
		if sum == 1:
			return True
		else:
			return is_happy(sum, b)

for i in range(N):
	line = f.readline()
	line = line[0:len(line)]
	bases = line.split(' ')
	
	k = 2
	
	while True:
		a = dict()
		all_happy = True
		
		for j in range(len(bases)):
			if not is_happy(k, int(bases[j])):
				all_happy = False
				break;
		
		if all_happy:
			break;
		else:
			k = k+1
	
	print "Case #" +  str(i+1) + ": " + str(k)