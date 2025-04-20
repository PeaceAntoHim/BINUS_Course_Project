#include <stdio.h>
#include <string.h>

int main()
{
    FILE *src, *dst;
    char hasil[80];
    char nama_src[50], nama_dst[50];

    printf("Masukkan nama file asal = "); scanf(" %[^\n]", nama_src);
    src = fopen(nama_src, "r");
    
    if (src == NULL)
    {
        printf("File tidak ada\n");
    }
    else
    {
        printf("Masukkan nama file tujuan = "); scanf(" %[^\n]", nama_dst);
        dst = fopen(nama_dst, "w");
        
        if (dst == NULL)
        {
            printf("File gagal dibuat\n");
        }
        else
        {
            while (fgets(hasil, 80, src))
            {
                fputs(hasil, dst);
            }
        }
    }
    
    fclose(src);
    fclose(dst);

    return 0;
}
