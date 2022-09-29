
#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[], int &len, T e) // 1.5.1.1
{
   arr[len] = e;
   len++;
   return len - 1;
}

template <typename T>
void insert(T arr[], int &len, T e, int p) // 1.5.1.2
{
   for (int i = len; i > p; i--)
   {
      arr[i] = arr[i - 1];
   }
   arr[p] = e;
   len++;
}

template <typename T>
T remove(T arr[], int &len, int p) // 1.5.1.3
{
   T ret = arr[p];
   for (int i = p; i < len; i++)
   {
      arr[i] = arr[i + 1];
   }
   len--;
   return ret;
}

template <typename T, typename K>
int find(T arr[], int len, K k, int cmpTK(T, K)) // 1.5.1.4
{
   for (int i = 0; i < len; i++)
   {
      T t = arr[i];
      if (cmpTK(t, k) == 0)
         return i;
   }
   return -1;
}

template <typename T>
int orderedInsert(T arr[], int &len, T e, int cmpTT(T, T)) // 1.5.1.5
{
   int i = 0;
   while (cmpTT(arr[i], e) <= 0 && i < len)
   {
      i++;
   }
   insert<T>(arr, len, e, i);
   return i;
}

template <typename T>
void sort(T arr[], int len, int cmpTT(T, T)) // 1.5.1.6
{
   // Insertion Sort
   for (int i = 1; i < len; i++)
   {
      int j = i;
      while ((j > 0) && (cmpTT(arr[j - 1], arr[j]) > 0))
      {
         // Swap
         T a = arr[j - 1];
         T b = arr[j];
         arr[j - 1] = b;
         arr[j] = a;
         j -= 1;
      }
   }
}

#endif
