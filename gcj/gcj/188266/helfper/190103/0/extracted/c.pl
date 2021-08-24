use strict;
use warnings;

my $T = <>;

for my $X ( 1..$T )
{
   my ($C, $N) = split /\s+/, <>;
   
   my $E = ($C + $N) / $N;
   
   printf "Case #%s: %.7f\n", $X, $E;
}
