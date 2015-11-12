#!/usr/bin/perl

print "Enter a string: ";

$_ = <>;

if ($_ =~ m/TT[GT]ACA[AGCT]{18}TAT[AG]TT/)
{
	print "Promoter sequence detected!";
}
else 
{
	print "Nothing detected!";
}
