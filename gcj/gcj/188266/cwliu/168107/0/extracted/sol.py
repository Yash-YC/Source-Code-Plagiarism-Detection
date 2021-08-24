#coding:utf-8
'''
Created on 2009/9/12

@author: Cody
'''
import math
filename = "bug"
filename = "B-small-practice"
filename = "B-large-practice"
filename = "sample"
filename = "A-small-attempt0"
fin = open(filename + ".in", "r")
fout = open(filename + ".out", "w")
T = int(fin.readline())

def toBase(n,base):
    list = []
    i = 1
    while n !=0 :
        list.append(n % base)
        n = n - n % base
        n = n / base
        i += 1
    return list
    
#init 
def happy(n,base):
    while True:
        #print "n: "+str(n)
        record = []
        ans = 0
        check = n 
        while True:
            list =  toBase(check,int(base))
            sum = 0
            for a in list :
                sum = sum + a*a
    
            if sum == 1:
                ans = 1
                break
            else:        
                check = sum
                try:
                    record.index(sum)
                    # exist 
                    ans = 0 
                    break;
                except ValueError:
                    record.append(sum)
        if ans == 0:
            return False
        else :
            return True

i = 0
for t in range(T):
    i = i + 1
    
    base_list= fin.readline()[:-1].split(" ")
    num = 2
    flag = True
    while True:
        result = True
        for base in base_list:
            if not happy(num,base):
                flag=False
                break
        if flag == True:
            print "Case #"+str(i)+": "+str(num)
            fout.write("Case #"+str(i)+": "+str(num)+"\n")
            break;
        else:
            num = num+1
            flag = True # reset
