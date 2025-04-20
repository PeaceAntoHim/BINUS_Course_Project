#include <stdio.h>
#include <stdlib.h>

// Definisi tipe data node
typedef struct node
{
   int data;
   struct node *next;
} Node;

// Definisi linked list
typedef struct
{
   Node *head;
   Node *tail;
} List;

// Fungsi untuk membuat linked list baru
List *create_list()
{
   List *new_list = (List *)malloc(sizeof(List));
   new_list->head = NULL;
   new_list->tail = NULL;
   return new_list;
}

// Fungsi untuk menambahkan elemen baru ke dalam circular singly linked list
void push(List *list, int data)
{
   Node *new_node = (Node *)malloc(sizeof(Node));
   new_node->data = data;
   if (list->head == NULL)
   {
      // Jika linked list masih kosong, elemen baru menjadi head dan tail
      new_node->next = new_node;
      list->head = new_node;
      list->tail = new_node;
   }
   else
   {
      // Jika linked list sudah ada elemen, elemen baru menjadi tail
      list->tail->next = new_node;
      list->tail = new_node;
      // Pointer next dari tail menunjuk ke head
      list->tail->next = list->head;
   }
}

int main()
{
   // Membuat linked list baru
   List *list = create_list();

   // Menambahkan elemen ke dalam linked list
   push(list, 10);
   push(list, 20);
   push(list, 30);

   // Menampilkan elemen dalam linked list
   Node *curr = list->head;
   do
   {
      printf("%d\n", curr->data);
      curr = curr->next;
   } while (curr != list->head);

   return 0;
}
