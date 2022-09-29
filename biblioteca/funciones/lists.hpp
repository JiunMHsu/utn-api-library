
#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T>
struct Node // 1.7.1.1
{
   T data;
   Node<T> *next;
   // puntero tipo Node porque apunta a otro nodo
   // y no a la informacion
};

template <typename T>
Node<T> *add(Node<T> *&p, T e) // 1.7.1.2
{
   Node<T> *n = new Node<T>;
   n->data = e;
   n->next = NULL;

   if (p == NULL)
   {
      // crear primer nodo
      p = n;
   }
   else
   {
      // si la lista ya existe, agregar como ultimo
      Node<T> *lastNode = p;
      while (lastNode->next != NULL)
      {
         lastNode = lastNode->next;
      }
      lastNode->next = n;
   }
   return n;
}

template <typename T>
Node<T> *addFirst(Node<T> *&p, T e) // 1.7.1.3
{
   Node<T> *n = new Node<T>;
   n->data = e;
   // apuntar 'next' a la lista ya creada
   // en caso de ser primer nodo agregado, p sera NULL
   n->next = p;
   // apuntar p al nuevo nodo
   p = n;
   return p;
}

template <typename T>
T removeFirst(Node<T> *&p) // 1.7.1.5
{
   T t = p->data;
   Node<T> *node = p->next; // obtener segundo nodo
   delete p;
   p = node; // asignar el segundo nodo como el primero
   return t;
}

template <typename T, typename K>
T remove(Node<T> *&p, K k, int cmpTK(T, K)) // 1.7.1.4
{
   T t;

   if (cmpTK(p->data, k) == 0)
   {
      t = removeFirst(p);
   }
   else
   {
      Node<T> *aux = p;
      Node<T> *prev = NULL;

      while (aux != NULL && cmpTK(aux->data, k) != 0)
      {
         prev = aux;
         aux = aux->next;
      }

      prev->next = aux->next;
      t = aux->data;
      delete aux;
   }

   return t;
}

template <typename T, typename K>
Node<T> *find(Node<T> *p, K k, int cmpTK(T, K)) // 1.7.1.6
{
   Node<T> *node = p;
   while (node != NULL)
   {
      if (cmpTK(node->data, k) == 0)
      {
         return node;
      }
      node = node->next;
   }
   return NULL;
}

template <typename T>
Node<T> *orderedInsert(Node<T> *&p, T e, int cmpTT(T, T)) // 1.7.1.7
{
   Node<T> *n = new Node<T>;

   // orden creciente (menor a mayor)
   // primera condicion:
   // si el elemento a insertar es menor o igual al primero
   if (p == NULL || cmpTT(p->data, e) >= 0)
   {
      n = addFirst<T>(p, e);
   }
   else
   {
      Node<T> *aux = p;
      Node<T> *prev = NULL;

      while (aux != NULL && cmpTT(aux->data, e) < 0)
      {
         prev = aux;
         aux = aux->next;
      }

      n->data = e;
      n->next = aux;
      prev->next = n;
   }

   return n;
}

template <typename T>
Node<T> *searchAndInsert(Node<T> *&p, T e, bool &enc, int cmpTT(T, T)) // 1.7.1.8
{
   Node<T> *node = find<T, T>(p, e, cmpTT);
   enc = (node != NULL) ? true : false;
   // enc = node != NULL;
   if (!enc)
   {
      node = orderedInsert<T>(p, e, cmpTT);
   }
   return node;
}

template <typename T>
void sort(Node<T> *&p, int cmpTT(T, T)) // 1.7.1.9
{
   Node<T> *nodeA = p;           // primer node
   Node<T> *nodeB = nodeA->next; // segundo node

   while (nodeB != NULL)
   {
      if (cmpTT(nodeA->data, nodeB->data) > 0)
      {
         // swap
         T t = nodeA->data;
         nodeA->data = nodeB->data;
         nodeB->data = t;

         // reset to first pointer
         nodeA = NULL;
         nodeB = p;
      }
      nodeA = nodeB;
      nodeB = nodeB->next;
   }
}

template <typename T>
bool isEmpty(Node<T> *p) // 1.7.1.10
{
   return p == NULL;
}

template <typename T>
void free(Node<T> *&p) // 1.7.1.11
{
   while (p != NULL)
   {
      removeFirst<T>(p);
   }
}

// ========== Extension (Stack) ==========

template <typename T>
Node<T> *push(Node<T> *&p, T e) // 1.7.2.1
{
   return addFirst<T>(p, e);
}

template <typename T>
T pop(Node<T> *&p) // 1.7.2.2
{
   return removeFirst<T>(p);
}

// ========== Extension (Queue) ==========

template <typename T>
Node<T> *enqueue(Node<T> *&p, Node<T> *&q, T e) // 1.7.3.1
{
   q = add<T>(p, e);
   return q;
}

// revisar
template <typename T>
Node<T> *enqueue(Node<T> *&q, T e) // 1.7.3.2
{
   q = add<T>(q, e);
   return q;
}

template <typename T>
T dequeue(Node<T> *&p, Node<T> *&q) // 1.7.3.3
{
   return removeFirst<T>(p);
}

template <typename T>
T dequeue(Node<T> *&q) // 1.7.3.4
{
   T t;
   return t;
}

#endif
