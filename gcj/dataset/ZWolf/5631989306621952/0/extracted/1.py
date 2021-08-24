import time
import math
import fractions
import numpy as np
from math import *
from fractions import *
from operator import itemgetter, attrgetter

start = time.time()

fname = "A-small-attempt0"

ifile = open(fname + '.in', 'r')
ofile = open(fname + '.out', 'w+')

def lastword(num_case, b):
	l = len(b)
	string = []
	string.append(b[0])
	for j in range(1, l):
		if ord(b[j]) >= ord(string[0]):
			string.insert(0, b[j])
		else:
			string.append(b[j])
	ofile.write("Case #%d: " % (num_case+1))
	for j in range(0, l):
		ofile.write(string[j])
	ofile.write("\n")


############ main #############################	
with ifile:
	[num_case] = [int(x) for x in ifile.readline().split()] 

	for i in range(0, num_case):
		[a] = [str(x) for x in ifile.readline().split()]
		b = list(a)
		lastword(i, b)






end = time.time()
print(end - start)



