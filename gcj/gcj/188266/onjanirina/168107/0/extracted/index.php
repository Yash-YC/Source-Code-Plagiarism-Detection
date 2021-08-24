<?php
	
	$pathInput=dirname( __FILE__)."\\input.txt"; 
	$pathOutput=dirname( __FILE__)."\\output.txt"; 
	$strInput=""; 
	$strOutput=""; 
	
	@unlink( $pathOutput); 
	
	// start
	$timeStart=microtime( TRUE); 
	
	class myBase
	{
		public $nBase=0; 
		public function __construct( $nBase)
		{
			$this->nBase=$nBase; 
		}
		
		public function isHappy( $n)
		{
			$num=$n; 
			$sums=array(); 
			$sum=$this->sumDigits( $num); 
			$sums[]=$sum; 
			while( $sum!=1)
			{
				$sum=$this->sumDigits( $sum); 
				if( in_array( $sum, $sums))
					return FALSE; 
				$sums[]=$sum; 
			}
			return TRUE; 
		}
		
		public function sumDigits( $number)
		{
			$sum=0; 
			$numBase=base_convert( $number, 10, $this->nBase); 			
			$rDigits=str_split(( string) $numBase, 1); 
			foreach( $rDigits as $digit)
				$sum+=pow(( int) $digit, 2); 
			return $sum; 
		}		
		
	}
	
	// 
	if( file_exists( $pathInput))
	{
	
		// FileContents
		if( $fileContents=file( $pathInput, FILE_TEXT))
		{
			$strOutput=""; 
			$nCases=( int) $fileContents[ 0];			
			for( $nCase=1; $nCase<=$nCases; $nCase++)
			{
				$nCaseResult=0; 
				$rBases=array(); 
				$arrBases=explode( " ", $fileContents[ $nCase]); 
				foreach( $arrBases as $nBase)
					$rBases[ ( int) $nBase]=new myBase(( int) $nBase); 
				
				/**/
				$nTest=2; 
				while( !$nCaseResult)
				{
					$nCount=0; 
					foreach( $rBases as $base)
					{
						if( $base->isHappy( $nTest))
							$nCount++; 
					}
					if( $nCount!=count( $rBases))
						$nTest++; 
						else $nCaseResult=$nTest; 
				} /**/
				
				$strCase="Case #".$nCase.": ".$nCaseResult." \n"; 
				$strOutput.=$strCase; 
			}
			file_put_contents( $pathOutput, $strOutput, FILE_TEXT); 
		}
		
	}
	$timeDuration=microtime( TRUE)-$timeStart; 
	
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Google Code Jam 2009 - 1A</title>
</head>
<body>
</body>
</html>