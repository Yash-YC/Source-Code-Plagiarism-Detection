def happy?(number, base)
  seen = {}
  result = 0
  
  begin
    result = 0
    seen[number] = true
    until(number.empty?)  
      digit = number.slice!(-1).chr
      result += digit.to_i ** 2
    end
    number = result.to_s(base)
  end until(seen[number])
  
  return result == 1
end


all = IO.readlines('A-small-attempt0.in.txt')
count = all.shift.to_i

count.times do |case_id|
  bases = all.shift.chomp.split(/\s+/).map { |val| val.to_i }

  answer = 0;
  2.upto(999999) do |i|
    answer = i
    break if bases.all? { |base| happy?(i.to_s(base), base) }
  end
    
  puts "Case \##{case_id + 1}: " + answer.to_s
end