#include <stdio.h>
#include <string.h>

struct mhs {
   char  nim[11];
   char  nama[50];
   float gpa;
   char mataKuliah[50];
};

int main () {
   struct mhs info;
   float wgpa;

   scanf("Masukan Nim anda = $s\n", &info.nim);
   fflush(stdin);
   scanf("Masukan Nama anda = $s\n", &info.nama);
   scanf("Masukan GPA anda = %f", &wgpa);
   info.gpa = wgpa;
   scanf("Masukan Mata Kuliah anda = $s\n", &info.mataKuliah);
   printf("Tampilan semua data %$ %$ %$ %.2f", info.nim, info.nama, info.gpa, info.mataKuliah);
   return 1;
}
