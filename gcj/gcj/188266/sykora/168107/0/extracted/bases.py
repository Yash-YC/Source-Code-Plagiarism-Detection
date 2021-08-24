from skynet.math.numbers import digits
from skynet.decorators import memoize
from itertools import count

def to_base(n, b) :
    s = ''
    while n :
        n, mod = divmod(n, b)
        s = str(mod) + s

    return int(s)

@memoize
def square_and_add(n, b) :
    d = sum(i**2 for i in digits(n))
    return to_base(d, b)

def is_happy(s, b) :
    chain = [s]
    while s != 1 :
        s = square_and_add(s, b)
        if s in chain :
            return False
        chain.append(s)

    return True

bases = (9, 10)

def smallest(bases) :
    for i in count(2) :
        if all(is_happy(to_base(i, b), b) for b in bases) :
            return i

if __name__ == '__main__' :
    with open('A-small-attempt0.in') as file :
        t = int(file.readline())
        for i in range(t) :
            bases = [int(i) for i in file.readline().split()]
            print("Case #{}: {}".format(i + 1, smallest(bases)))
