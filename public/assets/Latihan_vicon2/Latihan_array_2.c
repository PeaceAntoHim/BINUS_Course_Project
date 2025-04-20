#include <stdio.h>
#include <string.h>

int main() {
    char hVokal[] = "aiueoAIUEO";
    char kalimat[100];
    char hasil[100];
    
    printf("Masukan Kalimat = ");
    scanf("%[^\n]", kalimat);
    
    for(int k=0; k<strlen(kalimat); ++k) {
        hasil[k] = kalimat[k];
       for(int h=0; h<strlen(hVokal); ++h) {
           if(kalimat[k] == hVokal[h]) {
               hasil[k]= ' ';
               break;
           }
       } 
    }
    
    printf("Hasil = %s", hasil);
    return 0;
    
}