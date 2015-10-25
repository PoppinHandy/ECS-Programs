#!/usr/bin/perl
print "Input a DNA sequence\n";

$_ = <DATA>;
chomp;

tr/ATCG/X/;
print "$_ \n";


__DATA__
acTGG
