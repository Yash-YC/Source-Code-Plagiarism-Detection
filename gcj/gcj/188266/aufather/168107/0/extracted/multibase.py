
import sys

happyList = {2:([], {}),
             3:([], {}),
             4:([], {}),
             5:([], {}),
             6:([], {}),
             7:([], {}),
             8:([], {}),
             9:([], {}),
             10:([], {})}

superSet = set(range(2, 100000))

def get_digits(num, base):
    digits = []
    while num:
        digits.append(num % base)
        num /= base
    return digits

def sum_of_squares(num, base):
    sum = 0
    digits = get_digits(num, base)
    for digit in digits:
        sum += digit * digit
    return sum

def is_happy(num, base):
    sum = num
    sumList = []
    while True:
        sum = sum_of_squares(sum, base)
        if sum == 1:
            return True
        sumSet = set(sumList)
        if sum in sumSet:
            return False
        sumList.append(sum)

def get_next_happy(num, base):
    while True:
        num += 1
        if is_happy(num, base):
            return num

def process(outFile, numTestCase, bases):
    while True:
        curSet = None
        for base in bases:
            if not len(happyList[base][0]): curNum = 1
            else: curNum = happyList[base][0][-1]
            happyList[base][0].append(get_next_happy(curNum, base))
            if curSet is None: curSet = set(happyList[base][0])
            else: curSet &= set(happyList[base][0])
        if len(curSet):
            answer = 2
            while True:
                if answer in curSet:
                    print >> outFile, 'Case #' + str(numTestCase) + ': ' + str(answer)
                    return
                answer += 1

def testcase(fileName):
    bases = []
    T = None
    outFile = open("output.txt", "w")
    for numTestCase, line in enumerate(open(fileName)):
        if T is None:
            T = int(line)
            continue;
        bases = map(int, line.split())
        process(outFile, numTestCase, bases)

if __name__=='__main__':
    testcase(sys.argv[1])
