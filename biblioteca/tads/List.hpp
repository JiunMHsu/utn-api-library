
#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template <typename T>
struct List // 1.7.4.1
{
   Node<T> *first;
   Node<T> *aux;
   int size;
};

// Revisar si los accesos a punteros de la struct
// hacen falta usar operador flecha
// ej: lst->first  /  lst->aux

template <typename T>
List<T> list() // 1.7.4.2
{
   List<T> lst;
   lst.first = NULL;
   lst.aux = NULL;
   lst.size = 0;
   return lst;
}

template <typename T>
T *listAdd(List<T> &lst, T e) // 1.7.4.3
{
   Node<T> *node = add<T>(lst.first, e);
   lst.size++;
   // revisar si hace falta '&'
   // return &(node->data) ??
   return node->data;
}

template <typename T>
T *listAddFirst(List<T> &lst, T e) // 1.7.4.4
{
   Node<T> *node = addFirst<T>(lst.first, e);
   lst.size++;
   return node->data; // return &(node->data) ??
}

template <typename T, typename K>
T listRemove(List<T> &lst, K k, int cmpTK(T, K)) // 1.7.4.5
{
   T t = remove<T, K>(lst.first, k, cmpTK);
   lst.size--;
   return t;
}

template <typename T>
T listRemoveFirst(List<T> &lst) // 1.7.4.6
{
   T t = removeFirst<T>(lst.first);
   lst.size--;
   return t;
}

template <typename T, typename K>
T *listFind(List<T> lst, K k, int cmpTK(T, K)) // 1.7.4.7
{
   Node<T> *node = find<T, K>(lst, k, cmpTK);
   return node->data; // return &(node->data) ??
}

template <typename T>
bool listIsEmpty(List<T> lst) // 1.7.4.8
{
   return isEmpty<T>(lst.first);
}

template <typename T>
int listSize(List<T> lst) // 1.7.4.9
{
   return lst.size;
}

template <typename T>
void listFree(List<T> &lst) // 1.7.4.10
{
   free<T>(lst.first);
   lst.size = 0;
}

template <typename T>
T *listOrderedInsert(List<T> &lst, T t, int cmpTT(T, T)) // 1.7.4.11
{
   Node<T> *node = orderedInsert<T>(lst.first, t, cmpTT);
   lst.size++;
   return node->data; // return &(node->data) ??
}

template <typename T>
void listSort(List<T> &lst, int cmpTT(T, T)) // 1.7.4.12
{
   sort<T>(lst.first, cmpTT);
}

// depurar y revisar si hay otra alternativa
template <typename T>
void listReset(List<T> &lst) // 1.7.4.13
{
   if (lst.aux != NULL)
   {
      free<T>(lst.aux);
   }
   lst.aux = new Node<T>;
   lst.aux->next = lst.first;
}

template <typename T>
bool listHasNext(List<T> lst) // 1.7.4.13
{
   return lst.aux->next == NULL;
}

template <typename T>
T *listNext(List<T> &lst) // 1.7.4.14
{
   lst.aux = lst.aux->next;
   return lst.aux->data; // return con '&' ??
}

// revisar si funca
// estructura sacada de collNext(overload)
template <typename T>
T *listNext(List<T> &lst, bool &endOfList) // 1.7.4.15
{
   if (listHasNext<T>(lst))
   {
      endOfList = true;
   }
   else
   {
      endOfList = false;
   }
   T *t = listNext<T>(lst);
   return t;
}

#endif
