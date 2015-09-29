#!/usr/bin/perl

$nucstring = 'acCtagGgCCTTAcga';
$nucstring =~ tr/tT/uU/;
print "$nucstring \n";

$nucstring =~ tr/uU/tT/;
print "$nucstring\n";
