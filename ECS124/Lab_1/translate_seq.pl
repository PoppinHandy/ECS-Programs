#!/usr/bin/perl
$sequence = 'SEETQMRLQLKRKLQRNRTSFTQEQIEALEKEFERTHYPDVFARERL';
print "$sequence\n";

$sequence =~ tr/ACGPSTWY/A/;
$sequence =~ tr/RNDQEHK/E/;
$sequence =~ tr/ILMFV/I/;

print "$sequence\n";
