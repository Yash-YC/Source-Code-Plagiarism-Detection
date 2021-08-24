from priodict import priorityDictionary

def getall(i,j):
    ##print i,j,s,w,t
    return (s[i][j],w[i][j],t[i][j])

def getnhd(v):
    i,j=v
    #print v,D[v]
    ret=[]
    #print i,2*N,i+1<2*N,j,2*M
    if i+1<2*N:
        if i%2==1:
            ret.append(((i+1,j),2))
        else:
            cs,cw,ct=getall(i/2,j/2)
            ct=(D[v]-ct)%(cs+cw)
            if ct<cs:
                l=1
            else:
                l=1+(cs+cw-ct)
            ret.append(((i+1,j),l))

    if i>0:
        if i%2==0:
            ret.append(((i-1,j),2))
        else:
            cs,cw,ct=getall(i/2,j/2)
            ct=(D[v]-ct)%(cs+cw)
            if ct<cs:
                l=1
            else:
                l=1+(cs+cw-ct)
            ret.append(((i-1,j),l))

    if j+1<2*M:
        if j%2==1:
            ret.append(((i,j+1),2))
        else:
            cs,cw,ct=getall(i/2,j/2)
            ct=(D[v]-ct)%(cs+cw)
            if ct<cs:
                l=1+(cs-ct)
            else:
                l=1
            ret.append(((i,j+1),l))

    if j>0:
        if j%2==0:
            ret.append(((i,j-1),2))
        else:
            cs,cw,ct=getall(i/2,j/2)
            ct=(D[v]-ct)%(cs+cw)
            if ct<cs:
                l=1+(cs-ct)
            else:
                l=1
            ret.append(((i,j-1),l))
    #print ret
    return ret

for case in range(input()):
    print "Case #"+str(case+1)+":",
    N,M=map(int,raw_input().split())
    s=[[0 for i in xrange(M)] for j in xrange(N)]
    w=[[0 for i in xrange(M)] for j in xrange(N)]
    t=[[0 for i in xrange(M)] for j in xrange(N)]
    for i in xrange(N):
        inp=map(int,raw_input().split())
        for j in xrange(M):
            s[i][j]=inp[3*j]
            w[i][j]=inp[3*j+1]
            t[i][j]=inp[3*j+2]%(s[i][j]+w[i][j])
    s.reverse()
    w.reverse()
    t.reverse()
    start=(0,0)
    end=(2*N-1,2*M-1)
    D = {}	# dictionary of final distances
    P = {}	# dictionary of predecessors
    Q = priorityDictionary()   # est.dist. of non-final vert.
    Q[start] = 0

    for v in Q:
            D[v] = Q[v]
            if v == end: break

            for u,l in getnhd(v):
                    ##print l,u
                    vuLength = D[v] + l
                    if u in D:
                            if vuLength < D[u]:
                                    raise ValueError, \
"Dijkstra: found better path to already-final vertex"
                    elif u not in Q or vuLength < Q[u]:
                            Q[u] = vuLength
                            P[u] = v
    print D[end]
