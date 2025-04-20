#include <stdio.h>

#include <string.h>

 

int main()

{

  // set vaiable string dan integer

  char Str[500];

  int index;
 

  printf("Masukan Kalimat = ");

  //Input data

  scanf("%[^\n]", Str);

  /* logika perulangan menggunakan for 

  jika tidak sama dengan 0 */
  

  for (index = 0; Str[index] != '\0'; ++index);

  printf("Panjang kalimat = %d", index);

 

  return 0;

}