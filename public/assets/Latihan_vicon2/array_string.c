#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "abc";
    char s2[] = "def";

    strncpy(s1, s2, 2);    
    printf("Isi s1 = %s\n",s1);
    printf("Isi s2 = %s\n",s2);
    
    return 0;
}
