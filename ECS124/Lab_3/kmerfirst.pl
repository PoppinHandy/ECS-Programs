#!/pkg/bin/perl -w
# Program kmerfirst.pl
# This program finds all the overlapping k-mers of the input string. It builds
# an associative array where each key is one distinct k-mer in the string,
# and the associated value is the starting position where that
#k-mer is FIRST found.  Compare this to kmer2.pl
print "Enter the database file name: ";
$dataname = <>;
chomp $dataname;
print "Enter the query file name: ";
$queryname = <>;
chomp $queryname;
open DB, $dataname;
open QUERY, $queryname;
$k = 4;
chomp $k;
$query = <QUERY>;
@seq = split(//, $query);
$seq_length = @seq;
chomp $query;
%kmer = ();   # This initializes the database hash called kmer.
%qmer = ();   # This initializes the query hash called qmer.
%stringhash = (); # This initializes the stringhash called stringhash
$len = 0;

# Making kmers for the query sequence
$j = 1;
while (length($query) >= $k) {
        $query =~ m/(.{$k})/;     
        #print "$1, $j \n";
        if (! defined $qmer{$1}) {     #defined is a function that returns true
                                          # if a value has already been assigned to
                                          # $qmer{$1}, otherwise it returns false. 
                                          # the ! character is the negation, so
                                          # if $qmer{$1} has no value, then it will
                                          # be assigned the value of $j, the position
                                          # where the k-mer is first found.
                $qmer{$1} = $j;
        }
         $j++;
         $query = substr($query, 1, length($query) -1);
}# end while

# Making kmers for the database sequence
while ($database = <DB>){
	chomp $database;
	#print "Input sequence is: $database\n";
	$i = 1;
	while (length($database) >= $k) {
	  $database =~ m/(.{$k})/; 
	  #print "$1, $i \n";
	   if (! defined $kmer{$1}) {     #defined is a function that returns true
					  # if a value has already been assigned to
					  # $kmer{$1}, otherwise it returns false. 
					  # the ! character is the negation, so
					  # if $kmer{$1} has no value, then it will
					  # be assigned the value of $i, the position
					  # where the k-mer is first found.
	    $kmer{$1} = $i;       
	   }
	# Comparing the two kmers
	foreach $qmerkey(keys(%qmer)){
		foreach $kmerkey(keys(%kmer)){
			if ($kmerkey eq $qmerkey){
				@db = split(//, $database);
				$db_length = @db;
				$k_begin_pos = $kmer{$kmerkey};
				$q_begin_pos = $qmer{$qmerkey};
				$k_end_pos = $k_begin_pos + 3;
				$q_end_pos = $q_begin_pos + 3;
				
				# Going left first
				while ($db[$k_begin_pos] eq $seq[$q_begin_pos] && $k_begin_pos != 0 && $q_begin_pos != 0){
					$len++;
					$q_begin_pos--;
					$k_begin_pos--; 
				}# end while
				
				# Going right
				while ($db[$k_end_pos] eq $seq[$q_end_pos] && $k_end_pos != $db_length && $q_begin_pos != $seq_length){
                                        $len++;
                                        $q_begin_pos++; 
                                        $k_begin_pos++;
                                }# end while
				if (! defined $stringhash{$k_begin_pos}){
					$stringhash{$k_begin_pos} = $kmerkey;
					if ($len >= 10){
                                        	print "HSP found! It is in @db.\n";
                                	}

				} 
				# See if HSP
				$len = 0;
			}# end if
		}# end inner foreach
	}# end foreach
	 $i++;
	 $database = substr($database, 1, length($database) -1);
	}
	%{$stringhash} = ();
}#end while


close (DB);
close(QUERY);

