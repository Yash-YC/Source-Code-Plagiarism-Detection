# Marius Damarackas (m.damarackas@gmail.com)
# Google CodeJam, Round 1A 2009, Multi-base happiness

import itertools

def digit_square_sum(num, base):
    total = 0
    while num > 0:
        total += (num % base)**2
        num = num // base
    return total

def is_happy(num, base):
    visited = set()
    while True:
        num = digit_square_sum(num, base)
        if num == 1:
            return True
        elif num in visited:
            return False
        visited.add(num)
    return False

def solve(bases):
    for i in itertools.count(2):
        if all(is_happy(i, b) for b in bases):
            return i

def main():
    file = open("input.in")
    tests = int(file.readline().strip())
    for case in range(1, tests + 1):
        bases = [int(x) for x in file.readline().split()]
        print("Case #", case, ": ", solve(bases), sep="")

if __name__ == "__main__":
    main()
