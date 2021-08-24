#! /usr/bin/ruby

def happy(x, base, seen)
  # puts "Checking #{x} for base #{base} having seen #{seen}\n"
  if seen.member?(x)
    return false
  end
  seen.push(x)
  str = x.to_s(base)
  ss = 0
  str.each_byte do |c|
    d = c - '0'[0]
    ss += d*d
  end
  if ss == 1
    return true
  end
  return happy(ss, base, seen)
end

def all_happy(x, bases)
  # puts "Checking #{x} for bases #{bases}\n"
  return bases.all? do |base|
    happy(x, base, [])
  end
end

filename = ARGV[0]
file = File.new(filename)
lines = file.readlines

lines.shift

lines.each_with_index do |l, c|
  bases = l.split(" ").map { |s| s.to_i }
  x = 2
  while (not all_happy(x, bases)) do
    # puts "x = #{x}\n"
    x = x + 1
  end
  puts "Case \##{c+1}: #{x}\n"
end

