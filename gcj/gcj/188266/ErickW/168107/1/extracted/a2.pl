#!/usr/bin/perl
open(IN,'<','a.out'); @L=<IN>;
@A=(3,5,6,7,8,9,10);
@V{@A}=(1,2,4,8,16,32,64);

$cases=<>; for $label (1..$cases)
{
  @b=split' ',<>; @b=grep{$_!=2 and $_!=4}@b;
  $x=0; for(@b) { $x+=$V{$_}; }
  print "Case #${label}: ",$L[$x];
}
