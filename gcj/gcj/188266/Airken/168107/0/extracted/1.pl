#!/usr/bin/perl -w
use Data::Dumper;

sub is_happy_num
{
	my ($base, $num) = @_;

	$a = $num;
	$b = $sum = 0;
	@remainder = ();


	while ($sum != 1)
	{
		$sum = 0;
		$num = $a;
		while ($a != 0)
		{
			$b = $a % $base;
			$a = int($a / $base);

			$sum += $b * $b;
		}
		#print $base.": sum: ".$sum."\n";
		if ($sum == 1)
		{
			return 1;
		}

		if(grep $_ eq $sum, @remainder)
		{
			#print Dumper(@remainder);
			return 0;
		}
		else
		{
			push @remainder, $sum;
		}

		$a = $sum;
	}


	return ($sum == 1) ? 1 : 0;
}

my $T = <STDIN>;
$case_no = 0;

while (++$case_no <= $T)
{
	$lines = <STDIN>;
	chomp $lines;
	@bases = split(" ", $lines);

	$i = 2;

	while(1)
	{
		$found = 1;
		foreach (@bases)
		{
			$res = &is_happy_num($_, $i);

			if ($res == 0 )
			{
				$found = 0;
				last;
			}
		}

		if($found)
		{
			last;
		}

		$i++;
	}

	print "Case #".$case_no.": ".$i."\n";
}


