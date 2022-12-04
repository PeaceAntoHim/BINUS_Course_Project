#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stokBarang
{
   char jenisBarang;
   int jumlahBarangAwal;
   int selisiJumlahBarang;
   int hargaBarang;
   struct stokBarang *next;
} * head, *tail, *curr;

int main()
{

   printf("Hello World");

   return 0;
}
