# Marius Damarackas (m.damarackas@gmail.com)
# Google CodeJam, Round 1A 2009, Collecting Cards

import gmpy

def A(k, n):
    return gmpy.comb(n, k) * gmpy.fac(k)

def solve(C, N):
    average = 0
    for m in range(1, 200):
        foo = 0
        for i in range(1, C + 1):
            foo += (-1)**(i + 1) * gmpy.comb(C, i) * A(N, C - i)**m
        p = A(N, C)**m - foo
        bar = 0
        for i in range(1, C + 1):
            bar += (-1)**(i + 1) * gmpy.comb(C, i) * A(N, C - i)**(m - 1)
        p = p - (A(N, C)**(m - 1) - bar) * A(N, C)
        average += (p / A(N, C)**m) * m
    return average

def main():
    file = open("input.in")
    tests = int(file.readline().strip())
    for case in range(1, tests + 1):
        C, N = [int(x) for x in file.readline().split()]
        print("Case #", case, ": ", solve(C, N), sep="")

if __name__ == "__main__":
    main()
