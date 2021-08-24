'''
Google Code Jam 2009
Round 1A
A.

@author: Samuel Spiza
'''

#fileName = "A-practice.in"
fileName = "A-small-attempt0.in"
#fileName = "A-large.in"
file = open(fileName, "r")

def numberBase(number, base):
    arr = []
    while base <= number:
        arr.append(number%base)
        number = number//base
    arr.append(number)
    return arr

def findEnd(number, base, arr):
    if number > 1000000:
        print "hallo"
        return 2
    k = sum([j**2 for j in numberBase(number, base)])
    if k in arr:
        return k
    else:
        arr.append(k)
        return findEnd(k, base, arr)
    
def findInt(arr):
    i = 2
    while True:
        j = 0
        while j < len(arr) and 1 == findEnd(i, arr[j], []):
            j = j + 1
        if j == len(arr):
            return i
        i = i + 1

i = 0
string = ""

for line in file:
    if i == 0:
        T = line.strip()
    else:
        string = string + "Case #" + str(i) + ": " + str(findInt([int(x) for x in line.strip().split()])) + "\n"
    i = i + 1

file.close()





    
file = open(fileName.rsplit(".", 1)[0] + ".out", "w")
file.write(string.strip())
file.close()
