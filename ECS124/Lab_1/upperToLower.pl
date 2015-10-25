#!/usr/bin/perl

$sequence = 'VRNrIAEelslrrFMVALILdIKrTPgNKPriaemICDIDtYIvEa';
print "$sequence\n";

$sequence =~ tr/A-Za-z/a-zA-Z/;
print "$sequence\n";
