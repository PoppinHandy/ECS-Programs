#!/usr/bin/perl

print "Enter a string: ";

$_ = <>;

if ($_ =~ m/GCC[ATCG]{5}GGC/)
  {
    print "Matched!\n";
  }
else
  {
    print "No match!\n";
  }
