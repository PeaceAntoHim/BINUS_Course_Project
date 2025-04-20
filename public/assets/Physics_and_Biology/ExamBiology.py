from Bio.Seq import Seq
from Bio.SeqUtils import MeltingTemp, molecular_weight

# Sekuen DNA
seq1 = "CAGGTAACAAACCAACCAACTTTCGATCTCTTGTAGATCTGT"
seq2 = "GTCAACACTTGTAGT"

# Membuat objek Sequence
dna_seq1 = Seq(seq1)
dna_seq2 = Seq(seq2)

# a. Analisis sederhana
# Panjang sekuen
length_seq1 = len(dna_seq1)
length_seq2 = len(dna_seq2)

# Distribusi nukleotida
nucleotide_distribution_seq1 = {
    'A': dna_seq1.count('A'),
    'T': dna_seq1.count('T'),
    'G': dna_seq1.count('G'),
    'C': dna_seq1.count('C')
}

nucleotide_distribution_seq2 = {
    'A': dna_seq2.count('A'),
    'T': dna_seq2.count('T'),
    'G': dna_seq2.count('G'),
    'C': dna_seq2.count('C')
}

# Temperatur leleh
melting_temp_seq1 = MeltingTemp.Tm_Wallace(dna_seq1)
melting_temp_seq2 = MeltingTemp.Tm_Wallace(dna_seq2)

# Berat molekul
molecular_weight_seq1 = molecular_weight(dna_seq1)
molecular_weight_seq2 = molecular_weight(dna_seq2)

# Menampilkan hasil analisis
print("Analisis Sekuen DNA 1:")
print("Panjang Sekuen:", length_seq1)
print("Distribusi Nukleotida:", nucleotide_distribution_seq1)
print("Temperatur Leleh:", melting_temp_seq1)
print("Berat Molekul:", molecular_weight_seq1)
print()

print("Analisis Sekuen DNA 2:")
print("Panjang Sekuen:", length_seq2)
print("Distribusi Nukleotida:", nucleotide_distribution_seq2)
print("Temperatur Leleh:", melting_temp_seq2)
print("Berat Molekul:", molecular_weight_seq2)
print()

# b. Stabilitas berdasarkan persentase G-C dan T-A
gc_content_seq1 = (dna_seq1.count('G') + dna_seq1.count('C')) / length_seq1
gc_content_seq2 = (dna_seq2.count('G') + dna_seq2.count('C')) / length_seq2

if gc_content_seq1 > gc_content_seq2:
    stable_seq = "DNA 1"
else:
    stable_seq = "DNA 2"

print("Sekuen dengan stabilitas lebih tinggi:", stable_seq)
print()

# c. Penjajaran Sekuen
from Bio import pairwise2

alignments = pairwise2.align.globalxx(seq1, seq2)
best_alignment = alignments[0]
aligned_seq1 = best_alignment[0]
aligned_seq2 = best_alignment[1]

print("Sekuen DNA 1 (Panjang: {}):".format(len(aligned_seq1)))
print(aligned_seq1)
print("Sekuen DNA 2 (Panjang: {}):".format(len(aligned_seq2)))
print(aligned_seq2)