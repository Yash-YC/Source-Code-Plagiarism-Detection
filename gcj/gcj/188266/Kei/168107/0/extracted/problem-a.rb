require "pp"

def toBaseB(c, b)
  nA = Array.new
  
  while (c >= b)
    nA.unshift(c % b)
    c = c / b
  end
  nA.unshift(c)

  return nA
end

def isHappy(n, b)
  memory = Hash.new(0)
  c = n
  while (c != 1 && memory[c] == 0)
    memory[c] = 1
    nA = toBaseB(c, b)
    c = 0
    nA.each { |d|
      c += d*d
    }
  end 
  
  if c == 1
    return true
  end
  
  return false
end

def isOK(n, baseArray)
  flag = true
  baseArray.each { |b|
    if !isHappy(n, b) then
      flag = false
    end
  }

  return flag
end

inf = open(ARGV[0])
outf = open(ARGV[1], "w")

caseNum = inf.gets.to_i

caseNum.times { |i|
  bA = inf.gets.split(" ")
  bA.each_index { |j|
    bA[j] = bA[j].to_i
  }

  n = 2
  while !isOK(n, bA)
    n += 1
  end

  outf.puts("Case #" + (i+1).to_s + ": " + n.to_s)
  puts("Case #" + (i+1).to_s + ": " + n.to_s)
}

inf.close
outf.close
