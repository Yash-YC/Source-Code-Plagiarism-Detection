memoDict = {}
import math

inFile = open("../A-small.in", "r")
outFile = open("../A-sol.txt", "w")

def isHappy(base, num, tries):
    if memoDict.has_key((base, num)):
        return memoDict[(base, num)]
    #outFile.write("Trying num: " + str(num) + " in base " + str(base) + "\n")
    if base == 3 and num == 5:
        pass
    tries.append(num)
    digitList = []
    rawLog = math.log(float(num), float(base))
    numDigits = int(rawLog + 1)
    for i in range(numDigits):
        digitList.append((num / int(math.pow(float(base), float(i)))) % base)
    
    if sum(digitList) == 1:
        memoDict[(base, num)] = True
        return True
    """
    if len(digitList) == 1:
        memoDict[(base, num)] = False
        return False
    """
    
    newNum = sum([x * x for x in digitList])
    if newNum in tries:
        memoDict[(base, num)] = False
        return False
    
    if newNum == 0:
        memoDict[(base, num)] = False
        return False
    return isHappy(base, newNum, tries)
    



numTests = int(inFile.readline().strip())

for i in range(numTests):
    baseList = map(int, inFile.readline().strip().split(" "))
    lowNum = 2
    while True:
        if lowNum == 91:
            pass
        allHappy = True
        for base in baseList:
            allHappy = allHappy and isHappy(base, lowNum, [])
            if not allHappy:
                lowNum = lowNum + 1
                break
        if allHappy:
            break
    
    outFile.write("Case #" + str(i + 1) + ": " + str(lowNum) + "\n")