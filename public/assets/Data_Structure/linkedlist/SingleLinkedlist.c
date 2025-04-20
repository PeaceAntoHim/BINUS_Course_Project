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

// Create popHead
void popHead()
{
   if (head != NULL)
   {
      if (head == tail)
      {
         free(head);
         head = tail = NULL;
      }
      else
      {
         struct Data *node = head;
         head = node->next;
         free(node);
         node = NULL;
      }
   }
}

// Created popTail
void popTail()
{
   if (head != NULL)
   {
      if (head == tail)
      {
         free(head);
         head = tail = NULL;
      }
      else
      {
         struct Data *curr = head;
         while (curr->next != tail)
         {
            curr = curr->next;
         }
         tail = curr;
         free(tail->next);
         tail->next = NULL;
      }
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
   printf("\n");

   popTail();
   popTail();
   popTail();
   popTail();
   popTail();

   //   popHead();
   //      popHead();
   //       popHead();
   //          popHead();
   //           popHead();

   print();

   return 0;
}
