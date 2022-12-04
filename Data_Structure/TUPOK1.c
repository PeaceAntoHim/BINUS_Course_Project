
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stokBarang
{
   char jenisBarang;
   int jumlahBarangAwal;
   int selisiJumlahBarang;
   struct stokBarang *next;
} * head, *tail, *curr;

int main()
{

   printf("Hello World");

   return 0;
}