#include <stdio.h>
#include <string.h>

int main()
{
    FILE *ptr;
    char kar;
    char namafile[50], kalimat[50];
    
    printf("Masukkan nama file = "); scanf(" %[^\n]", namafile);
    ptr = fopen(namafile, "a");
    
    if (ptr == NULL)
    {
        printf("File tidak ada\n");
    }
    else
    {
        printf("Masukkan kalimat = "); scanf(" %[^\n]", kalimat);
        
        fputc('\n', ptr);
        for (int i=0; i<strlen(kalimat); i++)
        {
            fputc(kalimat[i], ptr);
        }
    }
    
    fclose(ptr);

    return 0;
}
