import time
import math
import fractions
import numpy as np
from math import *
from fractions import *
from operator import itemgetter, attrgetter

start = time.time()

fname = "C-small-attempt0"

ifile = open(fname + '.in', 'r')
ofile = open(fname + '.out', 'w+')

def bff(num_case, n, array):
	max_num = 0
	tmp_array = [1] * (2*n)
	change = 1
	j = 0
	while tmp_array != [0]*(2*n) and change == 1:
		change = 0
		# if tmp_array[2*j] > 0 or tmp_array[2*j+1] > 0:
		# 	if tmp_array[(array[j]-1)*2] > 0 or tmp_array[(array[j]-1)+1] > 0:
		# 		max_num += 1
		if tmp_array[2*j] > 0 and tmp_array[2*j+1] > 0:
			if tmp_array[(array[j] - 1) * 2 + 1 ] > 0:
				tmp_array[2 * j] -= 1
				tmp_array[(array[j] - 1) * 2 + 1] -= 1
				max_num += 1
				change = 1
				j = (array[j] - 1)
			elif tmp_array[(array[j]-1)*2] > 0:
				tmp_array[2 * j+1] -= 1
				tmp_array[(array[j] - 1) * 2] -= 1
				max_num += 1
				change = 1
				j = (array[j] - 1)
		elif tmp_array[2*j] > 0:
			if tmp_array[(array[j] - 1) * 2 + 1] > 0:
				tmp_array[(array[j] - 1) * 2 + 1] -= 1
				tmp_array[2 * j] -= 1
			max_num += 1
			change = 1
			j = (array[j] - 1)
		elif tmp_array[2*j+1] > 0:
			if tmp_array[(array[j]-1)*2] > 0:
				tmp_array[(array[j] - 1) * 2] -= 1
				tmp_array[2 * j + 1] -= 1
			max_num += 1
			change = 1
			j = (array[j]-1)

		if change == 0:
			for k in range(0, n):
				if ((tmp_array[2*k] > 0) or (tmp_array[2*k+1] > 0)) \
						and bool(tmp_array[(array[k] - 1) * 2 + 1] > 0) != bool(tmp_array[(array[k] - 1) * 2] > 0):
					change = 1
					j = k
					break

	ofile.write("Case #%d: %d\n" % (num_case+1, max_num))


############ main #############################	
with ifile:
	[num_case] = [int(x) for x in ifile.readline().split()] 

	for i in range(0, num_case):
		[n] = [int(x) for x in ifile.readline().split()]
		array = [int(x) for x in ifile.readline().split()]
		# array.insert(0, 0)
		bff(i, n, array)


end = time.time()
print(end - start)



