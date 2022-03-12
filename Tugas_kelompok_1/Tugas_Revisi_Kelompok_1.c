
#include <stdio.h>
int ganjil, genap;

int
main ()
{
  printf ("masukkan bilangan ganjil:");
  scanf ("%d", &ganjil);
  printf ("masukkan bilangan genap:");
  scanf ("%d", &genap);

  if (ganjil % 2 != 0)
    {
      printf ("%d adalah ganjil\n", ganjil);
    }
  else
    {
      printf ("%d bukan ganjil\n", ganjil);
    }
  if (genap % 2 == 0)
    {
      printf ("%d adalah genap\n", genap);
    }
  else
    {
      printf ("%d bukan genap\n", genap);
      return 0;
    }
  int jumlah = ganjil + genap;
  float rata_rata = jumlah / 2.0;
  int kuadrat_ganjil = ganjil * ganjil;
  int kuadrat_genap = genap * genap;

  printf ("jumlah dua bilangan tersebut adalah : %d \n", jumlah);
  printf ("rata-rata kedua bilangan adalah : %f \n", rata_rata);
  printf ("kuadrat bilangan ganjil : %d \n", kuadrat_ganjil);
  printf ("kuadrat bilangan genap : %d \n", kuadrat_genap);
}

