<?php

	function toX($x)
	{
		$v = 0;
		while ($x > 0)
		{
			$d = ($x % 10);
			$x = intval($x / 10);

			$v += $d * $d;
		}
		return $v;
	}

	function is_ok($x, $base)
	{
		$array = array();
		$array[1] = 1;
						
		while (!isset($array[$x]))
		{
			$array[$x] = 1;

			$x = base_convert($x, 10, $base);
			$x = intval(toX($x));
		}
		
		return ($x == 1);
	}	


function search($base_list)
{
	$j = 2;
	while (1)
	{
		$flag = 1;
		foreach ($base_list as $base)
		{
			if (is_ok($j, $base) == 0)
			{
				$flag = 0;
				break;
			}
		}
		
		if ($flag == 1)
		{
			return $j;
		}
		$j++;
	}	
}

$fin = fopen("A-small-attempt0.in", "r");
$line = fgets($fin);

$num_test = intval($line);
for ($t = 1; $t <= $num_test; $t++)
{
	$line = fgets($fin);
	$base_list = explode(' ', $line);

	$r = search($base_list);
	echo "Case #$t: $r\n";
}



