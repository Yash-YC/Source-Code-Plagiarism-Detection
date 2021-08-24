use strict;
use warnings;
use Data::Dump qw/dump/;

my @happies;

my @data = <STDIN>;
#my @data = <DATA>;
my $case_count = shift @data;

for (my $case = 1; $case <= $case_count; $case++) {
	my @bases = split(' ', shift @data);
	my $num = 2;
	loop:
	while (1) {
		#print "num: $num\n";
		foreach my $base (@bases) {
			#print "\tbase: $base\n";
			my %seen = ();
			my $cand= $num;
			while (1) {
				$seen{$cand} = 1;
				if (exists($happies[$base][$cand])) {
					foreach my $seen (keys %seen) {
						$happies[$base][$seen] = $happies[$base][$cand];
					}
					if ($happies[$base][$num] == 0) {
						$num++;
						goto loop;
					}
					else {
						last;
					}
				}
				my $result = check($cand, $base);
				if ($result == 1) {
					foreach my $seen (keys %seen) {
						$happies[$base][$seen] = 1;
					}
					last;
				}
				if (exists($seen{$result})) {
					# infinite loop
					foreach my $seen (keys %seen) {
						$happies[$base][$seen] = 0;
					}
					$num++;
					next loop;
				}
				$cand = $result;
			}
		}
		last;
	}
	print "Case #$case: $num\n";
}

sub check {
	my ($num, $base) = @_;
	my $result = 0;
	while ($num) {
		my $rest = $num % $base;
		$result += $rest ** 2;
		$num /= $base;
	}
	return $result;
}
		
__DATA__
42
7 10
6 7 8
2 4 7
4 7 9
2 10
6 7 9
7 8 9
2 3 8
3 10
4 7
8 10
3 4
3 6 10
3 4 7
6 9
2 5 10
7 9 10
3 6 8
2 8 9
2 7 8
2 5 6
2 6 9
2 4 9
4 5 8
2 3 5
4 7 10
3 7 10
2 4 6
3 6
3 6 9
4 9
4 8 9
3 8 10
4 5 6
2 6
5 8
3 4 6
6 10
2 4 8
2 8 10
7 8 10
5 6 10
