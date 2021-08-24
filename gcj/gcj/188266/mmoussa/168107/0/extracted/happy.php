<?php

$testCases = fgets( STDIN );

for ( $i = 1; $i <= $testCases; $i++ )
{
    $baseLine = fgets( STDIN );
    $bases = explode( ' ', $baseLine );

    $n = 2;

    while ( true )
    {
        $happy = true;

        for ( $j = 0; $j < count($bases); $j++ )
        {
            $history = array();

            if ( !isHappy( base_convert($n, 10, $bases[$j]), $bases[$j], $history ) )
            {
//                echo $n . ' is not happy in ' . $bases[$j] . "\n";
                $happy = false;
                break;
            }
            else
            {
//                echo $n . ' is happy in ' . $bases[$j] . "\n";
            }

        }

        if ( $happy )
        {
            break;
        }

        $n++;
    }

    echo "Case #{$i}: " . $n;

    if ( $i != $testCases )
        echo "\n";
}

function isHappy($n, $base, &$history)
{
    if ( $n == 1 )
    {
        return true;
    }
    else
    {
        $newNumber = 0;

        for ( $i = 0; $i < strlen($n); $i++ )
        {
            $digit = substr($n, $i, 1);
            $newNumber += $digit * $digit;
        }

        if ( isset($history[$newNumber]) )
        {
            return false;
        }
        else
        {
            $history[$newNumber] = true;
            return isHappy( base_convert($newNumber, 10, $base), $base, $history );
        }
    }
}