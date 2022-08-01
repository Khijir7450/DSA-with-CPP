#include <iostream>
using namespace std;
int main()
{
   int r, c;
   cout << "Enter number of row:";
   cin >> r;
   cout << "Enter number of column:";
   cin >> c;
   int **p = new int *[r];
   for (int i = 0; i < r; i++)
   {
      p[i] = new int[c];
   }
   cout << "Enter array element:" << endl;
   for (int i = 0; i < r; i++)
   {
      for (int j = 0; j < c; j++)
      {
         cin >> p[i][j];
      }
   }
   cout << endl
        << "Your array is:" << endl;
   for (int i = 0; i < r; i++)
   {
      for (int j = 0; j < c; j++)
      {
         cout << p[i][j] << " ";
      }
      cout << endl;
   }
   for (int i = 0; i < r; i++)
   {
      delete[] p[i];
   }
   delete[] p;

   return 0;
}