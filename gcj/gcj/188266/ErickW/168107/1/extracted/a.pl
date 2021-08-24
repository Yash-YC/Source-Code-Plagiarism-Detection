#!/usr/bin/perl
$cases=<>; for $label (1..$cases)
{
  ($b1,@b)=split' ',<>;
  $cmd = "cat al${b1}.txt";
  for(@b) { $cmd .= "| comm -12 - al${_}.txt"; }
  $cmd .= '|head -1 | sed -e "s/^0*//"';
  print "Case #${label}: "; system($cmd);
}
