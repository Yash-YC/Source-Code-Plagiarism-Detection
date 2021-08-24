import sys
import time

"""
2016 Problem A. The Last Word
"""

def rec( S, one, i, stop_i ):
    if i >= stop_i:
        return one
    return max(
        rec( S, one + S[i], i + 1, stop_i ),
        rec( S, S[i] + one, i + 1, stop_i ) )


def calc( S ):
    return rec( S, S[0], 1, len(S) )


T = int( raw_input() )
xs = []
for i in xrange( T ):
    xs.append( raw_input() )


#----------------------------
start = time.clock()

n = 1
for s in xs:
    r = calc( s )
    print( "Case #{0}: {1}".format( n, r ) )
    n += 1

#end = time.clock()
#print end - start
sys.exit(0)
