#!/usr/bin/env ruby

def calc(n, base)
  hist = Array.new
  hist.push(n)

  while true do
    sum = (n % base) * (n % base)

    while n >= base do
      n = n / base
      sum += (n % base) * (n % base)    
    end

    if hist.include?(sum) then
      return sum
    end
    hist.push(sum)
    
    if sum < base && (sum * sum) < base then
      return sum
    end

    n = sum
  end

  return sum
 end


$stdin.gets
ntests = $_.to_i

for i in (1 .. ntests)
  $stdin.gets
  @bases = $_.split
  j = 2
  while true do
    found = true
    for base in @bases
      if calc(j, base.to_i) != 1 then
        found = false
        break
      end
    end
    if found then
      printf("Case #%d: %d\n", i, j)
      break
    end
    j = j + 1
  end
end
