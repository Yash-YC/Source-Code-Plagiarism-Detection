def happy(n, base)
  ns = []
  until n == 1 || ns.include?(n)
    ns << n
    n = (base(n, base).map { |k| k*k }).inject(0) { |a, k| a += k }
  end
  return (n == 1)
end

def base(n, base)
  r = []
  until n == 0
    r << n % base
    n = n / base
  end
  return r
end

gets.to_i.times do |x|
  bases = gets.split.map { |n| n.to_i }
  break if bases.empty?
  n = 2
  while true
    b = true
    bases.each do |base|
      b = happy(n, base)
      break unless b
    end
    break if b
    n += 1
  end
  puts "Case ##{x+1}: #{n}"
end

