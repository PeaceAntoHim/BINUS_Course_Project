#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct DataKaryawan
{
   int id;
   char namaLengkap[50];
   char tempatLahir[30];
   char tanggalLahir[15];
   char jabatan[21];
   struct DataKaryawan *next;
} * head, *tail, *curr;

void view()
{
   int i = 0, j = 0;
   printf("        --------------------- LIST EMPLOYEE -------------- \n\n");
   for (j = 0; j < 128; j++)
      printf("=");
   printf("\n");
   printf("| %-3s    |    %-6s    |   %-20s   |   %-15s   |   %-8s    |   %-8s    |\n",
          "No.", "ID", "Nama Lengkap", "Tempat Lahir", "Tanggal Lahir", "Jabatan");
   for (j = 0; j < 128; j++)
      printf("=");
   printf("\n");
   curr = head;
   while (curr)
   {
      i++;
      printf("| %3d.  |    %-12s    |   %-20s   |   %-15s   |   %8d     | %-15s     |\n",
             i, curr->id, curr->namaLengkap, curr->tempatLahir, curr->tanggalLahir, curr->jabatan);
      curr = curr->next;
   }
   for (j = 0; j < 128; j++)
      printf("=");
   printf("\n");
   getchar();
   fflush(stdin);
}

void push(int id, char namaLengkap[], char tempatLahir[], char tanggalLahir[], char jabatan[])
{

   if (countData() >= 5)
   {
      printf("Data karyawan sudah mencapai batas maksimal (5 data)\n");
      return;
   }

   curr = (struct DataKaryawan *)malloc(sizeof(struct DataKaryawan));
   curr->id = id;
   strcpy(curr->namaLengkap, namaLengkap);
   strcpy(curr->tempatLahir, tempatLahir);
   strcpy(curr->tanggalLahir, tanggalLahir);
   strcpy(curr->jabatan, jabatan);

   if (head == NULL)
   {
      head = tail = curr;
   }
   else
   {
      tail->next = curr;
      tail = curr;
   }
   tail->next = NULL;
}

void pop(int id)
{
   curr = head;
   while (curr != NULL)
   {
      curr = curr->next;
   }

   if (curr == NULL)
   {
      printf("    Id employee yang anda masukan tidak di temukan \n");
   }
   else if (head == curr)
   {
      head = head->next;
      free(curr);
      printf("    Id employee yang anda masukan telah berhasil di hapus \n");
   }
   else if (head != curr && tail != curr)
   {
      struct DataKaryawan *temp;
      temp = head;
      while (temp->next != curr)
         temp = temp->next;
      temp->next = curr->next;
      free(curr);
      printf("   Id employee yang anda masukan telah berhasil di hapus \n");
   }
   else if (tail == curr)
   {
      printf("    Id employee yang anda masukan tidak bisa di hapus karena employee terkahir\n");
   }
}

void popall()
{
   while (head != NULL)
   {
      curr = head;
      head = head->next;
      free(curr);
   }
}

int countData()
{
   int count = 0;
   curr = head;

   while (curr != NULL)
   {
      count++;
      curr = curr->next;
   }

   return count;
}

void sortData()
{
   if (head == NULL || head->next == NULL)
   {
      return;
   }

   struct DataKaryawan *next;

   int isSorted = 0;
   while (!isSorted)
   {
      isSorted = 1;

      curr = head;
      next = curr->next;

      while (next != NULL)
      {
         if (curr->id > next->id)
         {
            int tempId = curr->id;
            curr->id = next->id;
            next->id = tempId;

            char tempNamaLengkap[30];
            strcpy(tempNamaLengkap, curr->namaLengkap);
            strcpy(curr->namaLengkap, next->namaLengkap);
            strcpy(next->namaLengkap, tempNamaLengkap);

            char tempTempatLahir[30];
            strcpy(tempTempatLahir, curr->tempatLahir);
            strcpy(curr->tempatLahir, next->tempatLahir);
            strcpy(next->tempatLahir, tempTempatLahir);

            char tempTanggalLahir[15];
            strcpy(tempTanggalLahir, curr->tanggalLahir);
            strcpy(curr->tanggalLahir, next->tanggalLahir);
            strcpy(next->tanggalLahir, tempTanggalLahir);

            isSorted = 0;
         }

         curr = curr->next;
         next = curr->next;
      }
   }
}

void menu()
{
   printf("COMPUTER ADMINISTRATOR\n");
   printf("+++++++++++++++++++++++\n");
   printf("1. List Employee\n");
   printf("2. Add (PUSH) Data Employee Baru\n");
   printf("3. Hapus (POP) Data Employee Lama\n");
   printf("4. Keluar Program\n");
   printf(">> Input Pilihan : \n");
}

void clear()
{
   int i = 0;
   for (i = 0; i < 25; i++)
      printf("\n");
}

int main()
{
   int choice;
   int id;
   char namaLengkap[50];
   char tempatLahir[30];
   char tanggalLahir[15];
   int day, month, year;
   char jabatan[21];

   do
   {
      clear();
      menu();
      scanf("%d", &choice);
      fflush(stdin);
      switch (choice)
      {
      case 1:
         sortData();
         view();
         break;
      case 2:
         do
         {
            printf(" Masukan Employee Id . Note: (Maksimal 5 angka): ");
            scanf("%d", &id);
            fflush(stdin);
         } while (id >= 99999);
         printf("\n");
         do
         {
            printf(" Masukan nama lengkap employee. Note: (Tidak kurang dari 3 kata atau lebih dari 50 kata[3..50]): ");
            scanf("%[^\n]", namaLengkap);
            fflush(stdin);
         } while (strlen(namaLengkap) < 3 || strlen(namaLengkap) > 50);
         printf("\n");
         do
         {
            printf(" Masukan tempat lahir employee. Note: (Tidak kurang dari 3 kata atau lebih dari 30 kata[3..30]): ");
            scanf("%[^\n]", tempatLahir);
            fflush(stdin);
         } while (strlen(tempatLahir) < 3 || strlen(tempatLahir) > 30);
         printf("\n");
         do
         {
            printf(" Masukan tanggal lahir employee. Note: (format: dd-mm-yyyy): ");
            scanf("%d-%d-%d", &day, &month, &year);
            sprintf(tanggalLahir, "%d-%d-%d", &day, &month, &year);
            fflush(stdin);
         } while (day < 1 || day > 31 || month < 1 || month > 12 || year < 1);

         do
         {
            printf(" Masukan jabata employee. Note: tidak kurang dari 3 kata atau lebih dari 20 kata[3..20]: ");
            scanf("%[^\n]", jabatan);
            fflush(stdin);
         } while (strlen(jabatan) < 3 || strlen(jabatan) > 20);
         printf("\n");
         push(id, namaLengkap, tempatLahir, tanggalLahir, jabatan);
         printf("\n\n\n ---------- Data Employee baru berhasil di tambahkan ------------ \n");
         getchar();
         fflush(stdin);
         printf("\n");
         break;
      case 3:
         if (head == NULL)
         {
            printf(" List data employee kosong...");
         }
         else
         {
            do
            {
               printf(" Masukan id employee untuk menghapus data employee. Note id employee maksimal 5 angka: ");
               scanf("%d", &id);
               fflush(stdin);
            } while (id >= 99999);
            pop(id);
         }
         getchar();
         fflush(stdin);
         break;
      case 4:
         popall();
         break;
      case 5:
         break;
      default:
         printf("Pilihan anda tidak valid\n");
         break;
      };

   } while (choice != 5);
   return 0;
}
