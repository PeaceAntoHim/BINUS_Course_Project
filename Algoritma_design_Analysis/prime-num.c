#include <stdio.h>

int angkaPrima(int N, int i)
{ // O (2)
   if (i == 1)
   {            // O (1)
      return 1; // O (1)
   }
   else
   {
      if (N % i == 0)
      {            // O (1)
         return 0; // O (1)
      }
      else
      {
         return angkaPrima(N, i - 1); // O (N log N)
      }
   }
}

int main()
{
   int bil, cek;
   printf("Masukan bilangan: ");
   scanf("%d", &bil); // O (1)
   cek = angkaPrima(bil, bil / 2);
   cek == 1 ? printf("%d ini adalah bilangan prima\n", bil) : printf("%d ini bukan bilangan prima\n", bil);
   return 0;
}

// f(x) = 2 + 1 + 1 + 1 + 1 + 1 + N log N
// f(x) = N log N + 7