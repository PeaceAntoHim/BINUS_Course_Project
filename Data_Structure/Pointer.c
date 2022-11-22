

#include <stdio.h>

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

   return 0;
}
