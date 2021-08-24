require 5.008;
package main;

sub filename_in{
  unless (defined($TYPE)){ print '$TYPE is not defined.'; exit 1; }
  unless (defined($PROBLEM)){ print '$PROBLEM is not defined.'; exit 1; }
  my $i = 0;

  if($TYPE eq 'small'){
    for(my $i=10; $i>=0; $i--) {
      if(-f "$PROBLEM-small-attempt$i.in"){
        return "$PROBLEM-small-attempt$i.in";
      }
    }
  }elsif($TYPE eq 'large'){
    if(-f "$PROBLEM-large.in"){
      return "$PROBLEM-large.in";
    }
  }
  print 'Invalid $TYPE, or Input file not found.'; exit 1;
}

sub filename_out{
  unless(defined($TYPE)){ print '$TYPE is not defined.'; exit 1; }
  unless(defined($PROBLEM)){ print '$PROBLEM is not defined.'; exit 1; }

  if($TYPE eq 'small' or $TYPE eq 'large'){
    return "$PROBLEM-${TYPE}_result.txt";
  }
  print 'Invalid $TYPE.'; exit 1;
}

our $PI = 3.141592653589793238;

sub max{
  my $m = shift;
  foreach(@_){ if($m<$_){$m=$_;} }
  return $m;
}

sub min{
  my $m = shift;
  foreach(@_){ if($m>$_){$m=$_;} }
  return $m;
}

sub has_same{
  my $n = @_;
  for (my $i=0; $i<$n-1; $i++) {
    for (my $j=$i+1; $j<$n; $j++) {
      return 1 if $_[$i] == $_[$j];
    }
  }
  return 0;
}

sub sum{
  my $s = 0;
  $s += $_ foreach @_;
  return $s;
}

sub dis2{
  my $s = 0;
  $s += $_*$_ foreach @_;
  return $s;
}

sub avg{
  return sum(@_) / @_;
}

1;
