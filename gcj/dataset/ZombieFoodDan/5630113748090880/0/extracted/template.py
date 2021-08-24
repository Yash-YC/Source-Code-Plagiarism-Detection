import sys, os

def main():
	t = int(raw_input()) # read a line with a single integer
	case = 0
	for i in xrange(1, t+1):
		case += 1
		n = int(raw_input())
		value_map = {}
		for j in xrange(1, 2*n):
			 for s in raw_input().split(" "):
			 	s = int(s)
			 	if s not in value_map:
			 		value_map[s] = 1
			 	else:
			 		value_map[s] += 1
	#		total = 0
	#		for x in line:
	#			total += x

			#print line #, total

		#	varray = value_map.setdefault(line[0], [])
		#	varray.append(line)

	#		varray = value_map.setdefault(total, [])
	#		varray.append(line)

		output = []
		for s, v in value_map.iteritems():
			if v % 2 > 0:
				output.append(s)

		output.sort()

		#for crap in xrange(0, len(columns)):
		#	output.append(columns[crap][-1])


		#k, c, s = [int(s) for s in raw_input().split(" ")]
		#print "Input Case#{}: {} {} {}".format(i, k, c, s)

		print "Case #%s: %s" % (case, ' '.join((str(s) for s in output)))

if __name__ == "__main__":
	main()