<?php

$f = fopen("A.in", "r");
$o = fopen("A.out", "w");

fscanf($f, "%d\n", &$T);

for ($a = 0; $a < $T; ++$a) {
	
	$bases = fgets($f);
	$base = explode(" ", $bases);
	
	for ($c = 2; true; ++$c) {
		$happies = 0;
		for ($b = 0; $b < count($base); ++$b) {
			$n = base_convert($c, 10, $base[$b]);
			$t = 0;
			$happy = false;
			while ($t < 50) {
				$sum = 0;
				for ($d = 0; $d < strlen($n); ++$d) {
					$bit = substr($n, $d, 1);
					$sum += $bit * $bit;
				}
					$sum = base_convert($sum, 10, $base[$b]);
				if ($sum == 1) {
					$happy = true;
					break;
				} else {
					$n = $sum;
				}
				
				++$t;
			}
			if ($happy) {
				++$happies;
			} else {
				break;
			}
		}
		if ($happies == count($base)) {
			break;
		}
	}
	
	fprintf($o, "Case #%d: %d\n", $a + 1, $c);
}

fclose($f); fclose($o);

?>
