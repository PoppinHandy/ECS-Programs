#!/usr/bin/perl

print "Enter a string: ";
$varstring = <>;

$varstring =~ s/(CA){5}(CA)*/X/g;

print "$varstring\n";
