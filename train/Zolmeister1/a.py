# Zolmeister

import sys
from bitarray import bitarray

fout = open(sys.argv[0] + '.out', 'w')

def pp(t, s):
    out = 'Case #{}: {}'.format(t + 1, s)
    print out
    fout.write(out + '\n')



T = int(input())

for t in xrange(T):
    line = raw_input()
    out = ''

    for char in line:
        if out == '':
            out = char
        else:
            if char >= out[0]:
                out = char + out
            else:
                out = out + char

    pp(t, out)



fout.close()
