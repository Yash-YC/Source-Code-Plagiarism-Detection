<?php
/* if you have any questions please email me : gib at pganet dot com */
header("Content-type: text/plain");
chdir(dirname($_SERVER['SCRIPT_FILENAME']));
error_reporting(E_ALL ^ E_NOTICE);
set_time_limit(300);
define("DEBUG",0);
define("OB",1);

if (!($fp = @fopen("input.txt","r"))) die ("nincs input.txt");

if (OB) ob_start();

$T = fgets($fp,65555);
pr("\nT=".$T);


for ($T_count=0;$T_count<$T;$T_count++)
{
	if ($T_count>0) echo "\n";
	echo "Case #".($T_count+1).":";
	/// /// /// /// /// /// /// /// CODE STARTS HERE/// /// /// /// /// /// /// /// /// /// 

		$bases = explode(" ",trim(fgets($fp,6555555)));
		pr("\nbases".implode(" ",$bases));
		$number=2;
		while( true){
			$ok = true;
			for($i=0;$i<sizeof($bases);$i++)
			{
				$base = $bases[$i];
				pr("\norig num:".$number);
				$ishappy = array();
				$whiledeep=0;
				if (!ishappy($number,$number,$base))
				{
					pr("\nnem happy");
					$ok = false;
					$number++;
					break;
				}
				else
				{
					pr("\n happy eddig ok");
				}
				
				if (!$ok) break;
			}
			if ($ok) { pr("!!!!!!!!!!!!!!!!HAPPY: ".$number); $zzz=0;  echo " ".$number;break;}
			if (++$zzz==200000) { pr("\nbajvan");exit; }
		}
		
		
}
$whiledeep = 0;
$ishappy = array();
function ishappy($number, $orignumber, $base)
{
	
	global $whiledeep,$ishappy;
	if ($whiledeep++==200000) { pr("\nbajvan2");exit;}
	if (isset($ishappy[$number])) return false;
	pr("\nishappy:".$number." /".$orignumber);
	
	$new_number = base_convert($number,10,$base);
	pr("\nnew num:".$new_number." base : ".$base);

	$sum = 0;
	$pieceval = array();
	for($i=0;$i<strlen($new_number);$i++)
	{
		$piece = $new_number[$i];
//		$pieceval[] = baseszor($piece);//*$piece
		$pieceval[] = ($piece*$piece);//
	}
	pr($pieceval);
	$piecesum = 0;
	$piecesum = array_sum($pieceval);
	/*
	foreach($pieceval as $val)
	{
		$piecesum = baseadd($piecesum,$val,$base);
	}*/
	vd($piecesum);
	vd($orignumber);
	$ishappy[$number] = "";
	switch($piecesum){
		case 1:	return true; break;
		case $base; return true;break;
		case $new_number<$number: return false; break;
		//case $new_number<$base: return false; break;
		case $number: return false; break;
		case $orignumber: return false; break;
		default :
			return ishappy($piecesum,$orignumber,$base);break;
	}
}

function baseadd($num1,$num2,$base)
{
	 $numb1 = base_convert($num1,$base,10);
	 $numb1 = base_convert($num2,$base,10);
	 return base_convert($numb2+$numb1,10,$base);
}
function baseszor($num1,$base)
{
	 $numb1 = base_convert($num1,$base,10);
	 return base_convert($numb1*$numb1,10,$base);
}
	/// /// /// /// /// /// /// // CODE ENDS HERE/// /// /// /// /// /// /// /// /// /// /// 























/********************************* SUPPORT METHODS *******************************/

if (OB)
{
	$content = ob_get_contents();
	ob_end_flush();
	if ($fp2 = fopen("output.txt","w")) {
		fwrite($fp2,$content);
		fclose($fp2);
	}
	
}

// kinyomja a 2 dimenzios tombot space-kel szeparalva.
function printsolution($array)
{
	foreach($array as $sor)
	{
		echo "\n";
		foreach($sor as $v)
		{ 
			echo $v." ";
		}
	}
}

// kinyomja a 2 dimenzios tombot szeparator nelkul.
function printtable($array)
{
	echo "\n";
	foreach($array as $sor)
		{
			echo "\n";
			foreach($sor as $v)
			{ 
				echo $v;
			}
		}
	echo "\n";			
}

function pr($mixed)
{
	if (DEBUG==1)
		print_r($mixed);
}

function vd($mixed)
{
	if (DEBUG==1)
		var_dump($mixed);
}

?>