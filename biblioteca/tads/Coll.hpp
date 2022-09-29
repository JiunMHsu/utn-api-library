
#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"

using namespace std;

template <typename T> // 1.3.2.1
struct Coll
{
   string s;
   char sep;
   int tokenIndx;
};

template <typename T> // 1.3.2.2
Coll<T> coll(char sep)
{
   Coll<T> c;
   c.s = "";
   c.sep = sep;
   return c;
}

template <typename T> // 1.3.2.3
Coll<T> coll()
{
   Coll<T> c;
   c.s = "";
   c.sep = '|';
   return c;
}

template <typename T> // 1.3.2.4
int collSize(Coll<T> c)
{
   return tokenCount(c.s, c.sep);
}

template <typename T> // 1.3.2.5
void collRemoveAll(Coll<T> &c)
{
   c.s = "";
}

template <typename T> // 1.3.2.6
void collRemoveAt(Coll<T> &c, int p)
{
   removeTokenAt(c.s, c.sep, p);
}

template <typename T> // 1.3.2.7
int collAdd(Coll<T> &c, T t, string tToString(T))
{
   string str = tToString(t);
   addToken(c.s, c.sep, str);
   return collSize(c) - 1;
}

template <typename T> // 1.3.2.8
void collSetAt(Coll<T> &c, T t, int p, string tToString(T))
{
   string str = tToString(t);
   setTokenAt(c.s, c.sep, str, p);
}

template <typename T> // 1.3.2.9
T collGetAt(Coll<T> c, int p, T tFromString(string))
{
   string str = getTokenAt(c.s, c.sep, p);
   T t = tFromString(str);
   return t;
}

template <typename T, typename K> // 1.3.2.10
int collFind(Coll<T> c, K k, int cmpTK(T, K), T tFromString(string))
{
   for (int i = 0; i < collSize(c); i++)
   {
      T t = collGetAt<T>(c, i, tFromString);
      if (cmpTK(t, k) == 0)
         return i;
   }
   return -1;
}

template <typename T> // 1.3.2.11
void collSort(Coll<T> &c, int cmpTT(T, T), T tFromString(string), string tToString(T))
{
   int i = 0;
   // Se itera hasta el anteultimo elemnto ya que se lo copmpara con el ultimo
   while (i < collSize(c) - 1)
   {
      T t1 = collGetAt<T>(c, i, tFromString);
      T t2 = collGetAt<T>(c, i + 1, tFromString);

      if (cmpTT(t1, t2) > 0)
      {
         collSetAt<T>(c, t1, i + 1, tToString);
         collSetAt<T>(c, t2, i, tToString);
         i = -1;
      }
      i++;
      // Despues de cada sort parcial, se resetea la posicion y se vulve a verificar desde el elemento 0
   }
}

template <typename T> // 1.3.2.12
bool collHasNext(Coll<T> c)
{
   // Funcional unicamente despues de aplicar collReset
   int next = c.tokenIndx + 1;
   if (next < tokenCount(c.s, c.sep))
      return true;
   return false;
}

template <typename T> // 1.3.2.13
T collNext(Coll<T> &c, T tFromString(string))
{
   // Nunca muestra el primer elemento (?
   c.tokenIndx++;
   T t = collGetAt<T>(c, c.tokenIndx, tFromString);
   return t;
}

template <typename T> // 1.3.2.14
T collNext(Coll<T> &c, bool &endOfColl, T tFromString(string))
{
   if (collHasNext(c))
   {
      endOfColl = false;
   }
   else
   {
      endOfColl = true;
   }
   T t = collNext<T>(c, tFromString);
   return t;
}

template <typename T> // 1.3.2.15
void collReset(Coll<T> &c)
{
   // c.tokrnIndx = 0;
   c.tokenIndx = -1;
}

template <typename T> // Funcion para Algoritmos Tool
string collToString(Coll<T> c)
{
   return c.sep + c.s;
}

template <typename T> // Funcion para Algoritmos Tool
Coll<T> collFromString(string s)
{
   Coll<T> c;
   c.sep = s[0];
   c.s = substring(s, 1);
   return c;
}

#endif
