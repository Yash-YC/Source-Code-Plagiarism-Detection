#!/usr/bin/perl -w
use strict;
use integer;

sub sos($$) {
    my ($n, $b) = @_;
    my $result = 0;
    while ($n != 0) {
        my $d = $n % $b;
        $result += $d * $d;
        $n /= $b;
    }
    $result;
}

sub rsos($$) {
    my ($n, $b) = @_;
    my %result;
    while (1) {
        $n = sos($n, $b);
        return $n if $n == 1 || exists $result{$n};
        $result{$n} = 1;
    }
}

our %cache;

sub poke($$) {
    $cache{$_[0]} //= do {
        warn "$_[0] => $_[1]\n";
        $_[1];
    };
}

sub rpoke($@) {
    my ($n, @b) = @_;
    for my $p (1 .. (1 << @b) - 1) {
        poke("@{[map {($p >> $_) & 1 ? $b[$_] : ()} 0..$#b]}", $n);
    }
}

sub coll($) {
    my ($n) = @_;
    my @b;
    for my $b (2..10) {
        push @b, $b if rsos($n, $b) == 1;
    }
    rpoke($n, @b);
    if (@b == 9) {
        for my $k (sort keys %cache) {
            print "$k => $cache{$k}\n";
        }
        exit;
    }
}

my $i = 1;
while (1) {
    coll(++$i);
}
