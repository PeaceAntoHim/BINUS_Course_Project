/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
void
main ()
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
