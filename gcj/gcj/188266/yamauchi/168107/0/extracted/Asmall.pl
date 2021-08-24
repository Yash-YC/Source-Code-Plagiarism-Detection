#!/perl

open(IN, "input.txt");
@in = <IN>;
close(IN);

chomp(@in);

open(OUT, ">output.txt");

for($i=1; $i<=$in[0]; $i++){
	@base = split(/\s/, $in[$i]);
	$test = 1;
	print"$i\n";
	do{
		$test++;
		$happy = 1;
		foreach $b(@base){
			if(&calc($test, $b) == 0){
				$happy = 0;
				last;
			}
		}
	}while($happy==0);
	print OUT "Case #".$i.": ".$test."\n";
}
close(OUT);

sub calc
{
	local($n, $b) = @_;
	local($i, $p, $happy, @digits);
	$happy = 0;
	for($i=0; $i<200; $i++){
		$p = 1;
		while($p<$n){
			$p *= $b;
		}
		@digits = ();
		while($p>0){
			push(@digits, int($n/$p));
			$n -= int($n/$p)*$p;
			$p = int($p/$b);
		}
		$n = 0;
		for($j=0; $j<=$#digits; $j++){
			$n += $digits[$j]*$digits[$j];
		}
		if($n==1){
			$happy=1;
			last;
		}
	}
	return $happy;
}
