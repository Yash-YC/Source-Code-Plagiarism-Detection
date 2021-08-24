#!/usr/bin/env ruby

def sumsq(n)
	n.split("").inject(0){|s,c|s+c.to_i**2}
end

def happy?(n,b)
	num = n.to_s(b)
	list = [num]
	while(true)
		ss = sumsq(num).to_s(b)
		return true if ss=="1"
		return false if list.include?(ss)
		list << ss
		num = ss
	end
end

gets.to_i.times do |x|
	print "Case ##{x+1}: "
	bases = gets.split.map{|c|c.to_i}
	n = 2
	while (true)
		c = 0
		bases.each do |b|
			break unless happy?(n,b)
			c += 1
		end
		break if c==bases.size
		n += 1
	end
	puts n
end
