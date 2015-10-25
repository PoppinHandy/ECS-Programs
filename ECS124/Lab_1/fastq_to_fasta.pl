#!/usr/bin/perl

#Open File
print "Name of input file: ";
$file = <>; 
print "Choose the name of the file to output to: ";
$outfile = <>;
open FASTQ, "$file";
open OUT, ">$outfile";

#Write ID and sequence to new file
while ($_ = <FASTQ>)
{
	chomp;
	$sequence = $_;
	$seq_count = $sequence =~ tr/AGTC/X/c;
	#print "$_\n";
	$id = $_ =~ tr/@/>/;
	if ($id > 0 or $seq_count == 0)
	{
		print "$_\n";
		print OUT "$_\n";
	}
}#end while

close FASTQ;
close OUT;