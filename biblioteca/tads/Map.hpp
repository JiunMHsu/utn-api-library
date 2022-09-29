
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Array.hpp"

using namespace std;

template <typename K, typename V>
struct Map // 1.6.2.1
{
   Array<K> keys;
   Array<V> values;
   int mapIndex;
};

template <typename K, typename V>
Map<K, V> map() // 1.6.2.2
{
   Map<K, V> m;
   m.keys = array<K>();
   m.values = array<V>();
   return m;
}

template <typename K, typename V>
int mapKeyIndex(Map<K, V> m, K k) // aux function
{
   for (int i = 0; i < arraySize<K>(m.keys); i++)
   {
      K *key = arrayGet<K>(m.keys, i);
      if (*key == k)
         return i;
   }
   return -1;
}

template <typename K, typename V>
V *mapGet(Map<K, V> m, K k) // 1.6.2.3
{
   int i = mapKeyIndex<K, V>(m, k);
   if (i > -1)
   {
      V *value = arrayGet<V>(m.values, i);
      return value;
   }
   return NULL;
}

template <typename K, typename V>
V *mapPut(Map<K, V> &m, K k, V v) // 1.6.2.4
{
   V *value = mapGet<K, V>(m, k);
   if (value != NULL)
   {
      *value = v;
   }
   else
   {
      arrayAdd<K>(m.keys, k);
      arrayAdd<V>(m.values, v);
      value = mapGet<K, V>(m, k);
   }
   return value;
}

template <typename K, typename V>
bool mapContains(Map<K, V> m, K k) // 1.6.2.5
{
   if (mapGet<K, V>(m, k) == NULL)
   {
      return false;
   }
   return true;
}

template <typename K, typename V>
V mapRemove(Map<K, V> &m, K k) // 1.6.2.6
{
   int i = mapKeyIndex<K, V>(m, k);
   arrayRemove<K>(m.keys, i);
   return arrayRemove<V>(m.values, i);
}

template <typename K, typename V>
void mapRemoveAll(Map<K, V> &m) // 1.6.2.7
{
   arrayRemoveAll<K>(m.keys);
   arrayRemoveAll<V>(m.values);
}

template <typename K, typename V>
int mapSize(Map<K, V> m) // 1.6.2.8
{
   return arraySize<V>(m.values);
}

template <typename K, typename V>
bool mapHasNext(Map<K, V> m) // 1.6.2.9
{
   // bool hasNext = (m.mapIndex < mapSize<K, V>(m) - 1) ? true : false;
   return (m.mapIndex < mapSize<K, V>(m) - 1) ? true : false;
}

template <typename K, typename V>
K mapNextKey(Map<K, V> &m) // 1.6.2.10
{
   m.mapIndex++;
   K *k = arrayGet<K>(m.keys, m.mapIndex);
   return *k;
}

template <typename K, typename V>
V *mapNextValue(Map<K, V> &m) // 1.6.2.11
{
   m.mapIndex++;
   return arrayGet<V>(m.values, m.mapIndex);
}

template <typename K, typename V>
void mapReset(Map<K, V> &m) // 1.6.2.12
{
   m.mapIndex = -1;
}

// Modificar (simplificar)

template <typename K, typename V>
void mapSortByKeys(Map<K, V> &m, int cmpKK(K, K)) // 1.6.2.13
{
   for (int i = 1; i < mapSize<K, V>(m); i++)
   {
      int j = i;
      while ((j > 0) && (cmpKK(*arrayGet<K>(m.keys, j - 1), *arrayGet<K>(m.keys, j)) > 0))
      {
         // Swap Key
         K key = *arrayGet<K>(m.keys, j - 1);
         *arrayGet<K>(m.keys, j - 1) = *arrayGet<K>(m.keys, j);
         *arrayGet<K>(m.keys, j) = key;

         // Swap Value
         V value = *arrayGet<V>(m.values, j - 1);
         *arrayGet<V>(m.values, j - 1) = *arrayGet<V>(m.values, j);
         *arrayGet<V>(m.values, j) = value;

         j -= 1;
      }
   }
}

template <typename K, typename V>
void mapSortByValues(Map<K, V> &m, int cmpVV(V, V)) // 1.6.2.14
{
   for (int i = 1; i < mapSize<K, V>(m); i++)
   {
      int j = i;
      while ((j > 0) && (cmpVV(*arrayGet<V>(m.values, j - 1), *arrayGet<V>(m.values, j)) > 0))
      {
         // Swap Key
         K key = *arrayGet<K>(m.keys, j - 1);
         *arrayGet<K>(m.keys, j - 1) = *arrayGet<K>(m.keys, j);
         *arrayGet<K>(m.keys, j) = key;

         // Swap Value
         V value = *arrayGet<V>(m.values, j - 1);
         *arrayGet<V>(m.values, j - 1) = *arrayGet<V>(m.values, j);
         *arrayGet<V>(m.values, j) = value;

         j -= 1;
      }
   }
}

#endif
