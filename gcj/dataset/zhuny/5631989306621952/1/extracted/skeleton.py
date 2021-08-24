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
        string = self.get_line()
        front = []
        back = []

        for char in string:
            if len(front)+len(back) == 0:
                front.append(char)

            elif self.get_first(front,back) <= char:
                back.append(char)

            else:
                front.append(char)

        back.reverse()
        back.extend(front)

        self.print_ln("".join(back))

    def get_first(self,front,back):
        if back:
            return back[-1]
        else:
            return front[0]






if __name__ == '__main__':
    CodeJamTest()

