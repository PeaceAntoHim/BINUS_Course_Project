#include <stdio.h>

int main()
{
    int nilai1, nilai2;
    char op;
    
    printf("Masukkan perhitungan = "); scanf("%d %c %d", &nilai1, &op, &nilai2);

    switch(op)
    {
        case '+' :
            {
                printf("Hasil penjumlahan = %d\n", nilai1+nilai2);
                break;
            }
        case '-' :
            {
                printf("Hasil pengurangan = %d\n", nilai1-nilai2);
                break;
            }
        case '*' :
            {
                printf("Hasil perkalian = %d\n", nilai1*nilai2);
                break;
            }
        case '/' :
            {
                printf("Hasil pembagian = %d\n", nilai1/nilai2);
                break;
            }
        default:
            {
                printf("Unknown operator");
                break;
            }
    }

    return 0;
}
