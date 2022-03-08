#include <stdio.h>

int main()
{
    int nilai1, nilai2;
    char op;
    
    printf("Masukkan perhitungan = "); scanf("%d %c %d", &nilai1, &op, &nilai2);
    
    if (op == '+') 
    {
        printf("Hasil penjumlahan = %d\n", nilai1+nilai2);
    }
    else if (op == '-') 
    {
        printf("Hasil pengurangan = %d\n", nilai1-nilai2);
    }
    else if (op == '*') 
    {
        printf("Hasil perkalian = %d\n", nilai1*nilai2);
    }
    else if (op == '/') 
    {
        printf("Hasil pembagian = %d\n", nilai1/nilai2);
    }
    else  
    {
        printf("Unknown operator");
    }
    
    return 0;
}
