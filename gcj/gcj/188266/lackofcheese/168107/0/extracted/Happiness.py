words = []
outFile = open("out.out", "w")
case = 1
def isHappy(num, base):
    return iht(num, base, [num])

def iht(num, base, nums):
    sum = 0
    while num > 0:
        d = num % base
        num /= base
        sum += (d ** 2)
    # print sum
    if sum == 1:
        return True
    elif sum == 0 or sum in nums:
        return False
    else:
        nums.append(sum)
        return iht(sum, base, nums) 

for ind, line in enumerate(open("A-small-attempt0.in","U")):
    if ind == 0:
        continue
    bases = line.split()
    bases = [int(i) for i in bases]
    # print bases
    n = 1
    happy = False
    while not happy:
        n += 1
        happy = True
        for b in bases:
            # print n, b
            if not isHappy(n, b):
                happy = False
                break
    output = "Case #%d: %d\n" % (case, n)
    print output,
    outFile.write(output)
    case += 1
outFile.close()
