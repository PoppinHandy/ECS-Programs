#!usr/bin/python
import re

#r = re.compile('\bF[A-Z][a-z]+[_][0-9]+\b')
alignment_file = open('/home/phamgouran/Browne_lab/Walnut_reads/Walnut_filtered/FASTA/BWA_INDEX/bwa_alignments_no_header.out', 'r')
#fo = open ('/home/phamgouran/Browne_lab/Walnut_reads/Walnut_filtered/ED-I.notwalnutplastids.fq', 'r')
ID_list = []
for line in alignment_file:
    #print "Reading: %s" % line
    list_of_words = line.split()

    #print list_of_words[0]
    ID_list.append(list_of_words[0])

ID_set = set(ID_list)
print ID_set
#print ID_list
#fo.close()
alignment_file.close()
