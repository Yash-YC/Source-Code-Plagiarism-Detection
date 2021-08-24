from __future__ import with_statement

def is_happy(number, base):
    #print "is_happy(%i, %i)?" % (number, base)
    result = 0
    results = []
    while True:
        while number:
            num = number % base
            #print "%i*%i +" % (num, num),
            result += num**2
            number -= num
            number /= base
        # Check if we have reached a cycle.
        if result in results:
            #print "False"
            return False
        else:
            results.append(result)

        # If not, check to see your result
        if result == 1:
            #print "True"
            return True
        #print "next is %i" % result
        number = result
        result = 0

def find_happy_number(bases):
    number = 2
    while True:
        while True:
            if is_happy(number, bases[0]):
                also_others = True
                for base in bases[1:]:
                    if not is_happy(number, base):
                        also_others = False
                        break
                if also_others:
                    return number
            number += 1

with open("A-small-attempt1.in") as f:
    lines = [l[:-1] for l in f.readlines()]
    for i,line in enumerate(lines[1:]):
        #print "Finding result for %s" % line
        result = find_happy_number([int(x) for x in line.split(" ")])
        print "Case #%i: %i" % (i + 1, result)

