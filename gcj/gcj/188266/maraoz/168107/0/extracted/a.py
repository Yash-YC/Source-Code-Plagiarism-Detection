# -*- coding: utf-8 -*-

import sys
from base import GcjSolver

def base_string(base):
    r = ''
    for i in xrange(base):
        r+= str(i)
    return r

def alien_convert(number='100',src_language='0123456789',dest_language='01'):
    src_base=len(src_language)
    dest_base=len(dest_language)
    num_length=len(number)

    num_pointer= 0
    decimal_number=0
    for i in number:
        num_pointer+=1
        src_pointer= -1
        digit_is_in_src_language_flag=0
        for j in src_language:
            src_pointer+=1
            if (i==j):
                decimal_number+=src_pointer*src_base**(num_length - num_pointer)
                digit_is_in_src_language_flag=1
        if (digit_is_in_src_language_flag==0):
            print "the digit %i in number was not found in the source language" % (num_pointer)
    resultado=''
    while (decimal_number>0):
        resto=decimal_number % dest_base
        dest_pointer= -1
        for k in dest_language:
            dest_pointer+=1
            if(dest_pointer==resto):
                resultado= k+resultado 
        decimal_number=decimal_number/dest_base
    return resultado

class XSolver(GcjSolver):
    Eee = 1
    def get_case(self):
        bases =  [int(x) for x in self.get_line().split(" ")]
        return bases
    def solve(self, bases):
        print "case", self.Eee
        self.Eee += 1
        i = 2
        while( not self.is_happy_in_bases(i,bases)):
            i += 1
        return str(i)
    def is_happy_in_bases(self, n, bases):
        for base in bases:
            if (not self.is_happy_in_base(n,base)):
                return False
        return True
    def is_happy_in_base(self, n, base):
        bs = base_string(base)
        converted = alien_convert(str(n),'0123456789',bs)
        memory = {}
        actual = -2
        while (memory.get(actual) != True):
            memory[actual] = True
            actual = self.sqsum(converted, bs)
            converted = str(actual)
        return actual == "1"
    def sqsum(self, converted, bs):
        suma = 0
        for c in converted:
            suma += int(c)**2
        return alien_convert(str(suma),'0123456789',bs)

def main(program, name):
    s = XSolver(name)
    s.run()


if __name__ == '__main__':
    reload(sys); sys.setdefaultencoding('utf-8')
    main(*sys.argv)