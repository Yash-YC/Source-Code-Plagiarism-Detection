#!/usr/bin/python

import sys

htenf = file('happyseq.txt', 'r')
htenfdata = htenf.readlines()
htenf.close()

htsdata = []
for line in htenfdata:
	htsdata.append(int(line.rstrip('\n').split(' ')[-1]))

del htenfdata

def tobasen(num, base):
	'''Given a number in base 10, return a list given in base.  (No letter representations, just values)'''
	answer = []
	while num > 0:
		answer.append(num % base)
		num /= base
	return answer[::-1]

"""Happy checks that loop were provided based on information from the Wikipedia:
http://en.wikipedia.org/wiki/Happy_number#Happy_numbers_in_other_bases"""

def happycheck3(check):
	if check == "11" or check == "12" or check == "22":
		return False
	return True

def happycheck5(check):
	if check == "20" or check == "23" or check == "31" or check == "33":
		return False
	return True

def happycheck6(check):
	if check == "32" or check == "21" or check == "5" or check == "41" or check == "25" or check == "45" or check == "105" or check == "42" or check == "32":
		return False
	return True

def happycheck7(check):
	if check == "2" or check == "4" or check == "22" or check == "11" or check == "34" or check == "13" or check == "23" or check == "16" or check == "52" or check == "41" or check == "23" or check == "63" or check == "44":
		return False
	return True

def happycheck8(check):
	if check == "4" or check == "20" or check == "5" or check == "31" or check == "12" or check == "32" or check == "15" or check == "24" or check == "64":
		return False
	return True

def happycheck9(check):
	if check == "55" or check == "58" or check == "108" or check == "72" or check == "45" or check == "75" or check == "82":
		return False
	return True

def happycheck10(num):
	if num > 1000000:
		return happycheck10(happyprocess(tobasen(num, 10)))
	else:
		return (num in htsdata)

def happyprocess(nums):
	ans = 0
	for x in nums:
		ans += x*x
	return ans

def happynumber(num, base):
	'''Given a number, determine if it is a happy number in given base'''
	if base == 2 or base == 4:
		return True
	if num == 1:
		return True
	convert = tobasen(num, base)
	check = ''.join(["%d" % k for k in convert])
	if base == 3:
		if happycheck3(check):
			return happynumber(happyprocess(convert), base)
		else:
			return False
	elif base == 5:
		if happycheck5(check):
			return happynumber(happyprocess(convert), base)
		else:
			return False
	elif base == 6:
		if happycheck6(check):
			return happynumber(happyprocess(convert), base)
		else:
			return False
	elif base == 7:
		if happycheck7(check):
			return happynumber(happyprocess(convert), base)
		else:
			return False
	elif base == 8:
		if happycheck8(check):
			return happynumber(happyprocess(convert), base)
		else:
			return False
	elif base == 9:
		if happycheck9(check):
			return happynumber(happyprocess(convert), base)
		else:
			return False
	elif base == 10:
		return happycheck10(num)
	else:
		sys.stderr.write("Happy number base check not implemented above base 10\n")
		sys.exit(1)

def commonnumber(num, bases):
	for base in bases:
		if (not happynumber(num, int(base))):
			return False
	
	return True

if __name__ == "__main__":
	if len(sys.argv) <= 1:
		sys.exit(0)

	f = file(sys.argv[1], 'r')

	lines = f.readlines()
	f.close()
	controldata = lines[0].rstrip('\n')
	del lines[0]

	casen = 1

	for line in lines:
		bases = line.rstrip('\n').split(' ')
		count = 2
		while True:
			if commonnumber(count, bases):
				break
			else:
				count += 1
	
		print "Case #%d: %d" % (casen, count)
		casen += 1
