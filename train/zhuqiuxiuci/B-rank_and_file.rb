T = gets.chomp.to_i

for repeat in 1..T
	n = gets.chomp.to_i
	files = []
	for j in 0...(2 * n - 1)
		files << gets.chomp.split.map(&:to_i)
	end
	print "Case ##{repeat}: "

	files.sort!
	stat = Hash.new
	for file in files
		for height in file
			if stat.has_key? height
				stat[height] += 1
			else
				stat[height] = 1
			end
		end
	end
	ls = []
	stat.each do |height, cnt|
		if cnt % 2 > 0
			ls << height
		end
	end
	ls.sort!
	puts ls.join(" ")
end

