import sys,re
import string
f=open( sys.argv[1])
n=int(f.readline().strip())
for i in xrange(n):
    (N,M) = f.readline().strip().split()
    N=int(N)
    M=int(M)
    lights=[]
    for j in xrange(N):
        ll = f.readline().strip().split()
        ll = map(int, ll)
        lights.append(ll)

    qa=[N*2-1]
    qb=[M*2-1]
    dp=[]
    for j in xrange(N*2):
        dp.append([-1] * (M*2))
    dp[N*2-1][M*2-1]=0
    def update(na, nb, nt):
        if dp[na][nb] == -1 or nt < dp[na][nb]:
            dp[na][nb] = nt
            qa.append(na)
            qb.append(nb)
#/            print "%d %d %d" % (na,nb,nt)
    def crosstime(t, dir, n, m):
        t0=lights[n][3*m+2]
        s0=lights[n][3*m]
        w0=lights[n][3*m+1]
        t0 = (t0 % (s0+w0))-s0-w0
        td =(t-t0)%(s0+w0)
       #/ print "int %d %d %d %d dir%d" % (t0, td, s0, w0, dir)
        if (td < s0):
            if dir==0:
                return 1
            else:
                return s0-t+1
        else:
            if dir==1:
                return 1
            else:
                return s0+w0-t+1

    while (len(qa)):
        a=qa.pop(0)
        b=qb.pop(0)
        #n
        na=-1
        nb=-1
        nt= dp[a][b]

        if a!=0:
            na = a-1
            nb = b
            if a%2 == 0:
                nt= nt+2
            else:
                nt = nt + crosstime(nt, 0, a/2, b/2)
            update(na,nb,nt)
        if a!=N*2-1:
            na = a+1
            nb = b
            if a%2 != 0:
                nt= nt+2
            else:
                nt = nt + crosstime(nt, 0, a/2, b/2)
            update(na,nb,nt)
        if b!=0:
            na = a
            nb = b-1
            if b%2 == 0:
                nt= nt+2
            else:
                nt = nt + crosstime(nt, 1, a/2, b/2)
            update(na,nb,nt)
        if b!=M*2-1:
            na = a
            nb = b+1
            if b%2 != 0:
                nt= nt+2
            else:
                nt = nt + crosstime(nt, 1, a/2, b/2)
            update(na,nb,nt)


    print "Case #"+str(i+1)+": "+str(dp[0][0])
    


