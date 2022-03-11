#include <stdio.h>

int main() {
   int ganjil, genap;

     printf("Masukan Angka ganjil = "); scanf("%d", &ganjil);
   if (ganjil % 2 != 0) {
      printf("%d\n", ganjil);
      printf("%d\n", (ganjil += ganjil));
      printf("%d\n", ((ganjil + ganjil) / 3));
      printf("%d\n", (ganjil ^ ganjil));
   } else {
      printf("Yang anda masukan bukan angka ganjil\n");
   }
   

   printf("Masukan Angka genap =  "); scanf("%d", &genap);

   if (genap % 2 == 0) {
      printf("%d\n", genap);
   } else {
      printf("Yang anda masukan bukan angka genap\n");
   }
 
}


