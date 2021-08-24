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




class CodeJamTest(CodeJam):
    def do(self):
        d = {}
        n = self.get_number()

        for i in range(2*n-1):
            for l in self.get_numbers():
                d[l] = d.get(l,0)+1

        keys = []
        for k,v in d.items():
            if v%2 == 1:
                keys.append(k)

        keys.sort()
        self.print_ln(" ".join(map(str,keys)))





if __name__ == '__main__':
    CodeJamTest()

