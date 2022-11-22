

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int value = 10;
   int *pointer = &value;
   // Double pointer or pointer to pointer
   int **pointer2 = &pointer;

   printf("Value = %d\n", value);
   printf("Pointer = %d\n", pointer);
   printf("Address of value = %d\n", &value);
   printf("Address of pointer = %d\n", &pointer);

   // we can access variable value use dereference with asterisk
   printf("*pointer = %d\n", *pointer);

   // We can change the variable value use pointer like this
   *pointer = 50;
   printf("value = %d\n", value);
   printf("*pointer = %d\n", *pointer);

   // pointer to pointer will used when we created linked list
   printf("pointer2 = %d\n", *pointer);
   printf("pointer2 = %d\n", &pointer2);

   // Created pointer with memory allocation than we used type casting
   int *p = (int *)malloc(sizeof(int));
   *p = 30;
   printf("*p = %d\n", *p);
   // This will dealocate the memory
   free(p);
   // printf("*p = %d\n", *p);
   return 0;
}
