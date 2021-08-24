import time
import math
import fractions
import numpy as np
from math import *
from fractions import *
from operator import itemgetter, attrgetter

start = time.time()

fname = "B-large"

ifile = open(fname + '.in', 'r')
ofile = open(fname + '.out', 'w+')

def rankfile(num_case, array, n):
	b =[0] * 2500
	for j in range(0, 2*n-1):
		for k in range(0, n):
			tmp = array[j][k]-1
			b[tmp] += 1

	ofile.write("Case #%d:" % (num_case+1))
	for j in range(0, 2500):
		if b[j] % 2 != 0:
			ofile.write(" %d" % (j+1))
	ofile.write("\n")


############ main #############################	
with ifile:
	[num_case] = [int(x) for x in ifile.readline().split()] 

	for i in range(0, num_case):
		[n] = [int(x) for x in ifile.readline().split()]
		array = []
		for j in range(0, 2*n-1):
			a = [int(x) for x in ifile.readline().split()]
			array.append(a)
			# for k in range(0, n):
			# 	array.append(a[k])
		rankfile(i, array, n)






end = time.time()
print(end - start)



