//Menampilkan deret bilangan prima
//2, 3, 5, 7, 11, 13, ...
#include <stdio.h>

int isPrime(int bil)
{
    //Prima = bilangan yang hanya bisa dibagi dirinya sendiri
    int pembagi = 1;
    char Prima = 1;
    
    do
    {
        pembagi++;
        if (bil % pembagi == 0) //habis dibagi
        {
            Prima = 0;
        }
    } while ((Prima == 1) && (bil - pembagi > 1));
    
    return Prima;
}

void CetakPrima(int jum)
{
    int bil = 1;
    int jum_tercetak = 0;
    
    do
    {
        bil++;
        
        if ((bil == 2) || (isPrime(bil) == 1))
        {
            printf("%d ", bil);
            jum_tercetak++;
        }
        
    } while (jum_tercetak < jum);
}

int main()
{
    int jum;
    
    printf("Masukkan jumlah bilangan prima yang mau ditampilkan = "); scanf("%d", &jum);
    CetakPrima(jum);

    return 0;
}
