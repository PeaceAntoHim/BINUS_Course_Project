#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

/* Fungsi untuk mengembalikan elemen teratas dari stack tanpa menghapusnya. */
char peek(char *stack, int *top)
{
   return stack[*top];
}

/* Fungsi untuk menghapus elemen teratas dari stack. */
char pop(char *stack, int *top)
{
   char elem = stack[*top];
   (*top)--;
   return elem;
}

/* Fungsi untuk menambahkan elemen baru ke stack. */
void push(char *stack, int *top, char elem)
{
   (*top)++;
   stack[*top] = elem;
}

/* Fungsi untuk membalikkan string dengan menggunakan stack. */
char *reverse_string(char *string)
{
   int i, length, top = -1;
   char *reversed_string, stack[STACK_SIZE];

   length = strlen(string);
   reversed_string = (char *)malloc(length + 1);

   /* Pindahkan karakter-karakter dari string ke stack. */
   for (i = 0; i < length; i++)
   {
      push(stack, &top, string[i]);
   }

   /* Pop karakter-karakter dari stack dan simpan di reversed_string. */
   for (i = 0; i < length; i++)
   {
      reversed_string[i] = pop(stack, &top);
   }

   reversed_string[length] = '\0';
   return reversed_string;
}

int main()
{
   char *string;
   char *reversed_string;
   // Ini inputan untuk menjadi data kata yang ingin di balik
   printf("Masukan kata yang ingin di balik: ");
   scanf("%[^\n]", string);
   // Ini untuk membalikan kata berupa string
   reversed_string = reverse_string(string);

   printf("Original string: %s\n", string);
   printf("Reversed string: %s\n", reversed_string);

   free(reversed_string);

   return 0;
}
