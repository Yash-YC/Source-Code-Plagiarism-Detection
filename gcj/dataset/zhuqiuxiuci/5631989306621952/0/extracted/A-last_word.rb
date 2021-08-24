T = gets.chomp.to_i

for repeat in 1..T
	s = gets.chomp
	print "Case ##{repeat}: "

	res = ""
	for ind in 0...s.size
		if res.size < 1
			res = res + s[ind]
		else
			if s[ind] < res[0]
				res = res + s[ind]
			else
				res = s[ind] + res
			end
		end
	end
	puts res
end

