def write_in_base(n, b)
  out = ""
  while (n >= b) do 
    out = "#{n % b}" + out
    n = n/b
  end
  out = n.to_s + out
end

def write_in_base_10(num, b)
  out = 0
  mult = 1
  num.reverse.each_char do |ch|
    out += ch.to_i * mult
    mult *= b
  end
  out
end

def is_happy(n, b)
  visited_hash = {}
  
  n_s = write_in_base(n, b)
  visited_hash[n_s] = false
  
  while(!visited_hash[n_s]) do
    visited_hash[n_s] = true
    if is_sum_one(n_s, b)
      return true
    else
      n_s = calculate_new(n_s, b)
    end
  end
  return false
end

def square(n_s, b)
  n = write_in_base_10(n_s, b)
  write_in_base(n*n, b)
end

def add(n_s, m_s, b)
  n = write_in_base_10(n_s, b)
  m = write_in_base_10(m_s, b)
  
  write_in_base(n+m, b)
end

def is_sum_one(n_s, b)
  sum = "0"
  
  n_s.each_char do |c|
    sum = add(c, sum, b)
  end
  
  sum == "1"
end


def calculate_new(n_s, b)
  sum = "0"
  n_s.each_char do |c|
    sum = add(sum, square(c, b) , b)
  end
  sum
end

def find_lowest(base_1, base_2, base_3)
  i = 1
  (1..100000).each do
    i += 1
    if is_happy(i, base_1)
      if is_happy(i, base_2)
        if base_3
          if is_happy(i, base_3)
            return i
          end
        else
          return i
        end
        
      end
    end
  end
end

def read_file(input_file="input.txt")
  file = File.new(input_file, "r")
  line = file.gets
  lines = line.chomp.to_i
  p lines
 
  bases = []
  (1..lines).each do |j|
    line = file.gets.chomp
    bases << line.split(" ").map(&:to_i)
  end
  p bases

  case_no = 0
  bases.each do |input|
    case_no += 1
    num = find_lowest(input[0], input[1], input[2])
    
    p "Case \##{case_no}: #{num}"
  end  
  file.close
end
