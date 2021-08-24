test = """3
2 3
2 3 7
9 10"""

def base10ToN( num, base ):
    x = []
    while( num > 0 ):
        x.append( num % base )
        num /= base

    x.reverse()
    return x

baseset = {}
nobaseset = {}
level = 0
circle = set()

def Luck( x, base ):
    global circle

    if x in circle:
        nobaseset[base].add( x )
        return False

    if x == 1:
        return True

    if x in baseset[base]:
        return True

    if x in nobaseset[base]:
        return False

    value = base10ToN( x, base )

    total = sum( [k ** 2 for k in value] )

#    print x, "=>", total
    if x == total:
        return False

    circle.add( x )
    result = Luck( total, base )

    if result:
        baseset[base].add( x )
    else:
        nobaseset[base].add( x )

    return result



def Happy( bases ):
    global circle
    i = 1
    End = False
    while( not End ):
        i += 1
#        print i
        End = True
        for b in bases:
            if b not in baseset:
                baseset[b] = set()

            if b not in nobaseset:
                nobaseset[b] = set()
            level = 0
            circle.clear()
            r = Luck( i , b )

            if not r:
                End = False
#                print "not ", b
#                pass

#        break


    return i

test = open( "A-small-attempt0.in" ).read()
lines = test.split( "\n" )
T = int( lines[0] )
for x in range( T ):
    bases = map( int, lines[1 + x].split( " " ) )
#    print bases
    print "Case #%s: %s" % ( x + 1, Happy( bases ) )
#    Happy( [9, 10] )




#Luck( int( base10toN( 143, 7 ) ) , 7 )

#def FindHappy( bases ):
#
#    s = HappyMemory[bases[0]]
#    for b in bases:
#        
#        
#    while( True ):


#rules = []
#for i in range( N ):
#    offset = 0
#    pure_rule = v[i + 1 + D]
#    rule = []
#    for j in range( L ):
#        if pure_rule[j + offset] == '(':
#            right = pure_rule.index( ")", j + offset )
##            print j, offset, right, pure_rule, rule
#            rule.append( pure_rule[j + offset + 1:right] )
#            offset = right - j
#        else:
#            rule.append( pure_rule[j + offset] )
#
#
#    rules.append( rule )
#
#print samples, rules
#
#root = {}
#childs = [root]
## build rule trees
#for r in rules:
#    for k in range( L ):
#        for s in r[k]:
#            for c in childs:
#                if childs[]


