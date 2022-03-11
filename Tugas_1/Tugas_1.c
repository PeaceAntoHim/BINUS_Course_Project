#include <stdio.h>
#include <string.h>

int main() {
   char Str[500], gaji1, gaji2, gaji3;
   int persentaseJ, persentaseP, jmlhJamKerja;
   
   printf ("PROGRAM HINTUNG GAJI KARYAWAN\n");
   printf ("Nama karyawan: ");
   scanf("%[^\n]", Str);
   printf("Golongan Jabatan: ");
   scanf("%d", &persentaseJ);
   printf ("Pendidikan: ");
   scanf("%d", &persentaseP);
   printf ("Jumlah jam kerja: ");
   scanf("%d", &jmlhJamKerja);

   if ( persentaseJ == 1 )
   {
      gaji1 = 2000000 * 5%
   }
   else if ( persentaseJ == 2 )
   {
      gaji1 = 2000000 * 10%
   }
   else if ( persentaseJ == 3 )
   {
      gaji1 = 2000000 * 15%
   }
   printf("    Tunjangan Jabatan: %d\n", gaji1);

   // if ( persentaseP == SMA) {
   //    gaji2 = (2000000 * 2.5%);
   // }
   // else if ( persentaseP == D3) {
   //    gaji2 = (2000000 * 5%);
   // }
   // else if ( persentaseP == S1) {
   //    gaji2 = (2000000 * 10%);
   // }
   // printf ("    Tunjangan Pendidikan: %d\n", gaji2);

   // if( jmlhJamKerja > 8)
   // {
   //    gaji3 = (20000 * &jmlhJamKerja);
   // }
   // else
   // {
   //    gaji3 = (20000 * 8);
   // }
   // printf ("    Honor Lembur: %d\n", gaji3);
}

   // switch(kerja) {
   //    case 'namaKaryawan'
   //    {
   //       if (jmlhJamKerja <= 40) {
   //          printf("Gaji karyawan = %d\n", Persentase * jmlhJamKerja);
   //       }
   //       else {
   //          printf("Gaji karyawan = %d\n", Persentase * 40 + (jmlhJamKerja - 40) * Persentase * 1.5);
   //       }
   //       break;
   //    }
   // }
   // scanf("%d", &jmlhJamKerja);