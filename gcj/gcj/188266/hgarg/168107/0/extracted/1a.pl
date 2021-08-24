use strict;
use POSIX;
my $T = <STDIN>;
chomp($T);
for (my $i = 1; $i <= $T; $i++)
{
	my $in = <STDIN>;
	chomp ($in);
	my @bases = split (/\s+/, $in);

	N: for (my $n = 2; ; $n++)	
	{
		#warn "Trying $n\n";
		foreach my $b (@bases)
		{
			my %seen;	
			my @digits = to_base($n, $b);
			while ($#digits != 0 || $digits[0] != 1)
			{
				my $sum_10 = 0;
				foreach my $digit (@digits)
				{
					$sum_10 += $digit*$digit;	
				}
				#warn @digits, "Summed to $sum_10";
 				@digits = to_base($sum_10, $b);

				if ($seen{$sum_10})
				{
					#warn "Skipping $n";
					next N;
				}
				else
				{
					$seen{$sum_10} = 1;
				}
			}
		}
		print "Case #$i: $n\n";
		last;
	}
}
sub to_base
{
	my ($n, $b) = @_;
	
	my @digits;
	while ($n >= $b)
	{
		push @digits, $n%$b;	
		$n = POSIX::floor($n/$b);
	}
	push @digits, $n;
	return reverse @digits;
}
