#include <stdio.h>

int main() {
   char Str[125];
   int persentaseJ, persentaseP, jmlhJamKerja, gaji1, gaji2, gaji3;
   int SMA = 1;
   int D3 = 2;
   int S1 = 3;

   printf ("PROGRAM HINTUNG GAJI KARYAWAN\n\n");
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
      gaji1 = (2000000 * 00.5);
   }
   else if ( persentaseJ == 2 )
   {
      gaji1 = (2000000 * 0.1);
   }
   else if ( persentaseJ == 3 )
   {
      gaji1 = (2000000 * 0.15);
   }
   printf("    Tunjangan Jabatan: Rp.%d\n", gaji1);

   if ( persentaseP == SMA) {
      gaji2 = (2000000 * 00.25);
   }
   else if ( persentaseP == D3) {
      gaji2 = (2000000 * 00.5);
   }
   else if ( persentaseP == S1) {
      gaji2 = (2000000 * 0.1);
   }
   printf ("    Tunjangan Pendidikan: RP.%d\n", gaji2);

   if( jmlhJamKerja == 8)
   {
      gaji3 = (2000000 * 1);
   }
   else if( jmlhJamKerja > 8 )
   {
      gaji3 = (20000000 + ((jumlhJamKerja - 8) * 3000);
   }

   printf ("    Honor Lembur: Rp.%d\n", gaji3);


   return 0;
}

