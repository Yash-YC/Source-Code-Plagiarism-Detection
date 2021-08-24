INF = 20000

$solution = []
$symbol = "a"
$map = []

def square_sum(num, base)
  num.to_s(base).split("").map{|x| x.to_i*x.to_i}.inject(0){|x,y| x+y}
end

def is_happy(num, base)
  (1..10).each do 
    num = square_sum(num, base)
    return true if num == 1
  end
  return false
end

def min_base(bases)
  (2..1000000000000).each do |test_int| 
    if(bases.map{|base| is_happy(test_int, base)}.select{|x| x == false}.empty?)
      return test_int
    end
  end
end

input = STDIN.read.split("\n")

input[1..-1].each_with_index do |bases_text, problem|
  
  bases = bases_text.split(" ").map{|x| x.to_i}
  
  puts "Case \##{problem+1}: #{min_base bases}"
  
end
