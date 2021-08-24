require "pp"

def c(n, k)
  d(n,k).div(d(k,k))
end

def d(n, k)
  (n-k+1..n).inject(1) { |result, item|
    result * item
  }
end

def f(i, c, n, ans)
  if i == 0
    ret = 0.0
  elsif i < n
    tmp = 1.0
    for j in 1..i
      tmp += (ans[i-j] * c(i, j).to_f * c(c-i, n-j).to_f / c(c, n).to_f)
    end
    #(i-1).times { |j|
    #  tmp += (ans[j] * c(i, i-j).to_f * c(c-i, n-i+j).to_f / c(c, n).to_f) 
    #}
    ret = tmp / (1.0 - c(c-i, n).to_f / c(c, n).to_f)
  else
    tmp = 1.0
    for j in 1..n
      tmp += (ans[i-j] * c(i, j).to_f * c(c-i, n-j).to_f / c(c, n).to_f)
    end
    ret = tmp / (1.0 - c(c-i, n).to_f / c(c, n).to_f)
  end

  return ret
end

def makeAns(ans, c, n)
  (c-n+1).times { |i|
    ans.push(f(i, c, n, ans))
  }
end

def makep(c, n)
  ans = Array.new
  makeAns(ans, c, n)

  return ans[c-n]+1.0
end


inf = open(ARGV[0])
outf = open(ARGV[1], "w")

caseNum = inf.gets.to_i
caseNum.times { |i|
  tmpArray = inf.gets.split(" ")
  c = tmpArray[0].to_i
  n = tmpArray[1].to_i
  p = makep(c, n)

  outf.puts("Case #" + (i+1).to_s + ": " + p.to_s)
  puts("Case #" + (i+1).to_s + ": " + p.to_s)
}

inf.close
outf.close
