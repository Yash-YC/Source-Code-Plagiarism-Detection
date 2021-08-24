filename = "A-small-attempt0"

fin = File.new("#{filename}.in",  "r")
fout = File.new("#{filename}.out",  "w")

def dec2base(number, base)
   number = Integer(number);
   if (number == 0)
      return 0;
   end
   ret_bin = "";
   while (number != 0)
      ret_bin = String(number % base) + ret_bin;
      number = number / base;
   end
   return ret_bin;
end

fin.gets.to_i.times do |t|
  bases = fin.gets.split.map { |m| m.to_i }
  num = 1
#  puts "Test ##{t}"

  while (true) do
    num += 1
#    puts "Num #{num}"
    valid = true
    bases.each do |b|
      if (valid == false) then next end
#      puts "Base #{b}"
      old = Array.new
      s = dec2base(num, b)
      begin
#        puts "Check #{s}"
        counter = 0
        s.split(//).each do |x|
          counter += x.to_i * x.to_i
        end
        s = dec2base(counter, b)
        if (old.include?(counter))
          break
        end
        old.push(counter)
      end while counter > 1
      if (counter != 1) then valid = false end
    end
    if (valid)
      fout.puts "Case ##{t+1}: #{num}"
      break
    end
  end
end

fin.close
fout.close
