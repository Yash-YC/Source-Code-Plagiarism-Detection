from sets import *

inName='A-small-attempt0.in.txt'
outName='out.txt'


def ToBase( num=1, base=2 ):
	newNum=""
	i = num
	while(i>0):
		newNum = str(i%base) + newNum
		i = i/base
	return newNum
	

def IsHappy( numString="", base=2):
		curNum = numString
		periodSet=set([])

		while( int(curNum) != 1 ):
			length = len( curNum )
			sum = 0
			for i in xrange(length):
				sum += int(curNum[i])**2
			curNum = ToBase(sum,base)
			
			if( curNum in periodSet ):
				return False
			else:
				periodSet.add(curNum)
			
		return True		
	

def SmallestHappy( baseList=[] ):
	smallest=2
	found=False
	while(found == False ):
		found=True
		for i in baseList:
			if( IsHappy(ToBase(smallest,i),i) == False ):
				found=False
				smallest += 1
				break
	return smallest
		
	

caseList=[]

inFile = open(inName,'r')
numCases = map(int,inFile.readline().split())[0]
for i in xrange(numCases):
		baseList=map(int,inFile.readline().split())
		caseList.append(baseList)			
inFile.close()


outFile = open(outName,'w')
for i in xrange(0,len(caseList)):
	outFile.write( "Case #" + str((i+1)) + ": " + str(SmallestHappy( caseList[i] )) + "\n" )
outFile.close()

#print ToBase(3,2)	
#print ToBase(3,3)
#print IsHappy(ToBase(3,2))
#print IsHappy(ToBase(3,3))