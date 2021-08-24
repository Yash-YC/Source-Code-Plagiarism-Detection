inputfile = ARGV.shift

f = File.new(inputfile)

class Fixnum
	def choose(k)
		return 0 if (k > self)
		n = self
		r = 1
		1.upto(k) do |d|
			r *= n
			r /= d
			n -= 1
		end
		return r
	end
end

t = f.gets.to_i
t.times do |i|
	c, n = f.gets.split.collect{|x| x.to_i}
	
	c -= n

	arr = {0 => 1}
	1.upto(c).each do |left|
		arr[left] ||= 1
		(n+1).times do |choose|
			if left - choose < 0
				arr[left] += n.choose(choose).to_f / (2 ** n)
			else
				arr[left] += (1+arr[left-choose]) * n.choose(choose).to_f / (2 ** n)
			end
		end
	end

	res = arr[c]
	puts "Case ##{i+1}: %.7f" % res
end

f.close
