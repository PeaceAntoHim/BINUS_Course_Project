#include <stdio.h>

int main()
{
    char nama[50];
    
    printf("Masukkan nama = "); scanf("%[^\n]", nama);
    printf("Nama = %s", nama);

    return 0;
}
