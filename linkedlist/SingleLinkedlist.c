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

void pushTail(int x)
{
   struct Data *node = (struct Data *)malloc(sizeof(struct Data));
   node->value = x;
   node->next = NULL;

   if (head == NULL)
   {
      head = tail = node;
   }
   else
   {
      tail->next = node;
      tail = node;
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
   //   pushHead(30);
   //   pushHead(10);
   //   pushHead(40);
   //   pushHead(20);
   //   pushHead(50);

   pushTail(20);
   pushTail(10);
   pushTail(40);
   pushTail(30);
   pushTail(50);

   print();

   return 0;
}
