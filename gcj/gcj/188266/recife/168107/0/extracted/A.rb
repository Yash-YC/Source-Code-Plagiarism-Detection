require 'scanf'
require 'pp'

def nxt(i,b)
  if (i<b) then
    i*i
  else
    j = i%b
    j*j + nxt(i/b,b)
  end
end


def happy(i,b)
  used = {}
  while (true) do
#    puts "- happy with #{i}:#{b}"
    return true if (i==1)
    used[i] = true
    i = nxt(i,b)
    return false if used[i]
  end
end


T = gets.to_i
(1..T).each do |t|
  base = gets.strip.split.map{|x|x.to_i}
#  puts "base:"
#  pp base
  ok = false
  i = 1
  while !ok do
    i = i + 1
    ok = true
#    puts "testing #{i}!!"
    base.each do |b|
      if !happy(i,b) then
        ok = false
#        puts "#{i}:#{b} is not happy"
        break
      else
#        puts "#{i}:#{b} is happy"
      end
    end
  end
  puts "Case ##{t}: #{i}"
end


