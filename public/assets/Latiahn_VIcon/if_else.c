#include <stdio.h>

int main()
{
    int nilai;
    char grade;
    
    printf("Masukkan nilai = "); scanf("%d", &nilai);
    
    if (nilai > 84) 
    {
        grade = 'A';
    }
    else if (nilai > 74) 
    {
        grade = 'B';
    }
    else if (nilai > 64) 
    {
        grade = 'C';
    }
    else if (nilai > 49) 
    {
        grade = 'D';
    }
    else  
    {
        grade = 'E';
    }
    
    printf("Grade anda = %c", grade);
    return 0;
}
