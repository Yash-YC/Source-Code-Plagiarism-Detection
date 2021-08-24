T = gets.to_i
N = 1000

def pow a, n
    r = 1
    n.times do
	r *= a
    end
    r
end

q = 1
while buf = gets
    tmp = buf.split.map{|e| e.to_i}
    c = tmp[0]
    n = tmp[1]
    p = n.to_f / c.to_f
    e = 1
    if p < 1
	for k in 1..N do
	    e += p / (1 - p) * k.to_f * pow(1 - p, k)
	end
    end

    puts "Case ##{q}: #{e}"
    
    q += 1
end
