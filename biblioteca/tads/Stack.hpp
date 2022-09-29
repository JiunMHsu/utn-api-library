
#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template <typename T>
struct Stack
{
};

template <typename T>
Stack<T> stack()
{
   Stack<T> st;
   return st;
}

template <typename T>
T *stackPush(Stack<T> &st, T e)
{
   return NULL;
}

template <typename T>
T stackPop(Stack<T> &st)
{
   T t;
   return t;
}

template <typename T>
bool stackIsEmpty(Stack<T> st)
{
   return true;
}

template <typename T>
int stackSize(Stack<T> st)
{
   return 0;
}

#endif
