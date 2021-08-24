# Common part begin

use strict;
use Getopt::Std;

getopts("v");
my $verbose = $::opt_v;

sub log {
	print STDERR "| ", @_, "\n" if $verbose;
}

sub readline {
	$_ = <>;
	chomp;
	$_;
}

my $num_of_problems = &readline;

for my $problem_index (1..$num_of_problems) {
	my $output = &solve;
	print "Case #${problem_index}: $output\n";
}

# Common part end

use List::Util qw[min max];
# use bigint;

sub solve {
	my @bases = split(/ /, &readline);
	my $i = 2;
	while (1) {
		my $is_all_happy = 1;
		for my $b (@bases) {
			if (is_happy($i, $b)) {
				next;
			} else {
				$is_all_happy = 0;
				last;
			}
		}
		return $i if $is_all_happy;
		$i++;
	}
}

sub is_happy {
	my $n = shift;
	my $b = shift;
	
	my %occurrence = ( 0 => 1, 1 => 1 );
	while (!$occurrence{$n}) {
		$occurrence{$n} = 1;
		
		my $p = 0;
		while ($n > 0) {
			my $k = $n % $b;
			$p += $k * $k;
			$n = ($n - $k) / $b;
		}
		$n = $p;
	}
	
	$n == 1;
}
