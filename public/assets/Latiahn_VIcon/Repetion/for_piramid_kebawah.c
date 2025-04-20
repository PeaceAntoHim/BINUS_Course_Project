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
}


// variasi kedua


#include <stdio.h>

//n=5
//54321
//5432
//543
//54
//5
int main()
{
    int jumlah;
    
    printf("Masukkan jumlah angka = "); scanf("%d", &jumlah);

    for (int baris = jumlah; baris >= 1; baris--)
    {
        for(int kolom = jumlah; kolom >= baris; kolom--)
        {
            printf("%d ", kolom);
        }
        
        printf("\n");
    }

    return 0;
}


// versi kedua

#include <stdio.h>

//n=5
//54321
//5432
//543
//54
//5
int main()
{
    int jumlah;
    
    printf("Masukkan jumlah angka = "); scanf("%d", &jumlah);

    for (int baris = 1; baris <= jumlah; baris++)
    {
        for(int kolom = jumlah; kolom >= baris; kolom--)
        {
            printf("%d ", kolom);
        }
        
        printf("\n");
    }

    return 0;
}


