# -*- coding:utf8

# Python3
# zhuny@kaist.ac.kr


import time


class Timer():
    def __init__(self,name):
        self.name = name
        self.start = 0.0

    def __enter__(self):
        self.start = time.time()

    def __exit__(self,ty,va,tr):
        # print (self.name,time.time()-self.start)
        pass


class CodeJam():
    def __init__(self):
        n = self.get_number()
        with Timer("CodeJam Time :"):
            for i in range(1,n+1):
                self.print_it("Case #{0}: ",i)
                self.do()

    def print_it(self,string="",*argv,**kwargs):
        print (string.format(*argv,**kwargs), end="")

    def print_ln(self,string="",*argv,**kwargs):
        self.print_it(string + "\n", *argv, **kwargs)

    def get_line(self):
        return input().strip()

    def get_line_func(self,func):
        return func(self.get_line())

    def get_number(self):
        return self.get_line_func(int)

    def get_numbers(self):
        return self.get_line_func(lambda l:list(map(int,l.split())))

    def do(self):
        self.print_it("\n")


class DisjointSet:
    def __init__(self):
        self.mapping = {}

    def _get_root(self,i):
        M = self.mapping
        while True:
            I = M.get(i,i)
            if I == i:
                return I
            i = I

    def connect(self,i,j):
        I = self._get_root(i)
        J = self._get_root(j)

        M = self.mapping
        if I != J:
            M[i] = M[j] = M[I] = J

    def get_sets(self):
        d = {}

        for k in self.mapping:
            K = self._get_root(k)
            if K not in d:
                d[K] = set()

            d[K].add(k)

        return d.values()


class CodeJamTest(CodeJam):
    def append(self,L,elem):
        L[elem] = len(L)

    def get_cycle_set(self,S,mapping):
        d = {}
        l = []
        for s in S:
            cur = s
            while True:
                if cur in d:
                    return set(l[d[cur]:])
                d[cur] = len(d)
                l.append(cur)
                cur = mapping[cur]

    def get_water_fall_length(self,S,cycle,mapping):
        SS = set(S)
        cycle_max = {c:(c,1) for c in cycle}
        while SS:
            cur = SS.pop()
            if cur in cycle_max:
                continue

            path = [cur]
            while cur not in cycle_max:
                cur = mapping[cur]
                path.append(cur)

            target,tail = cycle_max[path.pop()]
            while path:
                tail += 1
                cycle_max[path.pop()] = target,tail

        cycle_tail_max = {}
        for target,length in cycle_max.values():
            l = max(cycle_tail_max.get(target,0),length)
            cycle_tail_max[target] = l

        return sum(cycle_tail_max.values())

    def do(self):
        n = self.get_number()
        fl = self.get_numbers()
        fl = [l-1 for l in fl]

        S = DisjointSet()

        for i,bbf in enumerate(fl):
            S.connect(i,bbf)

        max_cycle = 0
        water_fall = 0

        for gr in S.get_sets():
            cycle = self.get_cycle_set(gr,fl)
            length = len(cycle)
            max_cycle = max(max_cycle,length)
            if length == 2:
                fall = self.get_water_fall_length(gr,cycle,fl)
                water_fall += fall

        self.print_ln("{0}", max(max_cycle,water_fall))





if __name__ == '__main__':
    CodeJamTest()

