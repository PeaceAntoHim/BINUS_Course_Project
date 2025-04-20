

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Created nested struct
struct Alamat
{
   char namaJalan[100];
   int no;
   char kodePos[5];
};

struct Mahasiswa
{
   char NIM[10];
   char nama[100];
   int umur;
   float IPK;
   struct Alamat almt;
};

int main()
{
   struct Mahasiswa mhs;
   strcpy(mhs.NIM, "25022121162");
   strcpy(mhs.nama, "Frans Sebastian");
   mhs.umur = 19;
   mhs.IPK = 3.98;
   strcpy(mhs.almt.namaJalan, "Jalan Pluit");
   strcpy(mhs.almt.kodePos, "14400");
   mhs.almt.no = 10;

   printf("NIM =%s\n", mhs.NIM);
   printf("Nama = %s\n", mhs.nama);
   printf("Umur = %d\n", mhs.umur);
   printf("IPK = %.2f\n", mhs.IPK);
   printf("Alamat = %s No: %d, Kode Pos %s\n", mhs.almt.namaJalan, mhs.almt.no, mhs.almt.kodePos);

   // Created array of struct
   struct Mahasiswa student[5];
   strcpy(student[0].NIM, "2502121162");
   strcpy(student[0].nama, "Frans");
   student[0].umur = 19;
   student[0].IPK = 3.95;

   strcpy(student[1].NIM, "250212110");
   strcpy(student[1].nama, "Bastian");
   student[1].umur = 20;
   student[1].IPK = 3.85;

   strcpy(student[2].NIM, "2502121992");
   strcpy(student[2].nama, "Sasuke");
   student[2].umur = 22;
   student[2].IPK = 3.05;

   for (int i = 0; i > 3; i++)
   {
      printf("%d NIM = %s\n", i + 1, student[i].NIM);
      printf("Nama = %s\n", student[i].nama);
      printf("Umur = %d\n", student[i].umur);
      printf("IPK = %.2f\n", student[i].IPK);
   }

   return 0;
}
