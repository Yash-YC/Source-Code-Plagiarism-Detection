#!/usr/bin/python
fp = open('in.txt', 'rU')
lines = (line.rstrip("\n") for line in fp.xreadlines())
C = int(lines.next())   # number of test cases
base_memos = {}
def is_happy(num, base):
    orig_num = num
    memo = set()
    this_base_memos = base_memos.setdefault(base, {})
    while True:
        memo.add(num)
        remainder = num
        digits = []
        while remainder:
            digits.append(remainder % base)
            remainder /= base
        num = sum(digit * digit for digit in digits)
        if num in memo:
            result = False
            break
        elif num == 1:
            result = True
            break
        elif num in this_base_memos:
            result = this_base_memos[num]
            break
    for n in memo:
        this_base_memos[n] = result
    #print '%d is happy in base %d: %r' % (orig_num, base, result)
    return result
for case_index in range(C):
    bases = [int(x) for x in lines.next().split(' ')]
    num = 2
    while not all(is_happy(num, base) for base in bases):
        num += 1
    print 'Case #%d: %d' % (case_index + 1, num)
