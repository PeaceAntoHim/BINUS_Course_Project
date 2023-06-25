#include <stdio.h>

int main()
{
    int arr[] = {10,20,30,40,50};
    int *ptr;
    
    ptr = arr;
    printf("Isi pointer adalah %i\n",*ptr);
    ptr+=2;
    printf("Isi pointer adalah %i\n",*ptr);
    ptr--;
    printf("Isi pointer adalah %i\n",*ptr);
    
    return 0;
}
