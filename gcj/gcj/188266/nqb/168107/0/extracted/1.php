<?php

$test = "1";

$file_in = "1/$test.in";
$file_out = "1/$test.out";

$in = fopen($file_in,"r");
$out = fopen($file_out,"wb");

$num_tests = fgets($in);

for ($t = 0;$t < $num_tests;$t++)
{
	$line = fgets($in);
	$nums = explode(" ",$line);
	
	sort($nums);
	
	$find_num = 2;
	
	while (true)
	{
		$all_happy = true;
		
		foreach ($nums as $num)
		{
			$all_happy = is_happy($find_num,$num);
			
			if (!$all_happy) break;
		}
		
		if ($all_happy) break;
	
		// @opt
		$find_num++;
	}
	
	$t_out = "Case #" . ($t+1) . ": "  . $find_num . "\n";
	
	fwrite($out,$t_out);
}

function is_happy($num,$base,$tracks=array())
{
	$num2 = base_convert($num,10,$base);

	$new = 0;
	
	for ($i = 0;$i < strlen($num2);$i++)
	{
		$new += $num2[$i] * $num2[$i];
	}
	
	if ($new != 1)
	{
		if (in_array($new,$tracks)) return false;
		$tracks[] = $new;
	
		return is_happy($new,$base,$tracks);
	}
	
	return true;
}