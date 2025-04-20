#include <stdio.h>

int main() {
   // Deklarasi variabel
   int D3 = 2;
   int S1 = 3;
   int SMA = 1;
   char nama[125];
   int gajiPerBulan = 2000000;
   int persentaseJ, persentaseP, jmlhJamKerja, gaji1, gaji2, gaji3;

   printf ("PROGRAM HINTUNG GAJI KARYAWAN\n\n");
   printf ("Nama karyawan: ");
   scanf("%[^\n]", nama);
   printf("Golongan Jabatan: ");
   scanf("%d", &persentaseJ);
   printf ("Pendidikan: ");
   scanf("%d", &persentaseP);
   printf ("Jumlah jam kerja: ");
   scanf("%d", &jmlhJamKerja);

   // Nama Karyawab
   printf("Nama Karyawan: %s\n", nama);
   printf("    Gaji per bulan: Rp. %d\n", gajiPerBulan);

   // Persentase Jabatan
   if (persentaseJ == 1 ) {
      gaji1 = (2000000 * 0.05);
   } else if (persentaseJ == 2 ) {
      gaji1 = (2000000 * 0.10);
   } else if (persentaseJ == 3 ) {
      gaji1 = (2000000 * 0.15);
   } else {
      printf("Golongan Jabatan tidak ditemukan\n");
      return 0;
   }
   printf("    Tunjangan Jabatan: Rp. %d\n", gaji1);

   // Tunjagnan pendidikan
   if (persentaseP == SMA) {
      gaji2 = (2000000 * 0.025);
   } else if (persentaseP == D3) {
      gaji2 = (2000000 * 0.05);
   } else if (persentaseP == S1) {
      gaji2 = (2000000 * 0.10);
   } else {
      printf("Gologan pendidikan tidak ditemukan mohon masukan salah satu kode ini SMA = 1, D3 = 2, S1 = 3\n");
      return 0;
   }
   printf("    Tunjangan Pendidikan: RP. %d\n", gaji2);

   // Hitung lama lembur
   if(jmlhJamKerja > 8) {
      gaji3 = ((jmlhJamKerja - 8) * 3000);
   } else if(jmlhJamKerja == 8) {
      gaji3 = (jmlhJamKerja * 0);
   } else {
      printf("Jumlah jam kerja anda kurang dari 8 jam\n");
      return 0;
   }
   printf ("    Honor Lembur: Rp. %d\n", gaji3);
   // Total gaji
   printf("Total Gaji: Rp. %d\n", (gajiPerBulan + gaji1 + gaji2 + gaji3));
   return 0;
}

