
#include <stdio.h>

int main(int N) // O (1)
{
   int jumlah = 0; // 0 (1)
   for (int i = N / 2; i <= N; i++)
   { // O (N)
      for (int j = 1; j <= N; j = 2 * j)
      {
         for (int k = 1; k <= N; k = k * 2)
         {
            jumlah++;
         }
      }
   }
   printf("jumlah %d", jumlah);

   return 0;
}
