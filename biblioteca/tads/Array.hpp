
#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template <typename T>
struct Array // 1.6.1.1
{
   T *arr;
   int len;
   int size;
};

template <typename T>
Array<T> array() // 1.6.1.2
{
   Array<T> ret;
   ret.len = 0;
   ret.size = 5;
   ret.arr = new T[ret.size];
   return ret;
}

template <typename T>
T *arrayResize(Array<T> &a)
{
   a.size *= 2;
   T *arr = new T[a.size];
   for (int i = 0; i < a.len; i++)
   {
      arr[i] = a.arr[i];
   }
   delete a.arr;
   return arr;
}

template <typename T>
int arrayAdd(Array<T> &a, T t) // 1.6.1.3
{
   if (a.len == a.size)
   {
      a.arr = arrayResize<T>(a);
   }
   return add<T>(a.arr, a.len, t);
}

template <typename T>
T *arrayGet(Array<T> a, int p) // 1.6.1.4
{
   // T *item = &(a.arr[p]);
   return &(a.arr[p]);
}

template <typename T>
void arraySet(Array<T> &a, int p, T t) // 1.6.1.5
{
   T *item = arrayGet<T>(a, p);
   *item = t;
}

template <typename T>
void arrayInsert(Array<T> &a, T t, int p) // 1.6.1.6
{
   if (a.len == a.size)
   {
      a.arr = arrayResize<T>(a);
   }
   insert<T>(a.arr, a.len, t, p);
}

template <typename T>
int arraySize(Array<T> a) // 1.6.1.7
{
   return a.len;
}

template <typename T>
T arrayRemove(Array<T> &a, int p) // 1.6.1.8
{
   T removed = remove<T>(a.arr, a.len, p);
   return removed;
}

template <typename T>
void arrayRemoveAll(Array<T> &a) // 1.6.1.9
{
   T *arr = new T[a.size];
   delete a.arr;
   a.len = 0;
   a.arr = arr;
}

template <typename T, typename K>
int arrayFind(Array<T> a, K k, int cmpTK(T, K)) // 1.6.1.10
{
   return find<T, K>(a.arr, a.len, k, cmpTK);
}

template <typename T>
int arrayOrderedInsert(Array<T> &a, T t, int cmpTT(T, T)) // 1.6.1.11
{
   if (a.len == a.size)
   {
      a.arr = arrayResize<T>(a);
   }
   return orderedInsert<T>(a.arr, a.len, t, cmpTT);
}

template <typename T>
void arraySort(Array<T> &a, int cmpTT(T, T)) // 1.6.1.12
{
   sort<T>(a.arr, a.len, cmpTT);
}

#endif
