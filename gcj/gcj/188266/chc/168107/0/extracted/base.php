<?php

$b = array();
$l = array(0,1,4,9,16,25,36,49,64,81);
function get_value($number, $base)
{
  global $l;
  global $b;

  if (isset($b[$base][$number])) {
     if ($b[$base][$number] === true)
       return true;
     else
       return false;
  }

  $b[$base][$number] = false;

  $value = base_convert($number, 10, $base) ;

  // if ($value < $base)
  //   return false;

  $len = strlen($value);
  $n = 0;
  for ($i=0;$i<$len; $i++) {
    $n+=$l[$value[$i]];
  }

  if ($n == 1) {
    $b[$base][$number] = true;
    return true;
  }

  $b[$base][$number] = get_value($n, $base);
  return($b[$base][$number]);
}

/*
var_dump(get_value(143, 2));
var_dump(get_value(143, 7));
*/

if ($argc !=2)
  exit;

$fp = fopen($argv[1], "r");

$buf = fgets($fp);
$N = rtrim($buf);
for ($i=1; $i<=$N; $i++)
{
  $buf = rtrim(fgets($fp));
  $c = explode(' ', $buf);
  for ($j=2; $j<10000000; $j++)
  {
    $f=0;
    foreach ($c as $base) {
      if ($base ==2 || $base ==4) {
        $f=1; continue;
      }
      if (get_value($j, $base) == false) {
        $f=0;
        break;
      }
      $f=1;
    }
    if ($f==1) {
       printf("Case #%d: %d\n", $i, $j);
       break;
    }
  }
}

?>
