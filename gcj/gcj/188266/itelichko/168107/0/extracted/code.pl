#!/usr/bin/perl -w
<>; my $TN = 0; while(<>) {my @BASES=split;
	sub dec2base { my ($d,$b)=@_;#!@#
		my @D; while ($d) {
			my $r = $d % $b;
			$d = ($d-$r)/$b;
			push @D , $r;
		} return @D
	}##@!

	my $R = 2; while(1) { my %happy; for my $b (@BASES) { my %loopguard;
		my @D = dec2base($R,$b); do {
			$loopguard{join(":",@D)} = 1;
			my $S = 0; for (@D) { $S += $_*$_ }
			@D = dec2base($S,$b);
		} while (@D > 1 or $D[0] != 1) and not $loopguard{join(":",@D)};

		$happy{$b} = (@D == 1 and $D[0] == 1) ? "y" : "n";
	} last if not grep {$_ eq "n"} values %happy; $R++ }
	printf "Case #%d: %s\n", ++$TN, $R;
}
