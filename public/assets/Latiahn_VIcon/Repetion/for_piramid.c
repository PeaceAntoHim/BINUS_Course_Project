#include <stdio.h>

//n=5
//1
//12
//123
//1234
//12345
int main()
{
    int jumlah;
    
    printf("Masukkan jumlah angka = "); scanf("%d", &jumlah);

    for (int baris = 1; baris <= jumlah; baris++)
    {
        for(int kolom = 1; kolom <= baris; kolom++)
        {
            printf("%d ", kolom);
        }
        
        printf("\n");
    }

    return 0;
}
