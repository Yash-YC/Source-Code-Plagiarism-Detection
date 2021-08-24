#!/usr/bin/ruby

def happy?(n, b)
  e = []
  loop do
    a = n.to_s(b).split(//).map { |s| s.to_i }
    n = 0
    a.each { |x| n += x * x }
    return true if n == 1
    return false if e.include?(n)
    e << n
  end
end

T = ARGF.gets.to_i
bases = nil
for i in 1..T
  bases = ARGF.gets.split(/ /).map { |s| s.to_i }
  n = 2
  loop do
    f = true
    bases.each do |b|
      f &= happy?(n, b)
      break unless f
    end
    break if f
    n += 1
  end
  puts "Case \##{i}: #{n}"
end

