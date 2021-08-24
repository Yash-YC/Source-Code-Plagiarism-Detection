import sys, os

def main():
	t = int(raw_input()) # read a line with a single integer
	case = 0
	for i in xrange(1, t+1):
		case += 1
		out = []
		for s in raw_input():
		#print "Input Case#{}: {}".format(i, s)

			if out:
				if s >= out[0]:
					out.insert(0, s)
				else:
					out.append(s)
			else:
				out.append(s)

		print "Case #%s: %s" % (case, ''.join(out))

if __name__ == "__main__":
	main()