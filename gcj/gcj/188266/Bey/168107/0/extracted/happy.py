#!/usr/bin/env python
import sys
from myMod import *
FI=open(sys.argv[1],'r')
def readInts():
	return ([int(x) for x in FI.readline().rstrip().split()])



NCases = int(FI.readline())
for nc in range(NCases):
	line = readInts()
	#print "bases: ", line
	NBases = len(line)
	j=NBases-1
	base = line[j]
	FoundAll = 0
	NumNow=2
	while(not FoundAll):
		#print "on NumNow=",NumNow
		# try NumNow 
		if CheckInBase(NumNow,base):
			if j==0:
				FoundAll=True
			else:
				j=j-1;base=line[j];
		else:
			if (NBases-1)==j:
				NumNow=NumNow+1
			else:
				j=NBases-1
				base=line[-1]
				NumNow=NumNow+1
	print "Case #"+str(nc+1)+":",NumNow

















FI.close()

