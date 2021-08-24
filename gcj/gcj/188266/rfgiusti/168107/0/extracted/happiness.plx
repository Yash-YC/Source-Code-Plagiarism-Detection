#!/usr/bin/perl

# Google Code Jam 2009
# Round 1A
# Problem A: Multi-base happiness

use strict;

use Math::BaseCalc;

sub ishappy {
	my $num = shift;
	my $base = shift;
	my $converter = shift;

	my %explored;
	$explored{$num} = 1;
	while ($num != 1) {
		my @converted = split //, $converter->to_base($num);
		$num = 0;
		for my $digit (@converted) {
			my $bdigit = $digit * $digit;
			$num += ($bdigit % $base) + $base * int($bdigit / $base);
		}
		return 0 if defined $explored{$num};
		$explored{$num} = 1;
	}

	return 1;
}

my $numcases;
$numcases = <>;
chomp $numcases;
for my $case (1 .. $numcases) {

	my $bases = <>;
	chomp $bases;
	my @bases = split / /, $bases;

	my $num = 1;
	my $isreallyhappy;
	do {
		$num++;
		$isreallyhappy = 1;
		#print "Testing $num for bases " . join(", ", @bases) . "...";
		outer: for my $base (@bases) {
			unless (ishappy($num, $base, new Math::BaseCalc(digits => [0 .. $base - 1]))) {
				#print " fail in base $base\n";
				$isreallyhappy = 0;
				last outer;
			}
		}
	} while (!$isreallyhappy);

	print "Case #$case: $num\n";
}
