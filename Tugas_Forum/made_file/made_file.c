#include <stdio.h>
#include <string.h>

int main() {
    FILE *in;
    in = fopen("sumber.txt", "r");
    char kalimat[250];
    char vokal[] = "aiueoAUIEO";
    
    if(!in) {
        perror("File not found");
        getchar();
        return 1;
    }
    
    while(!feof(in)) {
        fscanf(in, "%[^\n]\n", text);
        puts(kalimat);
        
        for(int k=0; k<strlen(kalimat); ++k) {
        hasil[k] = kalimat[k];
        for(int h=0; h<strlen(hVokal); ++h) {
            if(kalimat[k] == hVokal[h]) {
                hasil[k]= ' ';
                break;
            }
        } 
        }
    
        
        puts(kalimat);
    }
 return 0;   
}