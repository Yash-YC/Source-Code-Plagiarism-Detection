#!/usr/bin/python
''' Usage %s
'''
import logging

CurrentDebugLevel=logging.DEBUG

def DivideNum(num, base):
    numList = []
    while num > 0:
        numList.append(num % 10)
        num = int(num / 10)
    return numList

def ToNumByBase(num, base):
    digits = []
    while num >= base:
        digits.append(num % base)
        num = int(num / base)
    digits.append(num)
    return digits

def CheckHappyNum(num, base):
    sumList = []
    sum = 0
    while sum not in sumList:
        sumList.append(sum)
        numList = ToNumByBase(num, base)
        squareList = [x * x for x in numList]
        sum = 0
        for i in squareList: sum += i
        num = sum
        if sum == 1: 
            return True
    return False

def ProcessCase(inFile, caseNum):
    logging.debug('Case %d', caseNum)
    param = inFile.readline().strip().split()
    
    bases = [int(x) for x in param]
    logging.info('Chunk:{}'.format(bases))
    
    num = 2
    while True:
        isAllPassed = True
        for base in bases:
            if not CheckHappyNum(num, base):
                isAllPassed = False 
                break
        if isAllPassed: break
        num += 1 # test the next one
    result = [num]
    
    return result

def OutputResult(outFile, caseNum, result):
    value = result[0]
    outFile.write("Case #{0}: {1}\n".format(caseNum, value))
    logging.debug("Case #{0}: {1}\n".format(caseNum, value))

def ProcessDataFile(fileName):
    inFile = open(fileName, 'r')
    line = inFile.readline()
    lineCount = int(line)
    outFile = open(fileName + '.out.txt', 'w')
    for i in range(1, lineCount + 1):
        result = ProcessCase(inFile, i)
        OutputResult(outFile, i, result)
    outFile.close()

def main():
    logging.basicConfig(level=CurrentDebugLevel, datefmt='%Y.%m.%d %H:%M:%S', format='%(asctime)s %(levelname)-5s %(message)s')
    question = 'A'
    #dataSet = 'small'
    #dataSet = 'large'
    #dataSet = 'test'
    dataSet = 'small-attempt0'
    #dataSet = 'small-practice'
    #dataSet = 'large-practice'

    ProcessDataFile('{0}-{1}.in'.format(question, dataSet))

def main2():
    logging.basicConfig(level=CurrentDebugLevel, datefmt='%Y.%m.%d %H:%M:%S', format='%(asctime)s %(levelname)-5s %(message)s')
    result = [x for x in range(2, 100) if CheckHappyNum(x, 2)]
    logging.debug(result)
    result = [x for x in result if CheckHappyNum(x, 3)]
    logging.debug(result)
    
if __name__ == '__main__': main()