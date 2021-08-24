<?php

/**
 * actual code goes here
 */
function solve($problem)
{
	$letters = [
		65 => 'A',
		66 => 'B',
		67 => 'C',
		68 => 'D',
		69 => 'E',
		70 => 'F',
		71 => 'G',
		72 => 'H',
		73 => 'I',
		74 => 'J',
		75 => 'K',
		76 => 'L',
		77 => 'M',
		78 => 'N',
		79 => 'O',
		80 => 'P',
		81 => 'Q',
		82 => 'R',
		83 => 'S',
		84 => 'T',
		85 => 'U',
		86 => 'V',
		87 => 'W',
		88 => 'X',
		89 => 'Y',
		90 => 'Z',
	];

	$s = $problem[0];
	$s_arr = str_split($s);
	$char_arr = [];

	foreach($s_arr as $char)
	{
		$char_arr[] = ord($char);
	}

	$result = [];
	foreach($char_arr as $value)
	{
		if(empty($result)) {
			array_push($result, $value);
			continue;
		}

		if($value >= $result[0]) {
			array_unshift($result, $value);
			continue;
		}
		
		array_push($result, $value);
	}

	$output = "";
	foreach($result as $char_v)
	{
		$output .= $letters[$char_v];
	}

	return $output;
}

$input = explode(PHP_EOL,file_get_contents('in'));
if(empty($input[count($input)-1])) array_pop($input);
$output = "";
$problemCount = array_shift($input);
$linesPerProblem = 1;

for($i = 0; $i < count($input); $i = $i + $linesPerProblem)
{
	$caseNumber = ($i/$linesPerProblem)+1;
	$output .= "Case #$caseNumber: ".solve(array_slice($input,$i,$linesPerProblem))."\n";
}

file_put_contents('out', $output);