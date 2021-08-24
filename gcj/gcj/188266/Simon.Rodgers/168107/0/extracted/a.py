def sum_of_squares( n, base, seen ):
	i = n;
	r = 0;
	while i > 0:	
		r += (i % 10)**2;
		i /= 10;

	seen[n] = True;
	return convert_to_base( r, base )


def test_happy( n, base ):
	seen = dict();
	i = convert_to_base(n, base);
	while i > 1 and (i not in seen):
		i = sum_of_squares( i, base, seen );
	return (i == 1);


def get_smallest( bases ):
	i = 2;
	d = False;
	while not d:
		d = True;
		for b in bases:
			d = d and test_happy( i, b )
		if not d:
			i += 1
	return i
	


def convert_to_base( n, base ):
	r = 0;
	i = 0;
	while n > 0:
		r += (n % base) * 10**(i);
		n = n / base;
		i+=1;
	return r;

def convert_from_base( n, base ):
	r = 0;
	i = 1;
	while n > 0:
		r += (n % 10) * base**(i-1);
		n = n / 10;
		i+=1;
	return r;

raw = open("A-small-attempt0.in").readlines();

T = int(raw[0][:-1]);

for i in xrange( T ):
	N = (raw[i+1][:-1]).split(" ")
	for x in xrange(len(N)):
		N[x] = int(N[x])
	print "Case #" + str(i+1) + ": " + str(get_smallest( N ));
