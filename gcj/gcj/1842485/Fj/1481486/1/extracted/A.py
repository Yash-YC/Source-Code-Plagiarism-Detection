import pdb
import sys
import re
import time
from collections import namedtuple
from itertools import *
from copy import copy, deepcopy

taskname = 'A'
input = None

def readstr():
    return next(input).strip()

def readintlist():
    lst = map(int, readstr().split())
    return lst

def readint():
    lst = readintlist()
    assert len(lst) == 1
    return lst[0]

def solvecase():
    vine_cnt = readint()
    vines = [tuple(readintlist()) for _ in xrange(vine_cnt)]
    target_distance = readint()
    assert len(vines) == vine_cnt
    assert all(len(vine) == 2 for vine in vines)
    vines.sort()
    best_lengths = [0 for _ in xrange(len(vines))]
    best_lengths[0] = vines[0][0]
    for current_idx, (current_pos, _) in enumerate(vines):
#        print best_lengths
        length = best_lengths[current_idx]
        if not length:
            continue
        if current_pos + length >= target_distance:
            return 'YES'
        for next_idx in xrange(current_idx + 1, len(vines)):
            next_pos, next_length = vines[next_idx]
            distance = next_pos - current_pos
#            print distance
            if distance > length:
                break # too far to reach
            real_next_length = min(next_length, distance)
            if best_lengths[next_idx] < real_next_length:
                best_lengths[next_idx] = real_next_length
    return 'NO'

def solve(suffix):
    global input
    tstart = time.clock()
    input = open(taskname + '-' + suffix + '.in', 'r')
    output = open(taskname + '-' + suffix + '.out', 'w')
    casecount = readint()
    
    for case in range(1, casecount + 1):
        s = solvecase()
        s = "Case #%d: %s" % (case, str(s)) 
        print >>output, s
        print s 
        
    input.close()
    output.close()
    print '%s solved in %.3f' % (suffix, time.clock() - tstart)
            
if __name__ == '__main__':
    solve('small')
    solve('large')
