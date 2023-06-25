#include <stdio.h>
#include <string.h>

int main()
{
    FILE *ptr;
    char hasil[80];
    char namafile[50], kalimat[50];
    int counter=0;
    
    printf("Masukkan nama file = "); scanf(" %[^\n]", namafile);
    ptr = fopen(namafile, "r");
    
    if (ptr == NULL)
    {
        printf("File tidak ada\n");
    }
    else
    {
        //printf("Masukkan kalimat = "); scanf(" %[^\n]", kalimat);
        while (fgets(hasil, 10, ptr))
        {
            counter++;
            
            printf("Hasil pembacaan ke-%i = %s\n", counter, hasil);
        }
    }
    
    fclose(ptr);

    return 0;
}
