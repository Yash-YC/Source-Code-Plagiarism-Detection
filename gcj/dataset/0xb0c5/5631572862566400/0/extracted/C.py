

def get_sink_and_lengths(g,i):
	visited = []
	while not i in visited:
		visited.append(i)
		i = g[i]
	idx = visited.index(i)
	return i,len(visited)-idx,idx+1

def solve(g):
	segment_lengths = {}
	max_cycle = 0
	
	for i in range(len(g)):
		sink,cycle_length,length = get_sink_and_lengths(g,i)
		if cycle_length == 2:
			if (not sink in segment_lengths) or segment_lengths[sink] < length:
				segment_lengths[sink] = length
		else:
			max_cycle = max(max_cycle, cycle_length)
	
	segment_solution = sum(segment_lengths[sink] for sink in segment_lengths)
	return max(segment_solution, max_cycle)
	
n_cases = input()
for i in range(1,n_cases+1):
	raw_input()
	g = [int(z)-1 for z in raw_input().split(' ')]
	print 'Case #%d:' % i,
	print solve(g)