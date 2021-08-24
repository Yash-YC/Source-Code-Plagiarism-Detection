#!/usr/bin/env python 

import sys 

def getNumberBase(number,base):
	""" return the number in particular base """	
	
	newnumber = number;
	total = 0
	
	while(newnumber):
		#print base 
		rem = newnumber % base
		newnumber /= base
		total += rem * rem
	
	return(total)



def isHappy(number,base):
	retVal = number
	oldretVal = number 

	list = []
	flag = 1
	#while(retVal > base):
	while(1):
		if(retVal not in list):
			list.append(retVal)
			
		retVal = getNumberBase(retVal,base)
		#print number, base, retVal 
		
		if(retVal == 1 or retVal == base):
			return(1)

		if(retVal in list):
			return(0)	

	#if(flag == 0):
	#	return(0)
	#if(retVal == base or retVal == 1):
	#	return(1)
	#return(0)	


def process():
	""" xxx """
	
	#Bases = list(map(int,sys.stdin().split(' ')))
	Bases = list(map(int, sys.stdin.readline().strip().split(" ")))

	#print Bases

	start = 2;
	

	#isHappy(7,3)

	#print isHappy(91,10)
	#print isHappy(91,9)
	#return 0
	while(1):
		flag = 1
		for i in range(len(Bases)):
			if(not isHappy(start,Bases[i])):
				flag = 0
				break
		#break		
		#print flag 		
		#break
		if(flag == 1):
			return(start)
		start += 1
			
				
			
	





if(__name__=="__main__"):
	nTestCases = int(sys.stdin.readline().strip())
	#print nTestCases

	for i in range(1,nTestCases+1):
		string = "Case #" + str(i) + ": "
		print string + str(process())

