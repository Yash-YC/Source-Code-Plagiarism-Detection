#!/usr/bin/perl
use Getopt::Long;
use strict;
use Data::Dumper;
use Math::BaseCnv;
++$|;
my($opt,$debug,$test);

GetOptions(
	'debug' => \$debug,
	'test' => \$test,
);

sub logmsg {
	print STDERR join("",@_)."\n" if $debug;
}

sub happy {
	my($x,$base)=@_;
	my($found,%seen);
	logmsg "happy($x,$base)";
	$x = cnv($x,10,$base);
	while(!$found&&!$seen{$x}) {
		$found = $x==1;
		last if $found;
		++$seen{$x};
		my $sum = 0;
		logmsg "  happy $x _$base";
		foreach my $digit (split(//,$x)) {
			$sum += cnv($digit,$base,10)**2;
		}
		$x = cnv($sum,10,$base);
	}
	logmsg "found=".(0+$found);
	return $found;
}

sub process {
	logmsg 'PROCESS '.Dumper(@_);
	my($base)=@_;
	my @base = @{$base||[]};
	my($found,$min);
	$min = -1;
	for(my $x=2;!$found && $x<=1000000;++$x) {
		my $basecnt;
		foreach my $current (@{$base}) {
			$basecnt+=happy($x,$current);
		}
		if(scalar(@base)==$basecnt) {
			$found = 1;
			$min = $x;
		}
		
	}
	logmsg "found=$found min=$min";
	return $min;
}

sub test {
	#print happy(143,7);
	#print process([9,10]),"\n";
	print process([2,3,7]),"\n";
}

if($test) {
	$debug=1;
	test();
	exit(0);
}

my $file = shift @ARGV || die("Must specify input filename");
open(FILE,"<$file")||die("Error opening $file: $!");
my($line);
chomp($line=<FILE>);
my $n = $line;
for(my $i=0; $i<$n; ++$i) {
	my($map);
	chomp($line=<FILE>);
	my @base=split(/\s+/,$line);
	my $res = process(\@base);
        printf("Case #%d: %s\n",1+$i,$res);
}
close(FILE);
