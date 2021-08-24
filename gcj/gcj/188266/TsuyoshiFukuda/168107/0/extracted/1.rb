def gcj(n, &block)
	(1..n).each do |i|
		res = block.call
		if Array === res
			puts "Case \##{i}:"
			res.each do |line|
				puts line
			end
		else
			puts "Case \##{i}: #{res}"
		end
	end
end

def get(n, base)
	v = 0
	begin
		d = n % base
		v += d ** 2
		n /= base
	end while n > 0
	v
end

def happy(n, base)
	h = {}
	x = n
	loop do
		return false if h.has_key?(x)
		v = get(x, base)
		return true if v == 1
		h[x] = true
		x = v
	end
end


def process(basis)
	n = 2
	loop do
		flag = true
		basis.each do |base|
			unless happy(n, base)
				flag = false
				break
			end
		end
		return n if flag
		n += 1
	end
	n
end

t = gets.to_i

gcj(t) do
	basis = gets.chomp.split(/\s+/).map{|x| x.to_i}
	process(basis)
end
