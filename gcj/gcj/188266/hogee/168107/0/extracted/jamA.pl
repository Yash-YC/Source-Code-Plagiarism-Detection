# Google Code Jam 2009
# written by hogee <hogee3@gmail.com>
# This Program use the follow CPAN library.
# http://search.cpan.org/~kwilliams/Math-BaseCalc-1.013/lib/Math/BaseCalc.pm
use Math::BaseCalc; 

my $T = <STDIN>;chomp;

my $result;
foreach my $case (1..$T){
	my $line = <STDIN>;
	chomp($line);
	$result = &calc ($line);
	printf ("Case #%d: %d\n",$case , $result);

}
sub calc {
	my $a = shift;
	my @basis = split(/ /,$a); # basis
	my $ans = 0;
	my $baseobj = new Math::BaseCalc(digits => [0,1]);
	my $NG = 0;
	my %hist;
	my $master_number = 0;
	while(1){
#		print "TRY $master_number==>\n";
		$master_number++;
		$NG = 0;
		next if($master_number == 1);
		foreach my $d1 (@basis){
			$baseobj->digits([0..$d1-1]);
			$ans = 0;
			$number =$master_number;
			%hist = {};
			while(1){
				foreach(split(//,$baseobj->to_base($number))){
					$ans += $_**2;
				}
				if($ans == 1){
#					print "find!\n";
					last;
				}
				if($hist{$ans} == 1){
#					print "akirameta\n";
					$NG = 1;
					last;
				} else {
					$hist{$ans} = 1;
				}
				$number = $ans;
#				print $number ." ".$baseobj->to_base($number)."\n";
				$ans = 0;

			}
		}
		if($NG == 1){
#			print "$master_number NG\n";
		} else {
			return $master_number;
#			last;
		}
	}
}
