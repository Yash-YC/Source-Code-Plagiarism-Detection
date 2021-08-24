<?
	
	$lines = file('file.in', FILE_IGNORE_NEW_LINES);
	
	for ($case = 1; $case <= $lines[0]; $case++) {
	
		$i = 0;
		$a = 2;
		list ($n, $c) = explode(' ', $lines[$case]);
		$x = $n;
		
		if ($n == 1 && $c == 1)
			echo "Case #$case: 1\n";
		else {
			while (TRUE) {
				$oldi = $i;
				$i += $c * $a / $x;
				$a++;
				$x *= $n;
				if (abs($i - $oldi) < 0.000001)
					break;
			}
			
			echo "Case #$case: $i\n";
		}
	}