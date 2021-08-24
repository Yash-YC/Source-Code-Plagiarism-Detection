use strict;
use warnings;
use Math::BaseCalc;

my %LOGLEVEL = (debug => 0, info => 1, warn => 2, error => 3, none => -1);
my $debug = $LOGLEVEL{"none"};
sub debug ($) { &log(shift, "debug"); }
sub info ($) { &log(shift, "info"); }
sub warn ($) { &log(shift, "warn"); }
sub error ($) { &log(shift, "error"); }
sub log ($$) {my ($msg, $level) = @_;print $msg."\n" if $debug >= $LOGLEVEL{$level};}

my $case = 0;
my $first = <>;
chomp($first);
my $glut;
#&debug($first);
while(<>){
    chomp();
    my $line = $_;
    next if ($line eq "");
    $case++;
    #%$glut = ();
    my @bases = split " ", $line;
    my $r;
    for (my $i=2; $i<=50000; $i++) {
        my $ret = 1;
        for my $base (@bases) {
            &debug("check base=".$base.", no=".$i);
            $ret = $ret && &check($i, $base, {});
        }
        if ($ret) {
            &debug("happy!:".$i);
            print "Case #".$case.": ".$i."\n";
            last;
        }
    }
    &debug($line);
}

#n's base is 10
sub check () {
    my ($n, $base, $lut) = @_;
    if (defined($lut->{$n}) && $lut->{$n} == 1) {
        #loop
        return 0;
        for my $key (keys %$lut) {
            $glut->{"$base-$key"} = 0;
        }
    }
    if (defined($glut->{"$base-$n"})) {
        return $glut->{"$base-$n"};
    }
    $lut->{$n} = 1;
    my $org_n = $n;
    &debug("check n=".$n.", base=".$base);
    my $calc = new Math::BaseCalc(digits=>[0..$base-1]);
    $n = $calc->to_base($n);
    my @ns = split "", "$n";
    &debug("ns:".join ":", @ns);
    my $sum = 0;
    for my $t (@ns) { $sum += $t*$t; }
    if ($sum == 1) {
        #happy!
        for my $key (keys %$lut) {
            $glut->{"$base-$key"} = 1;
        }
        return 1;
    }
    #elsif ($sum < $base) {
    #    return 0;
    #}
    elsif ($sum == $org_n) {
        #return same no
        return 0;
        for my $key (keys %$lut) {
            $glut->{"$base-$key"} = 0;
        }
    } else {
        return &check($sum, $base, $lut);
    }
}
