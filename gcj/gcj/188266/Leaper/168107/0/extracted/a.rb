def happy? n, base
  ns = n.to_s.split("").map { |s| s.to_i }
  ret = ""
  for a in ns
    return -1 if a > base
    ret = (ret.to_i(base) + a*a).to_s(base)
  end
  ret
end

fin = File.open("A-small-attempt0.in")
fout = File.open("out.txt","w+")
cases = fin.readline().to_i
cases.times do |case_num|
  ps = fin.readline.chomp.split(" ").map { |obj| obj.to_i }
  passed = false
  start = 2
  while !passed
    passed = true
    happy = false
    for b in ps
      happy = false
      nums = []
      nums<<start.to_s(b)
      while true
        num = happy? nums.last,b
        if num == "1"
          happy = true
          break;
        elsif num == -1
          happy = false
          break;
        elsif nums.include?(num)
          happy = false
          break;
        end
        nums<<num
      end
      passed = passed && happy
    end
    start += 1
  end
  ss = "Case ##{case_num+1}: #{start-1}"
  fout.puts(ss)
end
fin.close
fout.close