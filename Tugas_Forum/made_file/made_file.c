#include <stdio.h>
#include <string.h>

int main() {
    FILE *in;
    in = fopen("sumber.txt", "r");
    char text[250];
    char vokal[] = "aiueoAUIEO";
    
    if(!in) {
        perror("File not found");
        getchar();
        return 1;
    }
    
    while(!feof(in)) {
        fscanf(in, "%[^\n]\n", text);
        puts(text);
        
          for(int i = 0; i < strlen(text); i++){
            for(int j = 0; j < 10; j++){
                if(text[i] == vokal[j]){
                    text[i] = "";
                }
            }
        }
        
        puts(text);
    }
 return 0;   
}