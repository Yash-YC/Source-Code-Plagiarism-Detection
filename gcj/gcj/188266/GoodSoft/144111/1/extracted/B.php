<?
	
	function calc ($time, $inter, $dir) {
		$start = floor(($time - $inter['start']) / ($inter['horizontal'] + $inter['vertical'])) * ($inter['horizontal'] + $inter['vertical']) + $inter['start'];
		if ($dir == 'vertical') {
			if ($time - $start < $inter['vertical'])
				return $time + 1;
			else
				return $start + $inter['horizontal'] + $inter['vertical'] + 1;
		}
		else {
			if ($time - $start < $inter['vertical'])
				return $start + $inter['vertical'] + 1;
			elseif ($time < $start + $inter['horizontal'] + $inter['vertical'])
				return $time + 1;
			else
				return $start + $inter['horizontal'] + $inter['vertical'] + $inter['vertical'] + 1;
		}
	}
	
	$lines = file('file.in', FILE_IGNORE_NEW_LINES);
	
	$line = 1;
	for ($c = 1; $c <= $lines[0]; $c++) {
		$intersections = $inter = array();
		$queue = array();
		list($n, $m) = explode(' ', $lines[$line++]);
		for ($i = 0; $i < $n; $i++) {
			$numbers = explode(' ', $lines[$line++]);
			for ($j = 0; $j < $m; $j++) {
				$intersections[$i][$j]['vertical'] = $numbers[$j * 3];
				$intersections[$i][$j]['horizontal'] = $numbers[$j * 3 + 1];
				$intersections[$i][$j]['start'] = $numbers[$j * 3 + 2] % ($numbers[$j * 3] + $numbers[$j * 3 + 1]) - ($numbers[$j * 3] + $numbers[$j * 3 + 1]);
				$inter[$i][$j] = array(2000000000, 2000000000, 2000000000, 2000000000);
			}
		}
		$inter[$n - 1][0][2] = 0;
		$queue[] = array($n - 1, 0, 2);
		while ($queue) {
			list($i, $j, $pos) = array_shift($queue);
			
			
			switch ($pos) {
				case 0:
					// Up
					if ($i > 0 && $inter[$i - 1][$j][2] > $inter[$i][$j][$pos] + 2) {
						$inter[$i - 1][$j][2] = $inter[$i][$j][$pos] + 2;
						$queue[] = array($i - 1, $j, 2);
					}
					
					// Left
					if ($j > 0 && $inter[$i][$j - 1][1] > $inter[$i][$j][$pos] + 2) {
						$inter[$i][$j - 1][1] = $inter[$i][$j][$pos] + 2;
						$queue[] = array($i, $j - 1, 1);
					}
					
					// Down
					$time = calc($inter[$i][$j][$pos], $intersections[$i][$j], 'vertical');
					if ($inter[$i][$j][2] > $time) {
						$inter[$i][$j][2] = $time;
						$queue[] = array($i, $j, 2);
					}
					
					// Right
					$time = calc($inter[$i][$j][$pos], $intersections[$i][$j], 'horizontal');
					if ($inter[$i][$j][1] > $time) {
						$inter[$i][$j][1] = $time;
						$queue[] = array($i, $j, 1);
					}
					
					break;
				case 1:
					// Up
					if ($i > 0 && $inter[$i - 1][$j][3] > $inter[$i][$j][$pos] + 2) {
						$inter[$i - 1][$j][3] = $inter[$i][$j][$pos] + 2;
						$queue[] = array($i - 1, $j, 3);
					}
					
					// Right
					if ($j < $m - 1 && $inter[$i][$j + 1][0] > $inter[$i][$j][$pos] + 2) {
						$inter[$i][$j + 1][0] = $inter[$i][$j][$pos] + 2;
						$queue[] = array($i, $j + 1, 0);
					}
					
					// Down
					$time = calc($inter[$i][$j][$pos], $intersections[$i][$j], 'vertical');
					if ($inter[$i][$j][3] > $time) {
						$inter[$i][$j][3] = $time;
						$queue[] = array($i, $j, 3);
					}
					
					// Left
					$time = calc($inter[$i][$j][$pos], $intersections[$i][$j], 'horizontal');
					if ($inter[$i][$j][0] > $time) {
						$inter[$i][$j][0] = $time;
						$queue[] = array($i, $j, 0);
					}
					
					break;
				case 2:
					// Dpwn
					if ($i < $n - 1 && $inter[$i + 1][$j][0] > $inter[$i][$j][$pos] + 2) {
						$inter[$i + 1][$j][0] = $inter[$i][$j][$pos] + 2;
						$queue[] = array($i + 1, $j, 0);
					}
					
					// Left
					if ($j > 0 && $inter[$i][$j - 1][3] > $inter[$i][$j][$pos] + 2) {
						$inter[$i][$j - 1][3] = $inter[$i][$j][$pos] + 2;
						$queue[] = array($i, $j - 1, 3);
					}
					
					
					// Up
					$time = calc($inter[$i][$j][$pos], $intersections[$i][$j], 'vertical');
					if ($inter[$i][$j][0] > $time) {
						$inter[$i][$j][0] = $time;
						$queue[] = array($i, $j, 0);
					}
					
					// Right
					$time = calc($inter[$i][$j][$pos], $intersections[$i][$j], 'horizontal');
					if ($inter[$i][$j][3] > $time) {
						$inter[$i][$j][3] = $time;
						$queue[] = array($i, $j, 3);
					}
					break;
				case 3:
					// Down
					if ($i < $n - 1 && $inter[$i + 1][$j][1] > $inter[$i][$j][$pos] + 2) {
						$inter[$i + 1][$j][1] = $inter[$i][$j][$pos] + 2;
						$queue[] = array($i + 1, $j, 1);
					}
					
					// Right
					if ($j < $m - 1 && $inter[$i][$j + 1][2] > $inter[$i][$j][$pos] + 2) {
						$inter[$i][$j + 1][2] = $inter[$i][$j][$pos] + 2;
						$queue[] = array($i, $j + 1, 2);
					}
					
					
					// Up
					$time = calc($inter[$i][$j][$pos], $intersections[$i][$j], 'vertical');
					if ($inter[$i][$j][1] > $time) {
						$inter[$i][$j][1] = $time;
						$queue[] = array($i, $j, 1);
					}
					
					// Left
					$time = calc($inter[$i][$j][$pos], $intersections[$i][$j], 'horizontal');
					if ($inter[$i][$j][2] > $time) {
						$inter[$i][$j][2] = $time;
						$queue[] = array($i, $j, 2);
					}
					break;
			}
			
		}
		echo "Case #$c: ".$inter[0][$m - 1][1]."\n";
	}
	
	
?>