#!/usr/bin/env ruby

$GRESULT=[]
$CHECK=[]
100000.times do $GRESULT.push([]) end
100000.times do $CHECK.push([]) end

def getnums(temp,b)
	nums=[]
	until temp < b
		nums.push(temp%b)
		temp=temp/b
	end
	nums.push(temp)
	return nums
end

def check(i,b)
	return $GRESULT[i][b] if $GRESULT[i][b]!=nil
	if $CHECK[i][b]!=nil
		$GRESULT[i][b]=false
		return false
	end
	
	nums=getnums(i,b)
	val=nums.inject(0){|x,y| x+y*y}
	if val==1
		$GRESULT[i][b]=true
		return $GRESULT[i][b]
	end

	$CHECK[i][b]=true
	$GRESULT[i][b]=check(val,b)
	$CHECK[i][b]=nil
	return $GRESULT[i][b]
end


def gethappy(bases)
	i=1
	loop do
		i+=1
		checkresults=bases.map{|b| check(i,b)}
		resultflag=checkresults.inject(true){|x,y| x&&y}
		break if resultflag
	end
	return i
end


T=gets.to_i
VAL=[]
result=[]
T.times do
	VAL.push(gets.split(" ").map{|x| x.to_i})
end

VAL.each do |v|
	result.push(gethappy(v))
end

num=1
result.each do |val|
	print "\n" if num!=1
	print "Case ##{num}: #{val}"
	num+=1
end


