
#include <stdio.h>

void main ()
{
  int angka, isian;

  printf ("Jumlah bilangan ganjil : ");
  scanf ("%d", &isian);

  printf ("hasil = ");
  for (angka = 1; angka <= isian; angka++)
    {
      printf ("%d ", 2 * angka - 1);
    }
}
