#!/pkg/bin/perl -w
# Program kmer1.pl
# #Here we try to find all the k-mers of a string. It
# only finds non-overlapping ones, but later it will
# be modified to find the overlapping ones as well.
# dg

$dnastring = <>;
print "What length k-mer?\n";
$k = <>;  
chomp $k; # without this, the next line finds no matches.
while ($dnastring =~ m/(.{$k})/g) {   # notice the /g in the regular expression
 print "$1 \n";
}

