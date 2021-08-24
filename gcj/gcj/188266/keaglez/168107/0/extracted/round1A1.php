<?php
function is_happy($n)
{
	if ($n == 1)
		return true;
	$l = strlen($n);
	if ($n == pow(10, $l-1))
		return true;
	return false;
}

function find_happy($n, $base)
{
	$arr = array(1);
	$a = 0;
	while (true)
	{
		$c = 0;
		$spl = str_split($n);
		foreach ($spl as $s)
		{
			$b = base_convert($s, $base, 10);
			$c += pow($b, 2);
		}
		//echo "$n -> $c\n";
		$c = base_convert($c, 10, $base);
		if (is_happy($c))
			return true;
		$n = $c;
		if (in_array($c, $arr))
			break;
		$arr[] = $c;
		$a++;
		if ($a > 100)
			break;
	}
	return false;
}

function get_happy($a, $base)
{
	$n = base_convert($a, 10, $base);
	while (! find_happy($n, $base))
	{
		//echo "^ is $n a happy in this base $base?\n";
		$a++;
		$n = base_convert($a, 10, $base);
	}
	return $a;
}

function get_all_happy($a, $base_arr)
{
	while (true)
	{
		foreach ($base_arr as $base)
		{
			$n = base_convert($a, 10, $base);
			$status = true;
			$status = find_happy($n, $base);
			if (! $status)
				break;
		}
		if ($status)
			break;
		$a++;
	}
	return $a;
}

$file = "A-small-attempt0.in";
$content = file_get_contents("case/$file");
$line = explode("\n", $content);

$out = "";

$testcase_num = $line[0];
for ($l = 1; $l <= $testcase_num; $l++)
{
	$case_arr = explode(" ", $line[$l]);
	$result = get_all_happy(2, $case_arr);
	$out .= "Case #{$l}: $result\n";
}

$file_out = str_replace("in", "out", $file);
file_put_contents("case/$file_out", $out);
?>
