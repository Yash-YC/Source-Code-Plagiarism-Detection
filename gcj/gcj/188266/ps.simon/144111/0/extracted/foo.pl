#!/usr/bin/perl
# gcj'09 round 1a
# solution by ps@k0de.de
use strict;

sub less {
  my $a = shift;
  my $b = shift;
  if ($b < 0) {
    return 1;
  }
  if ($a < 0) {
    return 0;
  }
  return ($a < $b);
}

my $N = <>;
for my $cnum (1..$N) {
  my ($N, $M) = split / /, <>;
  my (@V,@S,@W,@T,@D);
  for my $n (1..$N) {
    my @line = split / /, <>;
    for my $m (1..$M) {
      $S[$n][$m] = shift @line;
      $W[$n][$m] = shift @line;
      $T[$n][$m] = shift(@line) % ($S[$n][$m]+$W[$n][$m]);
    }
  }
  #dijkstra
  for my $n (1..$N) {
    for my $m (1..$M) {
      for my $i (1..4) {
        $D[$n][$m][$i] = ($n==$N && $m==1 && $i == 1)?0:-1; #inf
      }
    }
  }
  for(1..12*$M*$N){
  for my $mN (1..$N) {
    for my $mM (1..$M) {
      for my $mI (1..4) {
      my $mV = $D[$mN][$mM][$mI];
      # next crossing times
      my ($n, $w);
      my $off = ($mV - $T[$mN][$mM] + $S[$mN][$mM]+$W[$mN][$mM]) % ($S[$mN][$mM]+$W[$mN][$mM]);
      if ($off < $S[$mN][$mM]) {
        $n = 1;
        $w = $S[$mN][$mM] - $off + 1;
      }
      else {
        $n = $W[$mN][$mM] + $S[$mN][$mM] - $off + 1;
        $w = 1;
      }

     #sw of a crossing
     if($mI == 1) {
      # sidewalk
      if($mN < $N && less($mV + 2, $D[$mN+1][$mM][3])) {
        $D[$mN+1][$mM][3] = $mV+2;
      }
      if($mM > 1 && less($mV + 2, $D[$mN][$mM-1][2])) {
        $D[$mN][$mM+1][2] = $mV+2;
      }

      # crossing north
      if(less($mV + $n, $D[$mN][$mM][3])) {
         $D[$mN][$mM][3] = $mV + $n;
      }
      # crossing east
      if(less($mV + $w, $D[$mN][$mM][2])){
         $D[$mN][$mM][2] = $mV + $w;
      }
     }
     #se of a crossing
     elsif($mI == 2) {
      if($mM < $M && less($mV + 2, $D[$mN][$mM+1][1])) {
        $D[$mN][$mM+1][1] = $mV+2;
      }
      if($mN < $N && less($mV + 2, $D[$mN+1][$mM][4])) {
        $D[$mN+1][$mM][4] = $mV+2;
      }
      #crossing north
      if(less($mV + $n, $D[$mN][$mM][4])) {
         $D[$mN][$mM][4] = $mV + $n;
      }
      #crossing west
      if(less($mV + $w, $D[$mN][$mM][1])){
         $D[$mN][$mM][1] = $mV + $w;
      }

     }
     elsif($mI == 3) {
      if($mN > 1 && less($mV + 2, $D[$mN-1][$mM][1])) {
        $D[$mN-1][$mM][1] = $mV+2;
      }
      if($mM > 1 && less($mV + 2, $D[$mN][$mM-1][4])) {
        $D[$mN][$mM+1][4] = $mV+2;
      }
      #crossing south
      if(less($mV + $n, $D[$mN][$mM][1])) {
         $D[$mN][$mM][1] = $mV + $n;
      }
      #crossing east
      if(less($mV + $w, $D[$mN][$mM][4])){
         $D[$mN][$mM][4] = $mV + $w;
      }
     }
     elsif($mI == 4) {
      if($mN > 1 && less($mV + 2, $D[$mN-1][$mM][2])) {
        $D[$mN-1][$mM][2] = $mV+2;
      }
      if($mM < $M && less($mV + 2, $D[$mN][$mM+1][3])) {
        $D[$mN][$mM+1][3] = $mV+2;
      }
      #crossing south
      if(less($mV + $n, $D[$mN][$mM][2])) {
         $D[$mN][$mM][2] = $mV + $n;
      }
      #crossing west
      if(less($mV + $w, $D[$mN][$mM][3])){
         $D[$mN][$mM][4] = $mV + $w;
      }
     }

  }}}}

  print "Case #$cnum: ", $D[1][$M][4], "\n";
}
