#include <stdio.h>

//Mencetak deret bilangan kelipatan 5
//5 10 15 20 ...
//Mencetak deret bilangan kelipatan 3
//3 6 9 12 ...
int main()
{
    int jumlah, kelipatan;
    
    printf("Masukkan jumlah angka yang mau dicetak = "); scanf("%d", &jumlah);
    printf("Kelipatan berapa ? "); scanf("%d", &kelipatan);
    
    for (int i = 1; i <= jumlah; i++)
    {
        printf("%d ", i*kelipatan);
    }

    return 0;
}
