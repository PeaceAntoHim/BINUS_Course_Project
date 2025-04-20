#include <iostream>
using namespace std;
int main()
{
   int iNilaiCari{359};
   int iMaxCari{361};
   int iJumKoin{6};
   long iJumKemungkinan{0};
   int koin[]{1, 5, 10, 25, 50, 100};
   unsigned long long int C[361];
   bool bBisaDicari{true};
   for (int i = 0; i <= iMaxCari; i++)
   {
      C[i] = 0;
   }
   for (int j = 0; j < iJumKoin; j++)
   {
      C[koin[j]] = 1;
   }
   for (int n = 1; n < iMaxCari; n++)
   {
      for (int j = 0; j < iJumKoin; ++j)
      {
         if ((n - koin[j]) >= 1)
         {
            C[n] = C[n] + C[n - koin[j]];
         }
      }
   }
   if (C[iNilaiCari] > 0)
   {
      bBisaDicari = true;
      cout << "USD " << iNilaiCari << " bisa ditukar dengan " << C[iNilaiCari] << " kombinasi uang pecahan";
   }
   else
   {
      bBisaDicari = false;
      cout << "USD " << iNilaiCari << " tidak bisa ditukar kombinasi uang pecahan";
   }
   return 0;
}