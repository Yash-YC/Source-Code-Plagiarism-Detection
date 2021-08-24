for ($i=0; $i<=40; $i++) {
    $a[$i][0] = $a[$i][$i] = 1 ;
    for ($j=1; $j<$i; $j++) {
        $a[$i][$j] = $a[$i-1][$j-1] + $a[$i-1][$j] ;
    }
}
$lim = <> ;
for ($cc=1; $cc<=$lim; $cc++) {
    my $l = <> ;
    chomp $l ;
    my @f = split " ", $l ;
    my $n = $f[0] ;
    my $c = $f[1] ;
    $cnt[0] = 0 ;
    for ($i=1; $i<=$n; $i++) {
        my $s = 0 ;
        my $p0 = -1 ;
        for ($j=0; $j<=$i; $j++) {
            next if $i - $j > $c ;
            next if $c - $i + $j > $n - $i ;
            $p = $a[$i][$j] * $a[$n-$i][$c-$i+$j] ;
            die "Bad p: $p $i $j $n $c" if $p <= 0 ;
            if ($j == $i) {
                $p0 = $p ;
            }
            $s += $p ;
        }
        die "Bad s: $s" if $s <= 0 ;
        my $ep = 0 ;
        for ($j=0; $j<$i; $j++) {
            next if $i - $j > $c ;
            next if $c - $i + $j > $n - $i ;
            $p = $a[$i][$j] * $a[$n-$i][$c-$i+$j] ;
            $ep += $p / $s * $cnt[$j] ;
        }
        if ($p0 >= 0) {
            $cnt[$i] = (1 + $ep) / (1 - $p0 / $s) ;
        } else {
            $cnt[$i] = 1 + $ep ;
        }
    }
    print "Case #$cc: $cnt[$n]\n" ;
}
