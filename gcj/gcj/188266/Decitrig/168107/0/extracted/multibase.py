import sys
from math import log

def convert_base(num, radix=10):
    max_exp = log(num)/log(radix)
    places = [radix**e for e in range(int(max_exp)+1)]
    places.reverse()
    new = []
    curr = num;
    for p in places:
        q,r = curr // p, curr % p
        new.append(q)
        curr = r
    return new

def list_to_dec(num, radix):
    sum = 0
    for e in range(len(num)):
        sum += (radix**e) * num[e]
    return sum

def num_to_list(n):
    nstring = str(n)
    return [int(x) for x in nstring]

def get_squaresum(digitlist, base):
    sum = 0
    for i in digitlist:
        n = int(i)
        sum += n*n
    return sum

def is_happy(num, base):
    tried_already = []
    numstring = convert_base(num, base)
    sqsum = -1
    while not sqsum == 1:
        sqsum  = get_squaresum(numstring, base)
        numstring = convert_base(sqsum, base)
        if numstring in tried_already:
            return False
        tried_already.append(numstring)
    return True

def test_bases(num, base_list):
    result = [is_happy(num, base) for base in base_list]
    while False in result:
        num +=1
        result = [is_happy(num, base) for base in base_list]
    return num

if __name__ == '__main__':
    num_cases = int(sys.stdin.readline())
    cases = [n+1 for n in range(num_cases)]
    for case in cases:
        bases = sys.stdin.readline().split()
        bases = [int(x) for x in bases]
        print "Case #{0}: {1}".format(case, test_bases(2, bases))
