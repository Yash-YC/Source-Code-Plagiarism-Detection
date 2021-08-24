use Math::BaseCalc;
use Memoize;
use Algorithm::Combinatorics qw(variations);
use List::Util qw(sum);


my @base;
for(2..10) {
  $base[$_] = new Math::BaseCalc(digits=>[0..$_-1]);
}

my @data = (2,3,4,5,6,7,8,9,10);

memoize("is_happy");

for(2..9) {
#for(2,3) {
  for my $var (variations(\@data, $_)) {
    my $n = 1;
    out: while(1) {
      $n++;
      for(@$var) {
        if(!is_happy($n, $_)) {
          next out;
        }
      }
      last;
    }
    print "\$sol{\"";
    print join  "-", sort @$var;
    print "\"} = ",$n,";\n";
  }
}


sub is_happy {
  my $next = shift;
  my $base = $base[shift()];
  my %seen;
  $seen{$next} = 1;
  while($next != 1) {
    $next = sum map {$_*$_} split //, $base->to_base($next);
    return 0 if ($seen{$next});
    $seen{$next} = 1;
  }
  return 1;
}
