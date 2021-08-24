#!/usr/bin/python

import math

txt = open("A-large.in", "r")

out = open("a.txt", "w")

dic = {}
case = 0

for k in range(int(txt.readline().strip())):
	for i in txt:
		case = case + 1
		i.strip()
		out.write("Case #"+  str(case) + ": ")
		aoua = i[0]
		ababa = 0

		for j in range(1, len(i)):
			if i[j] >= aoua[0] :
				aoua = i[j] + aoua
			else:
				aoua = aoua + i[j]
		out.write(aoua)
