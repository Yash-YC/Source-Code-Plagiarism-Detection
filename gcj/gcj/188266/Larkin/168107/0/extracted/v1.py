


def tobase(b,n,result=''):
    if n == 0:
        if result:
            return result
        else:
            return '0'
    else:
        return tobase(b,n/b,str(n%b)+result)

		

def generateNext(aString, base):
	result = 0
	for character in str(tobase(base, aString)):
		result += int(character) * int(character)
		
	return result

def findHappy(input, base):
	# first convert to a string of proper base.
	
	num_str = str(tobase(base, input))
	results = []
	#print results
	#results.append(input)
	result = input
	while result not in results[:-1] and result != 1:
		result = generateNext(result, base)
		results.append(result)
		#print results
	
	return result
	


#input = '2 3 7'

def solveCase(inputList):
	bases = []
	for baseString in inputList.split():
		bases.append(int(baseString))
	
	solved = 0
	counter = 2
	while solved == 0:
		for base in bases:
			if findHappy(counter, base) != 1:
				counter += 1
				break
		else:
			solved = 1
			
	return counter
			
				
filename = 'A-small-attempt'
input = []
with open(filename + '.in') as f:
	for line in f:
		input.append(line)
		
input[0:1] = []

output = open(filename +'.out', "w")

caseNo = 1
for case in input:
	toPrint = 'Case #{0}: {1}'.format(caseNo, solveCase(case))
	output.write(toPrint + '\n')
	print toPrint
	
	caseNo += 1

output.close()

				
#solveCase('9 10')
				
	
	