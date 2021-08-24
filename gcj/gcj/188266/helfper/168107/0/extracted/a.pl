use strict;
use warnings;

my $T = <>;
my %path;

for my $X ( 1..$T )
{
   my @bases = split /\s+/, <>;
   
   my $K = 2;
   while ( 1 )
   {
      my $ok = 1;
      for ( @bases )
      {
         %path = ();
         unless ( happy($_, convert($_, $K)) )
         {
            $ok = 0;
            last;
         }
      }
      
      last if $ok;
      
      $K++;
   }
   
   print "Case #$X: $K\n";
}

sub happy
{
   my ($base, $N) = @_;

   return 1 if $N == 1;
   
   return 0 if $path{$N};
   $path{$N} = 1;
   
   my $a = 0;
   $a += $_ * $_ for split //, $N;
   
   return happy($base, convert($base, $a));
}

sub convert
{
   my ($base, $number) = @_;
   
   my $result = "";
   while ( $number > 0 )
   {
      $result = ($number % $base) . $result;
      $number = int($number / $base);
   }
   
   return $result;
}
