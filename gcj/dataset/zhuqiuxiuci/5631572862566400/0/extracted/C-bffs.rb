T = gets.chomp.to_i

def unionFind(union, ind)
	if union[ind] != ind
		grand = unionFind(union, union[ind])
		union[ind] = grand
		return grand
	end
	return ind
end

def unionAddPair(union, j, k)
	jr = unionFind(union, j)
	kr = unionFind(union, k)
	union[kr] = jr
end

def unionGetSets(union)
	sets = Hash.new
	for ind in 0...union.size
		rt = unionFind(union, ind)
		if sets.has_key? rt
			sets[rt] << ind
		else
			sets[rt] = [ind]
		end
	end
	return sets
end

def findLongestPath(nl, pt, visited, fs, liked)
	longest = 0
	path = []
	if not liked[pt]
		pn = fs[pt]
		if not visited[pn]
			nv = visited.dup
			nd = liked.dup
			nv[pn] = true
			liked[pt] = true
			if fs[pn] == pt
				liked[pn] = true
			end
			rec, rep = findLongestPath(nl, pn, nv, fs, liked)
			rec += 1
			if rec > longest
				longest = rec
				path = rep
			end
		end
	else # Current kid already sits with who he likes
		for pn in nl[pt]
			if not visited[pn]
				nv = visited.dup
				nd = liked.dup
				nv[pn] = true
				raise RuntimeError if fs[pt] == pn
				liked[pn] = true
				rec, rep = findLongestPath(nl, pn, nv, fs, liked)
				rec += 1
				if rec > longest
					longest = rec
					path = rep
				end
			end
		end
	end
	return longest, [pt] + path
end

def doubleCheck(fs, path)
	for ind in 0...path.size
		if fs[path[ind]] != path[ind - 1]
			if fs[path[ind]] != path[(ind + 1) % path.size]
				return false
			end
		end
	end
	return true
end

for repeat in 1..T
	n = gets.chomp.to_i
	fs = gets.chomp.split.map {|f| f.to_i - 1}
	print "Case ##{repeat}: "
	raise RuntimeError if n != fs.size
	
	union = (0...n).to_a
	for ind in 0...n
		unionAddPair(union, ind, fs[ind])
	end
	sets = unionGetSets(union)
	# p sets
	nl = []
	for ind in 0...n
		nl << []
	end
	for ind in 0...n
		nl[ind] << fs[ind]
		nl[fs[ind]] << ind
	end
	for ls in nl
		ls.uniq!
		ls.sort!
	end
	# p nl
	# res = findLongestPath(nl, 0, [true] + [false] * (n - 1), fs, [false] * n)
	# p res

	overall = []
	for set in sets
		overall << []
		longest = 0
		path = []
		stats = overall[-1]
		for ind in 0...n
			visited = [false] * n
			visited[ind] = true
			liked = [false] * n
			res, rep = findLongestPath(nl, ind, visited, fs, liked)
			res += 1
			# if not doubleCheck(fs, rep)
			#	next
			# end
			if fs[rep[-1]] != rep[-2] and fs[rep[-1]] != rep[0]
				next
			end
			# if res > longest
			#	longest = res
			#	path = rep
			# end
			if fs[rep[-1]] == rep[-2]
				stats << [res, true]
			else
				stats << [res, false]
			end
		end
	end
	longestF = 0
	longestT = 0
	for stats in overall
		biggestT = 0
		for t in stats
			if t[1]
				if biggestT < t[0]
					biggestT = t[0]
				end
			else
				if longestF < t[0]
					longestF = t[0]
				end
			end
		end
		longestT += biggestT
	end
	if longestF > longestT
		puts longestF
	else
		puts longestT
	end
end
