def convert(decimal, base)
  result = []
  until (decimal < 1)
    result = [decimal % base] + result
    decimal = decimal / base
  end
  result
end

def sum_of_each_digits_squre(digits, base)
  value = digits.inject(0) { |s, v| s += (v ** 2) }
  convert(value, base)
end

def is_happy_number?(number, base)
  digits = convert(number, base)
  prev_result = []
  result = sum_of_each_digits_squre(digits, base)
  until result == [1] or prev_result.include?(result)
    prev_result << result
    result = sum_of_each_digits_squre(result, base)
  end
  result == [1] ? true : false
end

def self_test
  p convert(83, 3)
  p convert(82, 3)
  p convert(82, 2)
  p convert(11, 4)
  p sum_of_each_digits_squre([8,2], 10)
  p sum_of_each_digits_squre([6,8], 10)
  p sum_of_each_digits_squre([1,0,0], 10)
  p sum_of_each_digits_squre(convert(82, 3), 3)
  p sum_of_each_digits_squre([2], 3)
  p sum_of_each_digits_squre([1,1], 3)

  p is_happy_number?(82, 10)
  p is_happy_number?(3, 2)
  p is_happy_number?(3, 3)
  p is_happy_number?(143, 3)
  p is_happy_number?(143, 2)
  p is_happy_number?(143, 7)
  p is_happy_number?(143, 6)

  2.upto(200) do |value|
    if is_happy_number?(value, 2) and is_happy_number?(value, 3) and is_happy_number?(value, 7)
      puts value 
      break
    end
  end

  2.upto(200) do |value|
    if is_happy_number?(value, 9) and is_happy_number?(value, 10)
      puts value
      break
    end
  end
end

if ARGV[0] == 'test'
  self_test
else
  File.open(ARGV[0], 'r') do |file|
    1.upto(file.readline.to_i) do |case_idx|
      bases = file.readline.split(' ').map(&:to_i)
      seed = 2
      until bases.all? { |base| is_happy_number?(seed, base) }
        seed += 1
      end
      puts "Case \##{case_idx}: #{seed}"
    end
  end
end