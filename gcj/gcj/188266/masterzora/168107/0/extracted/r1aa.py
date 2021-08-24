import sys
import os
import string

happynums = {}

def main():
	s = sys.stdin.readlines()
	os.close(0)
        s = map(lambda X: X[:-1], s)
        
        N = int(s[0])
        s = s[1:]

        for i in range(N):
            bases = s[0].split()
            bases = map(lambda X: int(X), bases)
            s = s[1:]
            j = 1
            while True:
                j += 1
                isHappy = False
                for k in bases:
                    if happy(j, k):
                        continue
                    else:
                        break
                else:
                    isHappy = True
                if isHappy:
                    break
            
            print "Case #" + str(i+1) + ": " + str(j)

def happy(num, base):
    s = set([])
    while True:
        convNum = NumToBaseB(num, base)
        if convNum=="1":
            return True
        elif num in s:
            return False
        else:
            s.add(num)
            num = 0
            for i in convNum:
                num += int(i)**2



def NumToBaseB(N, B):
	''' converts a decimal integer N into a base-B string'''
	if N==0: return ""
	else: return NumToBaseB(N/B,B) + DecToB36Digit(N%B)

def BaseBToNum(S,B):
	''' converts a Base-B string S into a decimal integer'''
	if S == "": return 0
	else: return B * BaseBToNum(S[:-1],B) + B36DigitToDec(S[-1])
	
def BaseToBase(B1, B2, S):
	''' converts a base-B1 string S into a base-B2 string '''
	return NumToBaseB(BaseBToNum(S,B1),B2)

def add(S1, S2):
	''' Adds two binary strings '''
	return NumToBaseB(BaseBToNum(S1,2) + BaseBToNum(S2,2), 2)
	
def DecToB36Digit(N):
	''' converts a decimal digit into a digit of a base up to B36 '''
	if 0 <= N <= 9: return str(N)
	elif 10<=N<=35: return chr(ord('A')+N-10)
	else: return '0'
	
def B36DigitToDec(S):
	''' converts a digit of a base up to B36 into a decimal digit '''
	if "0" <= S <= "9": return int(S)
	elif "A" <= S <= "Z": return ord(S)+10-ord('A')
	else: return '0'
	    
   
if __name__ == "__main__":
 	main()

