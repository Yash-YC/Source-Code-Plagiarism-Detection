#!/usr/bin/perl -w 

use warnings;

my $inFile = shift;

open(INFILE,"<$inFile") or die "$!Erro ao abrir: $inFile\n";
my @inData = <INFILE>;
close INFILE;
# ==================================================================================================
my $counter = 0;
my $numTC = $inData[$counter]; chomp($numTC); $counter++;
$case = 1;
for(my $i=0; $i<$numTC; $i++){

	

	my $d = $inData[$counter]; chomp($d); $counter++;
	my @aux = split(/ / , $d);

	my $resp = $aux[0]/$aux[1] + 1;

	print "Case #$case: ";
	printf '%.5f'."\n", $resp;
	$case++;
}

exit;
