<?php

require "Scanner.class.php";

$s = new Scanner(file_get_contents('inputb.txt'));

set_time_limit(60*7);

$f = fopen('output.out','w');
$cases = $s->nextInt();

for($i=0;$i<$cases;$i++){

  $cards = $s->nextInt();
  $per_pack = $s->nextInt();

  // Lol guessing.
  $ans = round(($cards/$per_pack)+1,7);

  echo "Case #".($i+1).": ".$ans."<br />\n";
  fwrite($f,"Case #".($i+1).": ".$ans."\n");
  flush();
}
fclose($f);

function isHappy($num,$base=10){
  $tried = array();
  $num = _base_convert($num,10,$base);
  do {
    $tried[$num] = 1;
    $num = str_split($num);
    $n = "0";
    for($i=0,$l=count($num);$i<$l;$i++){
      $n = bcadd($n,bcmul($num[$i],$num[$i]));
    }
    $num = _base_convert($n,10,$base);
  } while(!isset($tried[$num]) && bccomp($num,"1") != 0);
  return (bccomp($num,"1") == 0);
}

function _base_convert($numstring, $frombase, $tobase) {

   $chars = "0123456789abcdefghijklmnopqrstuvwxyz";
   $tostring = substr($chars, 0, $tobase);

   $length = strlen($numstring);
   $result = '';
   for ($i = 0; $i < $length; $i++) {
       $number[$i] = strpos($chars, $numstring{$i});
   }
   do {
       $divide = 0;
       $newlen = 0;
       for ($i = 0; $i < $length; $i++) {
           $divide = $divide * $frombase + $number[$i];
           if ($divide >= $tobase) {
               $number[$newlen++] = (int)($divide / $tobase);
               $divide = $divide % $tobase;
           } elseif ($newlen > 0) {
               $number[$newlen++] = 0;
           }
       }
       $length = $newlen;
       $result = $tostring{$divide} . $result;
   }
   while ($newlen != 0);
   return $result;
}

?>