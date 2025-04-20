#include <stdio.h>
#include <string.h>

int main() {
    FILE *in;
    in = fopen("sumber.txt", "r");
    char kalimat[250];
    char hVokal[] = "aiueoAUIEO";
    char hasil[250];
    
    if(!in) {
        perror("File not found");
        getchar();
        return 1;
    }
    
    while(!feof(in)) {
        fscanf(in, "%[^\n]\n", kalimat);
        puts(kalimat);
        
            for(int k=0; k<strlen(kalimat); ++k) {
            hasil[k] = kalimat[k];
            for(int h=0; h<strlen(hVokal); ++h) {
                if(kalimat[k] == hVokal[h]) {
                    hasil[k]= ' ';
                   
                }
            } 
        }
        puts(hasil);
    }
    
    
 return 0;   
}