#include <stdio.h>

#include <stdlib.h>

void mergesort(int key[], int n);

void merge(int a[], int b[], int c[], int m, int n);

int main(void)
{

   int i, key[8] = {12, 10, 45, 11, 9, 23, 4, 17};

   mergesort(key, 8);

   for (i = 0; i < 8; ++i)

      printf("%d\t", key[i]);

   return 1;
}

void mergesort(int key[], int n)
{

   int j, k, m, *w;

   for (m = 1; m < n; m *= 2)
      ;

   if (m != n)
   {

      printf("jumlah arraynya salah ");

      exit(1);
   }

   w = calloc(n, sizeof(int));

   assert(w != NULL);

   for (k = 1; k < n; k *= 2)
   {

      for (j = 0; j < n - k; j += 2 * k)

         merge(key + j, key + j + k, w + j, k, k);

      for (j = 0; j < n; ++j)

         key[j] = w[j];
   }

   free(w);
}

void merge(int a[], int b[], int c[], int m, int n)
{

   int i = 0, j = 0, k = 0;

   while (i < m && j < n)

      if (a[i] < b[j])

         c[k++] = a[i++];

      else

         c[k++] = b[j++];

   while (i < m)

      c[k++] = a[i++];

   while (j < n)

      c[k++] = b[j++];
}
