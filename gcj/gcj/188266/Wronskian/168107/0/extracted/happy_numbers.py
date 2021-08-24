#!/usr/bin/python2.5

def get_base_representation(n, b):
    if (b == 10): return str(n)
    numstr = []
    while (n >= 1):
        reminder = n % b
        numstr.insert(0, str(reminder))
        n = int(n/b)
    return "".join(numstr)

def compute_happy_number(n, b):
    global happy_number_cycle_tbl
    happy_number_cycle_tbl[n, b] = -1
    sum = 0
    numstr = get_base_representation(n, b)
    digits = map(int, numstr)
    for digit in digits:
        sum += digit*digit
    if (sum == 1):
        happy_number_cycle_tbl[n, b] = 1
        return happy_number_cycle_tbl[n, b]
    elif ((sum, b) not in happy_number_cycle_tbl):
        compute_happy_number(sum, b)
    hn = happy_number_cycle_tbl[sum, b]
    if (hn == -1): return -1
    else:
        happy_number_cycle_tbl[n, b] = hn + 1
        return happy_number_cycle_tbl[n, b]

def is_happy_in_all_bases(n):
    for b in bases:
        if (compute_happy_number(n, b) == -1): 
            return False
    return True

def compute_min_happy_number():
    n = 2
    largest_base = bases[len(bases)-1]
    while (True):
        while (compute_happy_number(n, largest_base) == -1):
            n += 1
        if (is_happy_in_all_bases(n)):
            return n
        else:
            n += 1

T = input()
happy_number_cycle_tbl = {}    

for case in range(T):
    bases = map(int, raw_input().split())
    print('Case #%d: %d') % (case+1, compute_min_happy_number())
