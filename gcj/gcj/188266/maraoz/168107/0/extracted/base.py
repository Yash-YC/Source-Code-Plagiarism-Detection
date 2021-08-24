#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

class GcjSolver(object):

    def __init__(self, name):
        self.name = name
        self.name_in = self.name+".in"
        self.name_out = self.name+".out"

    def run(self):
        self.fin = open(self.name_in, "r")
        self.fout = open(self.name_out, "w")

        case_number = self.get_int()
        for i in xrange(case_number):
            case = self.get_case()
            answer = self.solve(case)
            self.write(i, answer)
        self.fin.close()

    def write(self, index, answer):
        self.fout.write("Case #%d: %s\n" % (index+1, str(answer)))
    def get_line(self):
        return self.fin.readline().strip('\n')
    def get_int(self):
        return int(self.get_line())

    def get_case(self):
        raise NotImplementedError
    def solve(self, case):
        raise NotImplementedError

