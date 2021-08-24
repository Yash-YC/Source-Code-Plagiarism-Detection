#!/usr/bin/env python3

from sys import stdin, stdout, stderr

def is_happy(n, b):
    seen = set()
    m = 0
    while n not in seen:
        seen.add(n)
        m = 0
        while n > 0:
            m += (n % b) ** 2
            n //= b
        n = m
        if n == 1:
            return True
    return False

def solve_case(case):
    bases = case
    n = 2
    while True:
        happy = True
        for b in bases:
            happy = happy and is_happy(n, b)
        if happy:
            return n
        n += 1
            

def read_case():
    return list(map(int, input().split()))

def print_case(i, ans):
    s = "Case #%d: %s" % (i, ans)
    print(s)

def main():
    for i in range(1, int(input()) + 1):
        print_case(i, solve_case(read_case()))

if __name__ == "__main__":
    main()

