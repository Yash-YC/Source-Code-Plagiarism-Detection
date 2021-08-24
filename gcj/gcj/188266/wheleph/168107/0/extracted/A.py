INPUT_FILE = 'inputs/A-small-attempt0.in'
OUTPUT_FILE = 'outputs/A-small-attempt0.out'

f_in = open(INPUT_FILE, 'r')
f_out = open(OUTPUT_FILE, 'w+')

def expandNumber(n, base):
    retVal = []
    while(n > 0):
        retVal.append(n % base)
        n = int(n / base)
    retVal.reverse();
    return retVal

def isHappy(n, base):
    number = expandNumber(n, base)
    prevValues = []
    happy = False
    while(True):
        sum = 0
        for d in number:
            sum += d * d
            
        if (sum == 1):
            happy = True
            break
            
        number = expandNumber(sum, base)
        
        if (number in prevValues):
            break;
        
        prevValues.append(number)
        
    return happy

T = int(f_in.readline().strip())
for i in range(T):
    bases = [int(j) for j in f_in.readline().split()]
#    print(bases)
    currentNumber = 2
    while(True):
        happy = True
        for base in bases:
            if (not isHappy(currentNumber, base)):
                happy = False;
                break;
        
        if (happy):
            f_out.write("Case #" + str(i + 1) + ": " + str(currentNumber) + "\n")
            break;
        
        currentNumber = currentNumber + 1

f_in.close()
f_out.close()