#!/usr/bin/perl

print "Enter a string: ";

$_ = <>;

if ($_ =~ m/^TATA[AT]A[AT][AGTC]{17}[CT]{2}CA[AG]{2}$/)
  {
    print "Matched!\n";
  }

else
  {
    print "No match!\n";
  }
