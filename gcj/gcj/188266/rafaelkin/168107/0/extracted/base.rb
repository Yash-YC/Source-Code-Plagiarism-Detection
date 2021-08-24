file = File.open("A-small-attempt0.in")
t = file.readline.to_i

@cycle = []

def calculate(number, base)
  base_number = number.to_s(base).split(//).map(&:to_i)
  sum = 0
  base_number.each do |value|
    sum += value*value 
  end
  #puts "number: #{number}, base_number: #{base_number}, sum: #{sum}"
  #sleep 1
  return false if @cycle.include? sum
  @cycle << sum
  sum == 1 or calculate(sum, base)
end

1.upto(t) do |c|
  bases = file.readline.split.map(&:to_i)
  found = false
  min = 2
  2.upto 1.0/0 do |k|
     #puts "trying #{k}"
     bases.reverse.each do |base|
       @cycle = []
       break unless calculate(k, base)
       
       found = true if base == bases.first
     end
     if found
       puts "Case ##{c}: #{k}"
       break
     end
   end 
end
