from Bio.Seq import Seq 
# Sequence given 
dna_sequence = "TACAGCACTCAAGTCA" 

# Convert the sequence to a Seq object 
seq = Seq(dna_sequence) 

# a. Non-template strand (coding strand) 
non_template_strand = seq.reverse_complement() 
print("Non-template strand (coding strand):", non_template_strand) 
# b. mRNA sequence 
mRNA_sequence = seq.transcribe() 
print("mRNA sequence:", mRNA_sequence) 
# Mutate the non-coding strand 
mutated_sequence = non_template_strand[:3] + "T" + non_template_strand[3:] 
print("Mutated non-template strand:", mutated_sequence) 
# Generate mutated mRNA sequence
mutated_mRNA_sequence = mutated_sequence.transcribe() 
print("Mutated mRNA sequence:", mutated_mRNA_sequence)