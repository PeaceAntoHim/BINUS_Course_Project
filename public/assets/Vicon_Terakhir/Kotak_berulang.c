//Menampilkan kotak berisi suatu kata yang berulang
//Input kalimat = Binus
//Panjang kotak = 12
//Tinggi kotak = 3
//
//Output:
// BinusBinusBi
// nusBinusBinu
// sBinusBinusB

#include <stdio.h>
#include <string.h>

int main()
{
    int jum_huruf, panjang, tinggi, posisi;
    char kata[10];
    
    printf("Masukkan kata = "); scanf("%s", kata);
    printf("Panjang kotak = "); scanf("%d", &panjang);
    printf("Tinggi kotak  = "); scanf("%d", &tinggi);
    
    jum_huruf = strlen(kata);
    posisi = 0;
    
    for (int y=1; y <= tinggi; y++)
    {
        for (int x=1; x <= panjang; x++)
        {
            putchar(kata[posisi]);
            posisi++;
            if (posisi == jum_huruf) posisi = 0;
        }
        
        printf("\n");
    }
    
    return 0;
}
