
#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"

using namespace std;

int tokenCount(string s, char sep) // 1.2.1.1
{
   if (s == "")
      return 0;
   int tokenQty = charCount(s, sep) + 1;
   return tokenQty;
}

void addToken(string &s, char sep, string t) // 1.2.1.2
{
   if (tokenCount(s, sep) == 0)
   {
      s = s + t;
   }
   else
   {
      s = s + sep + t;
   }
}

string getTokenAt(string s, char sep, int i) // 1.2.1.3
{
   string str = "";
   int sepPos1 = indexOfN(s, sep, i);
   int sepPos2 = indexOfN(s, sep, i + 1);
   str = substring(s, sepPos1 + 1, sepPos2);
   return str;
}

void removeTokenAt(string &s, char sep, int i) // 1.2.1.4
{
   if (i == 0)
   {
      int sepPos = indexOf(s, sep);
      if (tokenCount(s, sep) == 1)
         s = "";
      s = substring(s, sepPos + 1);
   }
   else
   {
      int sepPos1 = indexOfN(s, sep, i);
      int sepPos2 = indexOfN(s, sep, i + 1);
      s = substring(s, 0, sepPos1) + substring(s, sepPos2);
   }
}

void setTokenAt(string &s, char sep, string t, int i) // 1.2.1.5
{
   int sepPos1 = indexOfN(s, sep, i);
   int sepPos2 = indexOfN(s, sep, i + 1);

   s = substring(s, 0, sepPos1 + 1) + t + substring(s, sepPos2);
}

int findToken(string s, char sep, string t) // 1.2.1.6
{
   int i;
   for (i = 0; i < tokenCount(s, sep); i++)
   {
      string token = getTokenAt(s, sep, i);
      if (cmpString(token, t) == 0)
         return i;
   }
   return -1;
}

#endif
