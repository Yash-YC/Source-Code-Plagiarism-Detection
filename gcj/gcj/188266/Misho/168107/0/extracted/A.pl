#!/usr/bin/perl
use strict;
use warnings;
use tools;

our $PROBLEM = 'A';

our $TYPE = 'small';
#our $TYPE = 'large';

our $array;

print "---\nINPUT FILE:  ".filename_in()."\nOUTPUT FILE: ".filename_out()."\n---\n";

open(IN,filename_in());
open(OUT,">".filename_out());

my $cases = <IN>;

for (my $n=0; $n<$cases; $n++) {
  my $list = <IN>;
  my @bases = split(" ",$list);
  my $num;
  for($num=2; ;$num++){
    my $flag = 1;
    foreach my $d(@bases){
      if(calc($num,$d)!=1){$flag = 0;}
    }
    last if $flag;
  }
  print "Case #",$n+1,": $num\n";
  print OUT "Case #",$n+1,": $num\n";
}

close(IN);
close(OUT);

exit 0;

sub calc{
  my $num  = shift;
  my $base = shift;

  if (defined($array->[$num][$base])){
    return $array->[$num][$base];
  }

  my $org = $num;
  my %tmp;
  while(-1){
    if($num == 1 || (defined($tmp{$num}))){
      last;
    }
    $tmp{$num} = 1;
    $num = step($num,$base);
  }
  foreach(keys %tmp){
    $array->[$_][$base] = $num==1 ? 1 : 0;
  }
  return $array -> [$org][$base];
}

sub step{
  my $nm   = shift;
  my $base = shift;

  my $ret  = 0;
  while($nm > 0){
    my $i    = $nm % $base;
    $nm = ($nm-$i) / $base;
    $ret += $i*$i;
  }
  $ret += $nm*$nm;
  return $ret;
}

