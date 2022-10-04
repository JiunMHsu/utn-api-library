
#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template <typename T>
struct Stack // 1.7.5.1
{
   Node<T> *first;
   int size;
};

template <typename T>
Stack<T> stack() // 1.7.5.2
{
   Stack<T> st;
   st.first = NULL;
   st.size = 0;
   return st;
}

template <typename T>
T *stackPush(Stack<T> &st, T e) // 1.7.5.3
{
   Node<T> *node = push<T>(st.first, e);
   st.size++;
   return &(node->data);
}

template <typename T>
T stackPop(Stack<T> &st) // 1.7.5.4
{
   T t = pop<T>(st.first);
   st.size--;
   return t;
}

template <typename T>
bool stackIsEmpty(Stack<T> st) // 1.7.5.5
{
   return isEmpty(st.first);
}

template <typename T>
int stackSize(Stack<T> st) // 1.7.5.6
{
   return st.size;
}

#endif
