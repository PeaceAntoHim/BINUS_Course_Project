

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa
{
   char NIM[10];
   char nama[100];
   int umur;
   float IPK;
};

int main()
{
   struct Mahasiswa mhs;
   strcpy(mhs.NIM, "25022121162");
   strcpy(mhs.nama, "Frans Sebastian");
   mhs.umur = 19;
   mhs.IPK = 3.98;

   printf("NIM =%s\n", mhs.NIM);
   printf("Nama = %s\n", mhs.nama);
   printf("Umur = %d\n", mhs.umur);
   printf("IPK = %.2f\n", mhs.IPK);

   return 0;
}
