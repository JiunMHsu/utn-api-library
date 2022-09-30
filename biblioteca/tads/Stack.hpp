
#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template <typename T>
struct Stack
{
   Node<T> *first;
   int size;
};

template <typename T>
Stack<T> stack()
{
   Stack<T> st;
   st.first = new Node<T>;
   st.size = 0;
   return st;
}

template <typename T>
T *stackPush(Stack<T> &st, T e)
{
   Node<T> *node = push<T>(st.first, e);
   st.size++;
   return &(node->data);
}

template <typename T>
T stackPop(Stack<T> &st)
{
   T t = pop<T>(st.first);
   st.size--;
   return t;
}

template <typename T>
bool stackIsEmpty(Stack<T> st)
{
   return isEmpty(st.first);
}

template <typename T>
int stackSize(Stack<T> st)
{
   return st.size;
}

#endif
