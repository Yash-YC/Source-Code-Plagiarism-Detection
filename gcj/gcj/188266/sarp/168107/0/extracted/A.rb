def convert(num, base)
  num = num.to_i
  fin = ""
  while(num > 0)
    fin = (num % base).to_s + fin
    num = num/base
  end
  fin
end

def what(num, base, seen)
  sum = 0
  num.to_s.each_char do |chr|
    sum += chr.to_i * chr.to_i
  end
  sum = convert(sum, base).to_i
  #puts "num: #{num} sum #{sum}"
  return true if sum == 1
  return false if seen.include?(sum)
  newseen = seen << sum
  what(sum, base, newseen)
end

def findsmallest(bases)
  num = 2
  while(true)
    mask = true
    bases.each do |base|
      mask = mask & what(convert(num, base),base, [])
      break if !mask
    end
    #puts "exit"
    return num if mask
    num = num + 1
  end
end

lines = IO.read("A-small.in").split("\n")
cases = lines[0].to_i
cases.times do |c|
  bases = lines[c+1].split(' ').map {|x| x.to_i}
  puts "Case ##{c+1}: #{findsmallest(bases)}"
end