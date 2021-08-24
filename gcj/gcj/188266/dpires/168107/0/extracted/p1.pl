#!/usr/bin/perl -w 

use warnings;
use strict;

sub mudaBase;
sub happy;

my $inFile = shift;

open(INFILE,"<$inFile") or die "$!Erro ao abrir: $inFile\n";
my @inData = <INFILE>;
close INFILE;
# ==================================================================================================
my $counter = 0;
my $numTC = $inData[$counter]; chomp($numTC); $counter++;
my $case = 1;
for(my $j=0; $j<$numTC; $j++){
	my $bases = $inData[$counter]; chomp($bases); $counter++;

# 	print "BASES $bases\n";

	my @bases_v = split(/ /, $bases);
	for(my $i=2; $i<999999999; $i++){
		my $count = 0;
		foreach my $base (@bases_v){

# 			print "** base:$base - num:$i\n";
			my $b = mudaBase($base, $i);
# 			print "** resp: $b\n";

# 			print " $b -";

			if(happy($b, $base)){
				$count++;
# 				print "HAPPY\n";
			}
			else{
# 				print "NOT HAPPY\n";
			}
		}
# 		print "*******$count\n";

		if($count == scalar(@bases_v)){
			print "Case #$case: $i\n";
			$case++;
			$i = 999999999;
		}
	}
}
# ==================================================================================================

sub happy{

	my $hn = shift;
	my $base = shift;
	my $sum = 0;

	my $str = sprintf '%s', $hn;

# 	print " length:",length($str);

	for(my$r=0; $r<10; $r++){
		$sum = 0;
		for(my $k=0; $k<length($str); $k++){
			my $a = int(substr($str,$k,1));

			$sum += $a*$a;

# 			print "sum: $hn $a $sum length: ", length($str),"\n";

		}
		if($sum <= 1){
			return 1;
		}
		$str = sprintf '%s',mudaBase($base, $sum);

# 		print "::$str\n"
	}
	return 0;

}

sub mudaBase{

	my $base = shift;
	my $numero = shift;
	my $resp = "";

	while($numero > 0){
		my $str = sprintf '%s' , ($numero % $base);
		$resp = $str.$resp;

# 		print ">> ", ($numero % $base), "\n";
# 		print "<< $numero - $base\n";

		$numero = int($numero/$base);
	}

# 	print "=== $numero - $base - $resp\n";

	return $resp;
}
exit;
