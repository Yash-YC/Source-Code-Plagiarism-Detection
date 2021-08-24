#!/usr/bin/ruby

require 'set'

def tr(n, b)
	a = []
	while( n > 0 )
		a << n%b
		n = n/b
	end
	a.reverse
end

def get_ret( ret, b )
	bbb = false 
	tmp = old_tmp = ret
	olds = Set.new
	olds << tmp

	while( true )
		a = tr(tmp, b)

		tmp = a.inject(0){|sum, e| sum + e*e}

		if(tmp == 1)
			bbb = true
			break
		elsif(olds.member?(tmp))
			bbb = false
			break
		end
		olds << tmp
	end

	bbb
end

fp = open(ARGV[0], "r")
num = fp.readline.chomp
(1..num.to_i).each{|c|
	bases = fp.readline.chomp.split.map{|e| e.to_i}


	ret = 2
	while ( !bases.all?{|b| get_ret(ret, b) } )
		ret = ret + 1
	end
	print "Case ##{c}: #{ret}\r\n"
}
