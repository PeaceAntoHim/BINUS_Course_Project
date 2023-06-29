#include <stdio.h>
#include <string.h>
char kalimat_1[250]; 
char kalimat_2[250];
char temp;
char gabungan[250];

int main()
{
    printf("Kalimat 1: "); scanf("%[^\n]", kalimat_1);
    
    scanf("%c",&temp);
    printf("Kalimat 2: "); scanf("%[^\n]", kalimat_2);
    strcpy(gabungan, kalimat_1);
    
    strcat(gabungan, " "); strcat(gabungan, kalimat_2);
    printf("Gabungan 2 buah inputan kalimat = %s\n", gabungan);
    
    int panj_gabungan = strlen(gabungan);
    char rev_gabungan[250];
    
    for(int i= 0; i<panj_gabungan; i++){ 
        int index_gabungan = panj_gabungan - 1 - i;
        rev_gabungan[i]= gabungan[index_gabungan];
    }
    printf("Hasil membalik kalimat gabungan = %s\n", rev_gabungan);
    
    int jumlah_1 = strlen(kalimat_1);
    printf("Jumlah Huruf kalimat pertama = %d\n", jumlah_1);
    int jumlah_2 = strlen(kalimat_2);
    printf("Jumlah Huruf kalimat kedua = %d\n", jumlah_2);
    int jumlah_gabungan = jumlah_1 + jumlah_2;
    printf("Total Jumlah huruf = %d\n", jumlah_gabungan);
    int jumlah_perkalian = jumlah_1 * jumlah_2;
    printf("Total Perkalian kalimat = %d\n", jumlah_perkalian);
    
    
    /*printf("gabungan inputan 2 buah kalimat = %s %s", kalimat_1, kalimat_2);
    int panj_k1 = strlen(kalimat_1)-1;
    for (int i=panj_k1; i>=0, i--){
        
    }
    */
    
    
    return 0;
}
