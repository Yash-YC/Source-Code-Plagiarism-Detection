#!/usr/bin/python

import sys

def line():
    return sys.stdin.readline()[:-1]

def readList():
    return map(eval,line().split())

def neighbors(pos,N,M):
    x,y = pos
    result = []
    if x > 0:
        result.append((x-1,y))
    if y < 2*M-1:
        result.append((x,y+1))
    return result

def timeToGetThere(source,dest,time,S,W,T):
    sx,sy = source
    dx,dy = dest
    lightx = sx / 2
    lighty = sy / 2
    light = (lightx,lighty)
    timeToCross = T[light]
    increment = S[light] + W[light]
    if sx == dx: # Going W-E
        if sy % 2 == 1: # We are in a block
            return 2
        else:
            if W[light] < 1:
                return -1
            timeToCross = timeToCross + S[light]
            alloted = W[light] - 1
            while timeToCross + alloted < time:
                timeToCross = timeToCross + increment
            return max(timeToCross,time) + 1
    else: # Going N-S
        if sx % 2 == 0: # We are in a block
            return 2
        else:
            if S[light] < 1:
                return -1
            alloted = S[light] - 1
            while timeToCross + alloted < time:
                timeToCross = timeToCross + increment
            return max(timeToCross,time) + 1

def processOne(knownTimes,unknownTimes,S,W,T):
    minimum = None
    closest = None
    for x in knownTimes:
        for y in list(unknownTimes):
            time = timeToGetThere(x,y,knownTimes[x],S,W,T)
            if minimum == None or (time != -1 and time < minimum):
                minimum = time
                closest = y
    unknownTimes.remove(closest)
    knownTimes[closest] = minimum

if __name__ == '__main__':
    numberOfCases = eval(line())
    for caseNumber in range(numberOfCases):
        N,M = readList()
        positions = [(i,j) for i in range(2*N) for j in range(2*M)]
        origin = (2*N-1,0)
        destination = (0,2*M-1)
        knownTimes = dict()
        unknownTimes = set(positions)
        unknownTimes.remove(origin)
        knownTimes[origin] = 0
        S = dict()
        W = dict()
        T = dict()
        for i in range(N):
            data = readList()
            for j in range(M):
                S[(i,j)] = data[3*j]
                W[(i,j)] = data[3*j+1]
                T[(i,j)] = data[3*j+2]
        while destination in unknownTimes:
            processOne(knownTimes,unknownTimes,S,W,T)
        print "Case #" + str(caseNumber+1) + ":",knownTimes[destination]
