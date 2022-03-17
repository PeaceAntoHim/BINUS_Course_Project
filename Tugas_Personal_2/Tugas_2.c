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

   printf("Masukan Nim anda = "); scanf("%s", &info.nim);
   fflush(stdin);
   printf("Masukan Nama anda = "); scanf("%s", &info.nama);
   printf("Masukan GPA anda = "); scanf("%f", &wgpa);
   info.gpa = wgpa;
   printf("Masukan Mata Kuliah anda = "); scanf("%s", &info.mataKuliah);
   printf("Tampilkan Nim = %s\n", info.nim);
   printf("Tampilkan Nama = %s\n", info.nama);
   printf("Tampilkan GPA =  %.2f\n", info.gpa);
   printf("Tampilkan mata kuliah = %s\n", info.mataKuliah);
   return 0;
}
