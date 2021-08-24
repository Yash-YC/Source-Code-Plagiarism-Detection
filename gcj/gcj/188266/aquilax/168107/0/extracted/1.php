<?php

  function is_happy($num, $base, $level){
    //echo 'Rec'.$level.'  '. $num."\n";
    if ($num == 0) return FALSE;
    if ($level > 15) return FALSE;
    $sum = 0;
    $ary = str_split($num);
    foreach($ary as $s){
      $sum += base_convert($s, $base, 10)*base_convert($s, $base, 10);
    }
    if ($sum == 1){
      return TRUE;
    } else {
      return is_happy(base_convert($sum, 10, $base), $base, ++$level);
    }
  }

  $file_in = '1.in';
  $file_out = '1.out';
  $text = file_get_contents($file_in);
  $ary = split("\n", $text);
  $harry = array();
  unset($ary[0]);
  $case = 1;
  $out = '';
  foreach ($ary as $row){
    if ($row == ''){
      continue;
    }
    echo $row;
    $nums = split(' ', $row);
    $hfa = FALSE;
    $base = $nums[0];
    unset($nums[0]);
    $num = 1;
    do {
      $num++;
      $tnum = base_convert($num, 10, $base);
      if (is_happy($tnum, $base, 0)){
        $hfa = TRUE;
        foreach($nums as $ibase){
          $tnum = base_convert($num, 10, $ibase);
          if (!is_happy($tnum, $ibase, 0)){
            $hfa = FALSE;
            continue;
          } else {
            echo '.';
          }
        }
      } else {
        $hfa = FALSE;
      }
    } while (!$hfa);
    echo '|';
    $out .= sprintf("Case #%d: %d\n", $case, $num);
    $case++;
  }
  file_put_contents($file_out, $out);
?>
