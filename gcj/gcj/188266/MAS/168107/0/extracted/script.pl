use strict;
use warnings;
use Math::BaseCalc;

my @CalcList = (0, 0);
foreach my $i (2..10) {
    push @CalcList, Math::BaseCalc->new(digits => [0 .. $i-1]);
}

my $count = <STDIN>;
chomp $count;

foreach my $i (1..$count) {
    my $line = <STDIN>;
    my @bases = split /\s/, $line;
    
    my $target = 1;
    LOOP: while (1) {
        $target++;
        my $is_happy = 1;
        foreach my $base (@bases) {
            unless (is_happy_number($target, $base)) {
                $is_happy = 0;
                next LOOP;
            }
        }
        last if $is_happy;
    }
    printf "Case #%d: %d\n", $i, $target;
}

sub is_happy_number {
    my $base_10 = shift; # base 10
    my $base = shift;
    
    my $calc = $CalcList[$base];
    
    # to base n
    my $num = $base_10;
    my %done;
    while ($num > 1) {
        if (exists $done{$num}) {
            return 0;
        }
        $done{$num} = 1;
        my $base_n = $calc->to_base($num);
        $num = sum_each_keta($base_n);
    }
    return $num;
}

sub sum_each_keta {
    my $str = shift;
    my $sum = 0;
    foreach my $i (split //, $str) {
        $sum += $i * $i;
    }
    return $sum;
}
