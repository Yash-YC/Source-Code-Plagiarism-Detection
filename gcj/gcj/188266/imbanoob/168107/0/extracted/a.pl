#!/usr/bin/perl -w

use strict;

my $limit = 100000;

sub solve{
	my ($b) = @_;
	my ($ret,$a,$elem,$c,$happy,$e,$reached);
	for(2..$limit){
		$happy = 1;
		foreach $elem (@$b){
			$reached = {};

			$a = numberToBase($_,join("",(0..$elem-1)));
			while($a ne 0 and $a ne 1){
				$e = 0;
				foreach $c(split("","$a")){
					$e += $c*$c; 
				}
				$a = numberToBase($e,join("",(0..$elem-1)));
				$reached->{$a} ++;
				if ($reached->{$a} >= 2){
					$a = 0;
					last;

				}
			}
			if ($a eq 0){
				$happy = 0;
				last;
			}
		}
		return $_ if ( $happy == 1);


	}
	die "limit reached";
}


sub numberToBase{

	my ($n,$b) = @_;
	my ($l,$i,$t,$s,@a,%h);
	$l = length($b);

	@a = split("",$b);

	foreach (0..$#a){
		$h{$_} = $a[$_];
	}
	$i = $l;
	$s = "";
	while ($n > 0){
		$t = $n % $i;
		$s = $h{$t/($i/$l)}.$s;

		$n -= $t;


		$i *= $l;

	}
	return $s;

}



my ($n,$s,$bList);
$n = <>;
chomp $n;

for (1..$n){

	$s = <>;
	chomp $s;
	$bList = [split(" ",$s)];



	print "Case #$_: ",solve($bList),"\n";

}







