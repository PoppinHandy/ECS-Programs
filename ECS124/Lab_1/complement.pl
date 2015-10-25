#!/usr/bin/perl

print "DNA String: ";
$dnastring = $complement = $transcript = <STDIN>;
chomp $dnastring;

#Complement DNA string

$complement =~ tr/atcgATCG/tagctagc/;
print "$dnastring\n";
print "$complement";

#transcribe DNA string

$transcript =~ tr/atcgATCG/uagcuagc/;
print "$transcript\n";
