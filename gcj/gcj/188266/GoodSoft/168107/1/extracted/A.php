<?
	
	error_reporting(E_ALL ^ E_NOTICE);
	
	/* GENERATOR
	
	function happy($number, $base) {
		$seen = array();
		
		while ($number != 1 && !$seen[$number]) {
			$newnum = 0;
			$seen[$number] = 1;
			while ($number) {
				$newnum += ($number % $base) * ($number % $base);
				$number = floor($number / $base);
			}
			$number = $newnum;
		}
		return $number == 1;
	}
	
	$ok = array();
	for ($number = 2; ; $number++) {
		$happy = array();
		for ($base = 2; $base <= 10; $base++) {
			if (happy($number, $base))
				$happy[] = $base;
		}
		if ($happy) {
			if (!$ok[implode(', ', $happy)]) {
				$ok[implode(', ', $happy)] = $number;
				echo "$number: ".implode(', ', $happy)."\n";
			}
		}
	}*/
	
	$data = '
			2: 2, 4
			3: 2, 3, 4, 9
			5: 2, 4, 5
			6: 2, 4, 6
			7: 2, 4, 5, 7, 10
			8: 2, 4, 8
			10: 2, 4, 10
			13: 2, 3, 4, 10
			17: 2, 3, 4
			19: 2, 4, 5, 10
			23: 2, 3, 4, 5, 10
			25: 2, 3, 4, 5
			27: 2, 3, 4, 5, 8, 9
			44: 2, 4, 6, 10
			49: 2, 4, 5, 6, 7, 10
			77: 2, 3, 4, 8
			79: 2, 3, 4, 5, 6, 10
			81: 2, 3, 4, 5, 9
			91: 2, 3, 4, 5, 9, 10
			95: 2, 4, 5, 9
			97: 2, 4, 8, 10
			125: 2, 4, 5, 7, 9
			143: 2, 3, 4, 5, 7, 9
			167: 2, 3, 4, 7, 10
			191: 2, 3, 4, 7
			216: 2, 4, 6, 8
			219: 2, 3, 4, 5, 8, 10
			229: 2, 4, 5, 6
			309: 2, 4, 5, 8
			311: 2, 4, 7
			385: 2, 4, 9
			397: 2, 4, 9, 10
			401: 2, 4, 5, 7
			415: 2, 4, 5, 6, 9
			469: 2, 4, 5, 6, 10
			533: 2, 3, 4, 5, 6
			545: 2, 3, 4, 5, 8
			553: 2, 4, 8, 9
			608: 2, 4, 6, 8, 10
			623: 2, 3, 4, 8, 10
			695: 2, 3, 4, 6
			707: 2, 3, 4, 6, 9
			713: 2, 3, 4, 5, 7
			739: 2, 3, 4, 9, 10
			1001: 2, 4, 5, 7, 8
			1009: 2, 4, 5, 9, 10
			1033: 2, 4, 6, 9, 10
			1135: 2, 4, 6, 9
			1177: 2, 3, 4, 5, 8, 9, 10
			1277: 2, 3, 4, 6, 10
			1337: 2, 3, 4, 7, 9, 10
			1695: 2, 3, 4, 5, 6, 9
			1975: 2, 4, 5, 6, 8
			2159: 2, 3, 4, 7, 9
			2207: 2, 3, 4, 5, 6, 7
			2455: 2, 4, 5, 8, 10
			2753: 2, 4, 6, 7, 9
			2807: 2, 4, 6, 7
			2893: 2, 4, 5, 8, 9
			3137: 2, 4, 7, 9, 10
			3487: 2, 3, 4, 8, 9
			3879: 2, 3, 4, 5, 6, 8, 10
			4137: 2, 3, 4, 5, 6, 8
			4417: 2, 4, 5, 8, 9, 10
			4557: 2, 3, 4, 6, 8
			4577: 2, 4, 5, 6, 9, 10
			4859: 2, 3, 4, 6, 7
			4977: 2, 4, 5, 6, 8, 9
			5527: 2, 4, 6, 7, 10
			5719: 2, 3, 4, 5, 7, 8
			6073: 2, 3, 4, 5, 6, 9, 10
			6211: 2, 4, 7, 8
			6307: 2, 3, 4, 6, 7, 10
			6351: 2, 3, 4, 7, 8
			6393: 2, 4, 5, 7, 8, 9
			7307: 2, 4, 5, 6, 7
			7895: 2, 3, 4, 5, 6, 7, 10
			7961: 2, 4, 8, 9, 10
			8787: 2, 4, 7, 10
			9721: 2, 4, 7, 9
			9867: 2, 4, 6, 8, 9, 10
			10089: 2, 3, 4, 6, 8, 9
			10309: 2, 3, 4, 5, 7, 10
			12085: 2, 3, 4, 8, 9, 10
			12399: 2, 3, 4, 6, 9, 10
			23117: 2, 3, 4, 5, 6, 8, 9
			24855: 2, 4, 7, 8, 9
			28099: 2, 3, 4, 5, 6, 8, 9, 10
			29627: 2, 4, 6, 8, 9
			29913: 2, 4, 5, 7, 9, 10
			34527: 2, 4, 5, 7, 8, 10
			35785: 2, 3, 4, 7, 8, 9
			37079: 2, 3, 4, 6, 8, 10
			37131: 2, 3, 4, 5, 6, 7, 9
			40285: 2, 4, 5, 6, 8, 10
			43465: 2, 4, 5, 6, 7, 9
			44265: 2, 4, 7, 8, 10
			47089: 2, 3, 4, 6, 7, 8
			47775: 2, 3, 4, 6, 8, 9, 10
			48041: 2, 3, 4, 7, 8, 9, 10
			48769: 2, 4, 5, 6, 7, 8
			51909: 2, 3, 4, 7, 8, 10
			58775: 2, 3, 4, 5, 6, 7, 8
			68091: 2, 3, 4, 6, 7, 9
			71735: 2, 4, 6, 7, 9, 10
			108161: 2, 4, 5, 6, 8, 9, 10
			120149: 2, 3, 4, 5, 7, 9, 10
			120407: 2, 3, 4, 5, 7, 8, 10
			120785: 2, 4, 6, 7, 8
			128821: 2, 3, 4, 5, 7, 8, 9
			142901: 2, 4, 7, 8, 9, 10
			218301: 2, 4, 5, 6, 7, 9, 10
			245035: 2, 4, 5, 6, 7, 8, 10
			246297: 2, 4, 5, 7, 8, 9, 10
			285357: 2, 4, 6, 7, 8, 10
			346719: 2, 3, 4, 5, 7, 8, 9, 10
			569669: 2, 3, 4, 5, 6, 7, 8, 9
			613479: 2, 3, 4, 6, 7, 9, 10
			662619: 2, 3, 4, 6, 7, 8, 9
			697563: 2, 3, 4, 6, 7, 8, 10
			710761: 2, 4, 6, 7, 8, 9
			711725: 2, 3, 4, 5, 6, 7, 9, 10
			1026657: 2, 4, 5, 6, 7, 8, 9
			2662657: 2, 4, 6, 7, 8, 9, 10
			2688153: 2, 3, 4, 5, 6, 7, 8, 10
			4817803: 2, 3, 4, 6, 7, 8, 9, 10
			11814485: 2, 3, 4, 5, 6, 7, 8, 9, 10

	';
	
	$data = explode("\n", $data);
	foreach ($data as $line) {
		$line = trim($line);
		list($number, $line) = explode(':', $line);
		$line = trim($line);
		$bases = explode(', ', $line);
		$numbers[$number] = $bases;
	}
	
	
	$lines = file('file.in', FILE_IGNORE_NEW_LINES);
	
	for ($i = 1; $i <= (int)$lines[0]; $i++) {
		$bases = explode(' ', $lines[$i]);
		foreach ($numbers as $number => $hasbases) {
			$ok = TRUE;
			foreach ($bases as $base)
				$ok = $ok && in_array($base, $hasbases);
			if ($ok) {
				echo "Case #$i: $number\n";
				break;
			}
		}
	}
	
	
?>