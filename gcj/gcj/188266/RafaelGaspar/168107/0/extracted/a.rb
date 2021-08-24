require "set"

def is_happy?(number, base)  
  checkeds = Set.new()
  
  new_number = number
  
  begin
    digits = []
    new_number.to_s(base).each_byte do |b|
      digits << b.chr.to_i
    end
    
    squares = digits.collect { |x| x*x }

    sum = 0
    squares.map { |x| sum += x}
    
    if sum == 1
      return true
    else
      checkeds << new_number
      new_number = sum
    end
  end while !checkeds.member?(new_number)
    
  return false
end

def main(argv)
  # Get the parameters from input file    
  num_of_tests = readline.to_i
  
  num_of_tests.times do |i|
    bases = readline.split.collect { |x| x.to_i }
    
    j = 2
    while true
      h = true
      bases.map { |b| h &&= is_happy?(j, b) }
       
      if h
        puts "Case ##{i+1}: #{j}"
        break
      else         
        j += 1
      end
    end
  end
end

main(ARGV)