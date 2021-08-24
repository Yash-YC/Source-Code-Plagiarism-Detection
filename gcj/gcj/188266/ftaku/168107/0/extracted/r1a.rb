file = open('A-small-attempt0.in', 'r')
problem_arr = file.read.split("\n")
file.close

def trans_base(deci, base_num)
  ret = Array.new
  loop do
    ret << deci % base_num
    deci = deci / base_num
    if deci < base_num then
      ret << deci
      break
    end
  end
  return ret
end

pair3 = Array.new
9.times do |i|
  (9-i).times do |j|
    j += i
    (9-j).times do |k|
      k += j
      pair3 << [i+2,j+2,k+2]
    end
  end
end

ans_table = Array.new
ans = 2
loop do
  ans_table[ans] = Array.new(11, true)
  (2..10).each do |base|
    temp_hash = Hash.new
    temp_hash[ans] = true
    ans_copy = ans
    
    loop do
      trans_ans = trans_base(ans_copy, base)
      temp = 0
      trans_ans.each do |i|
        temp += i*i
      end
      ans_copy = temp
      
      #puts"ans_copy: #{ans_copy}"
      
      if temp_hash[ans_copy] then
        ans_table[ans][base] = false
        break
      elsif ans_copy == 1 then
        ans_table[ans][base] = true
        break
      end
      temp_hash[ans_copy] = true
    end
  end
  
  pair3.delete_if do |ele|
    ans_table[ans][ele[0]] == true && ans_table[ans][ele[1]] == true && ans_table[ans][ele[2]] == true
  end
  break if pair3.empty?
  ans += 1
end

ans_arr = Array.new
test_case_num = problem_arr[0].to_i
test_case_num.times do |i|
  base_arr = problem_arr[i+1].split.map{|ele| ele.to_i}
  index= 2
  loop do
    temp = true
    base_arr.each do |base|
      temp &= ans_table[index][base]
    end
    break if temp
    index += 1
  end
  ans_arr << index
end

ans_arr.each_with_index do |ans, index|
  puts"Case ##{index+1}: #{ans}"
end

