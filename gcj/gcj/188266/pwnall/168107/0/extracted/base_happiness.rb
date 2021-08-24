#!/usr/bin/env ruby
#
# Author:: Victor Costan <costan@gmail.com>
# Copyright:: none
# License:: Public Domain

@memo = Array.new(11) { Hash.new }

def happy(n, b)
  visited = {}
  answer = nil
  loop do
    return @memo[b][n] if @memo[b].has_key? n
    if n == 1
      answer = true
      break
    end
    visited[n] = true
    new_n = 0
    while n != 0
      new_n += (n % b) ** 2
      n /= b
    end
    n = new_n
    if @memo[b].has_key? n
      answer = @memo[b][n]
      break
    end
    if visited[n]
      answer = false
      break
    end
  end
  
  visited.keys.each { |k| @memo[b][k] = answer}
  return answer
end

tests = gets.to_i
1.upto(tests) do |test|
  bases = gets.split.map { |token| token.to_i }
  n = 2
  loop do
    if bases.all? { |b| happy(n, b) }
      print "Case ##{test}: #{n}\n"
      break
    end
    n += 1
  end
end


# Randomness follows
exit

nn = 2


(1..200).each { |i| puts i if happy(i, 10) }
exit

loop do
  if (4..10).to_a.all? { |b| happy(nn, b) }
    puts nn
    break
  end
  nn += 1
  puts nn if nn % 1000 == 0
end
