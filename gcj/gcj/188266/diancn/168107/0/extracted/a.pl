#!/usr/bin/perl

use strict;

my($i, $j, $k, $kk, $nkk, @blist, $h,@loop);
=dd
for($i=2; $i<=9; $i++) {
	print to_x($i, 91),"\n";
}
exit;
=cut

my($casenum);
$casenum = <>;
chomp($casenum);

for($i=0;$i<$casenum;$i++) {
	$_=<>;
	chomp;
	@blist=split(/ /, $_);
#print "@blist\n";
	KF:
	for($k=2;;$k++) {
	#for($k=2;$k<2000;$k++) {  #debug
		JF:
		for($j=0;$j<=$#blist;$j++) {
			@loop=();
			$kk = $k;
			
#		print "f:  j=$j, base=$blist[$j], k=$k,  kk=$kk, nkk=$nkk\n";
			$h=1;
			$nkk =sum_sq(to_x($blist[$j], $kk));
			#$nkk =sum_sq($kk);
#		print "f:  j=$j, base=$blist[$j], k=$k,  kk=$kk, nkk=$nkk\n";
			#$nkk =$kk;
			#while($nkk>$blist[$j]-1 and $nkk != $k) {
			#while($nkk>$blist[$j]-1 ) {
			while($nkk !=1 ) {
				if(found(\@loop, $nkk)==1) {
					$h=0;
					last JF;
				}
				push(@loop, $nkk);
#				print "kk=$kk, nkk=$nkk\n";
				$kk = $nkk;
				$nkk =sum_sq(to_x($blist[$j], $kk));
			}
			if ($nkk != 1) {
				$h=0;
				last JF;
			}
		}
		if($h==1) {
			printf "Case #%d: $k\n", $i + 1;
			last KF;
		}
	}
}
close(FH);

sub found {
	my($ra, $key) = @_;
	my($item);
	foreach $item (@$ra) {
		if($key == $item) {
			return 1;
		}
	}
	return 0;
}
sub sum_sq {
	my($num) = @_;
	my($sum, $i, @list);
	@list=split(//, $num);
	for($i=0;$i<=$#list;$i++) {
		$sum+=$list[$i]*$list[$i];
	}
	return($sum);
}

sub to_x {
	my($base, $num) = @_;
	my($shang, $yu, @list);
	$shang=int($num / $base);
	while($shang!=0) {
		$yu=$num % $base;
		#print "$shang, $yu\n";
		$num=$shang;
		push(@list, $yu);
		$shang=int($num / $base);
	}
	push(@list, $num);
	#print "@list\n";
	return(join('', reverse(@list)));
}

sub to_dec {
	my($base, $str) = @_;
	my($i, @list, @newlist, $sum, $len);
	@list = split(//, $str);
	@newlist = reverse @list;
	$len = $#list;
	for($i=0; $i<=$len; $i++) {
		$sum += $list[$i] * expn($base, ($len-$i));
		print "$sum\n";
	}
	return($sum);
}

sub expn {
	my($b, $e) = @_;
	my($res) = 1;
	foreach (1..$e) {
		$res *= $b;
	}
	return $res;
}
