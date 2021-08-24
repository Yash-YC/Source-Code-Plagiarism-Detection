#!/usr/bin/ruby

status = 0
cc = 0 # current case num

def f(n,b,arr)
  return true if n == 1
  input = n.to_s(b).split(//)
  out = 0
  input.map!{ |i| i.to_i}
  input.each{ |i|
    out += i * i
  }
#  p out
  arr.each{|a|
    return false if a == out
  }
  arr << out
  
  return f(out,b,arr)
end

def main(line)
  arr = line.split.map!{ |i| i.to_i}
  res = 2
  while 1
    flg = 1
#    print "res:#{res}\n"
    arr.each{ |b|
#      print "\tb:#{b}\t"
      a = []
#      flg = 0 unless f(res,b,a)
      if !f(res,b,a)
#        print "false\n"
        flg = 0
        break
      end
#      print "true\n"
    }
    break if flg == 1
    res += 1
  end
  return res
end

tc = STDIN.gets.chomp!.to_i

while line = STDIN.gets
  line.chomp!
  case status
  when 0
    cc += 1
    res = main(line)
    printf "Case ##{cc}: #{res}\n"
  end
end



