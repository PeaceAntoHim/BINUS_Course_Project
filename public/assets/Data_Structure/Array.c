#include <stdio.h>

int main()
{
    int age[3];
    char name[3][50];
    
    for(int i = 0; i<3; i++) {
        printf("Masukan umur ke-%d: ", i+1);
        scanf("%d", &age[i]);
        getchar();
        printf("Masukan name ke-%d: ", i+1);
        scanf("%[\n]", &name[i]);
        getchar();
    }
    
    for(int i= 0; i<3;i++) {
        printf("Nama ke-%d: %s\n", i+1, name[i]);
        printf("Umur ke-%d: %d\n", i+1, age[i]);
    }
    
    return 0;
}
