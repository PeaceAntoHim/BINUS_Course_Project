#include <stdio.h>
#include <stdlib.h>

// Created SingleLinkedList

struct Data
{
   int value;
   struct Data *next;
} * head, *tail;

void pushHead(int x)
{
   struct Data *node = malloc(sizeof(struct Data));
   node->value = x;
   (*node).next = NULL;

   // created validation
   if (head == NULL)
   {
      head = tail = node;
   }
   else
   {
      node->next = head;
      head = node;
   }
}

void print()
{
   if (head != NULL)
   {
      struct Data *curr = head;
      while (curr != NULL)
      {
         printf("%d ", curr->value);
         curr = curr->next;
      }
   }
   else
   {
      printf("Data Kosong\n");
   }
}

int main()
{
   pushHead(30);
   pushHead(10);
   pushHead(40);
   pushHead(20);
   pushHead(50);

   print();

   return 0;
}
