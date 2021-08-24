<?php

$testCases = fgets( STDIN );
$facCache = array();
$facCache[0] = 1;

for ( $i = 1; $i <= $testCases; $i++ )
{
    fscanf( STDIN, '%d %d', $C, $N );
    $combo = getCombinations($C, $N);

    echo "Case #{$i}: " . ( ($combo / $N) + 1 );

    if ( $i != $testCases )
        echo "\n";
}

function getCombinations($C,$N)
{
    return fac($C) / fac($N) * fac($C - $N);
}

function fac($n)
{
    global $facCache;

    if ( isset($facCache[$n]) )
    {
        return $facCache[$n];
    }
    else
    {
        $facCache[$n] = $n * fac($n-1);
        return $facCache[$n];
    }
}