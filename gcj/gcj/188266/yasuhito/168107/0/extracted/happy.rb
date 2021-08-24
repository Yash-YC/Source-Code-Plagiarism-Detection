#!/usr/bin/env ruby

input = IO.read( ARGV[ 0 ] ).split( "\n" )
test_cases = input[ 1..-1 ]

def convert_base number, base
  result = ""
  while number > 0
    tmp = number % base
    number /= base
    result = "#{ tmp }#{ result }"
  end
  result.to_i
end


def happy? number, base
  history = []
  snumber = convert_base( number, base ).to_s
  loop do
    sum = snumber.split( // ).inject( 0 ) do | result, each |
      result += each.to_i * each.to_i
    end
    sum = convert_base( sum, base )
    if history.include? sum
      return false
    else
      history << sum
    end
    if sum == 1
      return true
    else
      snumber = sum.to_s
    end
  end
end




input[ 1..-1 ].each_with_index do | bases, index |
  candidate = 2
  loop do
    all_happy = bases.split( /\s+/ ).inject( true ) do | result, each |
      result = result and happy?( candidate, each.to_i )
    end
    if all_happy
      puts "Case ##{ index + 1 }: #{ candidate }"
      break
    end
    candidate += 1
  end
end


# p convert_base( 9, 2 )
# p happy?( 20, 10 )
# p happy?( 91, 2 )
# p happy?( 91, 3 )
# p happy?( 91, 9 )
# p happy?( 91, 10 )


