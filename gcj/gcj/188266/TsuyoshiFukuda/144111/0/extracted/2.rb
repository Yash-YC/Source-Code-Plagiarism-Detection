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


def group(a, width)
	n = (a.size + width - 1) / width
	(0...n).map do |i|
		a[i*width, width]
	end
end

def even?(x)
	x % 2 == 0
end

def calc_wait(t, tr, dir)
	cycle = tr[0] + tr[1]
	d = (t - tr[2]) % cycle
	if dir == 0		# north-south
		if d < tr[0]
			0
		else
			cycle - d
		end
	else
		if d < tr[0]
			tr[0] - d
		else
			0
		end
	end
end

def calc(traffic, m, n)
	buf = Array.new(n*2){Array.new(m*2)}
	buf[0][0] = 0
	(n*2).times do |i|
		(m*2).times do |j|
			t = buf[i][j]
			if i < n*2-1
				# to north
				tt = if even?(i)		# traffic
					tr = traffic[i/2][j/2]
					wait = calc_wait(t, tr, 0)
					t + wait + 1
				else					# block
					t + 2
				end
				if !buf[i+1][j] || buf[i+1][j] > tt
					buf[i+1][j] = tt
				end
			end

			if j < m*2-1
				# to east
				tt = if even?(j)		# traffic
					tr = traffic[i/2][j/2]
					wait = calc_wait(t, tr, 1)
					t + wait + 1
				else			# block
					t + 2
				end
				if !buf[i][j+1] || buf[i][j+1] > tt
					buf[i][j+1] = tt
				end
			end
		end
	end
	buf[n*2-1][m*2-1]
end

c = gets.to_i

gcj(c) do
	n, m = gets.chomp.split(/\s+/).map{|x| x.to_i}
	a = (0...n).map do
		b = gets.chomp.split(/\s+/).map{|x| x.to_i}
		group(b, 3)
	end.reverse
	calc(a, m, n)
end
