def baseconvert(n, base):
    digits = "0123456789abcdefghijklmnopqrstuvwxyz"

    try:
        n = int(n)
        base = int(base)
    except:
        return ""

    if n < 0 or base < 2 or base > 36:
        return ""

    s = ""
    while 1:
        r = n % base
        s = digits[r] + s
        n = n / base
        if n == 0:
            break

    return s


def is_happy(n, base):
    numbers_tried = []
    
    while True:
        n_in_base = baseconvert(str(n), base)
        the_sum = sum([int(i)**2 for i in n_in_base])
        if the_sum == 1:
            return True
        
        if the_sum in numbers_tried:
            return False
        
        numbers_tried.append(n)
        
        n = the_sum

def happy_generator(n, bases):
    for base in bases:
        yield is_happy(n, base)
    
def happy_in_all_bases(n, bases):    
    return all(happy_generator(n, bases))

#import psyco
import sys

def solve_for(bases):
    i = 2
    while not happy_in_all_bases(i, bases):
        i+=1
        #print 'trying', i
        
    return i


def main():
    number_of_cases = int(raw_input())
    for case_number in range(1, number_of_cases+1):
        bases = map(int, raw_input().split())
                
        print 'Case #%d: %d' % (case_number, solve_for(bases))
        
main()