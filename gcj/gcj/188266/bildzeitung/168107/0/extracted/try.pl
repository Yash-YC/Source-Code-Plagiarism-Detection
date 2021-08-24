#!/opt/local/bin/perl -w

use Math::BaseCnv qw( :all ) ;
use List::Util qw( sum ) ;

my $cases = <> ;
chomp $cases ;

foreach my $case (1..$cases) {
	my $line = <> ;
	chomp $line ;
	
	my @bases = split /\s+/, $line ;
	
	my $done ;
	my $i = 2 ;
	while ( ! $done ) {
		my $happy = 1 ;
		foreach ( @bases ) {
			if ( ! is_happy( $i, $_ ) ) {
				undef $happy ;
				last ;
			}
		}
		last if ( $happy ) ;
		$i++ ;
	}
	
	print "Case #$case: $i\n" ;
}

sub is_happy {
	my ( $n, $base ) = @_ ;
	#print "Got $n with base $base\n" ;

	$n = cnv( $n, 10, $base ) ;

	my %store = ( $n => 1 ) ;
	my $done ;

	
	while ( ! $done ) {
		
		my $r = sum map { $_ * $_ } split //, $n ;

		#print "$n, $r\n" ;

		return 1 if ( $r == 1 ) ;
		
		$n = cnv( $r, 10, $base ) ;
		
		last if ( exists $store{$n} ) ;
		
		$store{$n} = 1 ;		
	}	
	
	return ;
}