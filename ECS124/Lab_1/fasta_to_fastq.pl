#!/usr/bin/perl

#Open File
print "Name of input file: ";
$file = <>;
print "Choose the name of the file to output to: ";
$outfile = <>;
open FASTA, "$file";
open OUT, ">$outfile";

#Change to FASTQ
while ($_ = <FASTA>){
      chomp;
      $seq_check = $_ =~ tr/>/@/;

      #Change > to @ and store the sequence ID
      if ($seq_check > 0)
      {
      	 print "$_\n";
	 $seq_id = $_;
	 $seq_id =~ tr/@//d;
      }#end if

      #Add the + and sequence ID as well as quality score
      else{
	$seq = $_;
	$seq_check = $seq =~ tr/AGTC/X/c;
	$seq_count = $seq =~ tr/AGTC/X/;
	#print "$seq_count\n";
	if ($seq_check == 0){
	   print "$_\n";
	   print "+$seq_id\n";
	   for (my $i = 0; $i < $seq_count; $i++){
	       print "B";
	   }
	   print "\n";
	}#end if	
     }#end else
}#end while

close FASTA;
close OUT;