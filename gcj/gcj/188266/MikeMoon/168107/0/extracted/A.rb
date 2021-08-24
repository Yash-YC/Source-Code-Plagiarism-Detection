def ishappy(n, b, path)
	if n == 1 or b==2
		return true
	end
	path.push(n)
	next_array = n.divmod(b)
	repeat = next_array[1] ** 2
	while next_array[0] > 0
		next_array = next_array[0].divmod(b)
		repeat += next_array[1] ** 2
	end
	if path.index(repeat).nil?
		return ishappy(repeat, b, path)
	else
		return false
	end
end

c = readline.to_i
0.upto(c-1) do |x|
	parameters = readline.split
	bases = Array.new
	parameters.each { |b| bases.push(b.to_i) }
	happy = 2
	found = false
	while not found
		found = true
		0.upto(bases.length-1) do |b|
			if not ishappy(happy, bases[b], Array.new)
				found = false
				break
			end
		end
		happy += 1
	end
	puts "Case #%d: %d" % [x+1, happy-1]
end
