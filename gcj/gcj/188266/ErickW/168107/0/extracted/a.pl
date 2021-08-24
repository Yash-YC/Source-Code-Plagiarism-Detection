#!/usr/bin/perl
$cases=<>; for $label (1..$cases)
{
  ($b1,$b2,@b)=split' ',<>;
  $cmd = "join a${b1}.txt a${b2}.txt";
  for(@b) { $cmd .= "| join - a${_}.txt"; }
  $cmd .= '|head -1 | sed -e "s/^0*//"';
  print "Case #${label}: "; system($cmd);
}
