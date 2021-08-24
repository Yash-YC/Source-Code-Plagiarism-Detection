inputfile = ARGV.shift

f = File.new(inputfile)

t = f.gets.to_i
t.times do |i|
	a = f.gets.split.collect{|x| x.to_i}

	j = 2
	n = nil
	while true
		a.each do |base|
			n = j.to_s(base)
			history = []
			until n == "1" or history.include? n
				history << n
				n = n.split(//).inject(0){|s,v| s + v.to_i ** 2}.to_s(base)
			end
			if n != "1"
				j += 1
				break
			end
		end
		if n == "1"
			res = j
			break
		end
	end

	puts "Case ##{i+1}: #{res}"
end

f.close
