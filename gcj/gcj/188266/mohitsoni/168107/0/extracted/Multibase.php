<?php
// MultiBaseHappy.php
function mdisp( $e ) { echo "$e\n"; }

$un_res = array();
function is_happy( $number, $base ) {
	global $un_res;
    $res = (string)$number;
	$ssq = 0;
	for($i=0; $i<strlen($res); $i++ ) {
		$dig = (int)$res[$i];
		$dig10 = base_convert( $dig, $base, 10 );
		$ssq10 = base_convert( $ssq, $base, 10 );
		$ssq = base_convert( $ssq10 + ($dig10 * $dig10), 10, $base );
	}

	if( in_array($ssq, $un_res) )
		return false;
	else
		$un_res[] = $ssq;

	if( $ssq == 1 ) {
		return true;
	}
	else
        return is_happy( $ssq, $base );
}

$num = 2;

$input = explode( "\n", trim(file_get_contents("A-small-attempt0.txt")) );

$N_cases = $input[0];
for( $i=1; $i<=$N_cases; $i++ ) {
    $num = 2;
    $bases = explode( ' ', $input[$i] );
    $happy_found = false;
    while( !$happy_found ) {
        $happy_stat = true;
        foreach( $bases as $base ) {
            $base = (int)$base;
            $un_res = array();
            $happy_stat &= is_happy( base_convert($num,10,$base),$base);
        }
        if( $happy_stat == 0 )
            $num++;
        else {
            mdisp( "Case #$i: $num" );
            $happy_found = true;
        }
    }
}
?>