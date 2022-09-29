
#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int length(string s) // 1.1.1.1
{
   int i;
   for (i = 0; s[i] != '\0'; i++);
   return i;
}

int charCount(string s,char c) // 1.1.1.2
{
   int n = 0;
   for (int i = 0; s[i] != '\0'; i++) {
      if (s[i] == c) n++;
   }
   return n;
}

string substring(string s,int d,int h) // 1.1.1.3
{
   string sbstr;
   if (h > length(s)) return "-1";

   for (int i = d; i < h; i++) {
      sbstr = sbstr + s[i];
   }
   return sbstr;
}

string substring(string s,int d) // 1.1.1.4
{
   string a = substring(s, d, length(s));
   return a;
}

int indexOf(string s,char c,int offSet) // 1.1.1.6
{
   int i = offSet;

   while ((s[i] != c) && (s[i] != '\0')) {
      i++;
   }
      
   if (s[i] == '\0') return -1;
   return i;
}

int indexOf(string s,char c) // 1.1.1.5
{
   int i = indexOf(s, c, 0);
   return i;
}

int indexOf(string s,string toSearch,int offset) // 1.1.1.8
{
   int lngthTS = length(toSearch);
   int lngthS = length(s);

   if (lngthTS > lngthS) return -1;
   
   for (int i = offset; i < lngthS; i++) {
      bool compare = true;
      int indxTS = 0;
      int indxS = i;

      while ((compare == true) && (indxTS < lngthTS)) {
         compare = s[indxS] == toSearch[indxTS];
         indxTS ++;
         indxS ++;
      }

      if (toSearch[indxTS - 1] == s[indxS - 1]) return i;
   }
   
   return -1;
}

int indexOf(string s,string toSearch) // 1.1.1.7
{
   int n = indexOf(s, toSearch, 0);
   return n;
}

int lastIndexOf(string s,char c) // 1.1.1.9
{
   int lngthS = length(s);

   for (int i = lngthS - 1; i > 0; i--) {
      if (s[i] == c) return i;
   }
   return -1;
}

int indexOfN(string s,char c,int n) // 1.1.1.10
{
   int a = 0;
   if (n == 0) return -1;
   
   for (int i = 0; i < length(s); i++) {
      if (s[i] == c) a++;
      if (a == n) return i;
   }
   return length(s);
}

int charToInt(char c) // 1.1.1.11
{
   int num;

   // Conversion a Mayuscula
   if ((c >= 97) && (c <= 122)) {
      c = c - 32;
      // 32 es la diferencia entre mayuscula y minuscula
      // de cualquier caracter alfabetico en ASCII
   }

   // Conversion a valor numerico
   if ((c >= 65) && (c <= 70)) {
      num = c - 55;
   } else if ((c >= 48) && (c <= 57)) {
      num = c - 48;
   } else {
      num = -1;
   }

   return num;
}

char intToChar(int i) // 1.1.1.12
{
   char x;

   if ((i >= 0) && (i <= 9)) {
      x = i + 48;
   } else if ((i >= 10) && (i <= 35)) {
      x = i + 55;
   } else {
      x = 45;
   }
   return x;
}

int digitCount(int n) // 1.1.1.14
{
   n = abs(n);
   int a = 0;
   
   if (n == 0) return 1;
   for (int i = 1; n > 0; i = i * 10) {
      n = n - (n % i);
      a++;
   }
   return a - 1;
}

int powr(int b, int e) // Funcion potencia auxiliar
{
   if (e == 0) return 1;
   int n = b;

   while (e > 1) {
      n = n * b;
      e--;
   }
   return n;
}

string intToString(int i) // 1.1.1.15
{
   string str = "";
   int n = abs(i);
   int exp = digitCount(i) - 1;
   int placeVal;

   // En base a Notacion Posicional
   for (int a = 0; exp >= 0; exp --) {
      placeVal = powr(10, exp);
      a = n / placeVal;
      n = n - (a * placeVal);
      str = str + intToChar(a);
   }

   if (i < 0) return "-" + str;
   return str;
}

int getDigit(int n,int i) // 1.1.1.13
{
   string numStr = intToString(n);
   int indx = (length(numStr) - 1) - i;
   char x = numStr[indx];
   int num = charToInt(x);

   return num;
}

int stringToInt(string s,int b) // 1.1.1.16
{
   int num = 0;
   int strLenght = length(s);
   int exp = strLenght - 1;

   // Algoritmo de conversion (Sistema de Notacion Posicional)
   for (int i = 0; i < strLenght; i++) {
      char x = s[i];
      int a = charToInt(x);
      num = num + (a * ( powr(b, exp) ));
      exp --;
   }

   return num;
}

int stringToInt(string s) // 1.1.1.17
{
   int num = stringToInt(s, 10);
   return num;
}

string charToString(char c) // 1.1.1.18
{
   string a = "";
   a = a + c;
   return a;
}

char stringToChar(string s) // 1.1.1.19
{
   char x = s[0];
   return x;
}

string stringToString(string s) // 1.1.1.20
{
   return s;
}

string doubleToString(double d) // 1.1.1.21
{
   // Resolver
   string str = to_string(d);
   return str;
}

double stringToDouble(string s) // 1.1.1.22
{
   int dotPos = indexOf(s, '.');
   int integer = stringToInt( substring(s, 0, dotPos) );
   int decimal = stringToInt( substring(s, dotPos + 1) );
   
   double h = powr(10, digitCount(decimal));

   double intPart = integer;
   double decPart = decimal / h;

   double num = intPart + decPart;

   return num;
}

bool isEmpty(string s) // 1.1.1.23
{
   bool emptyStr;

   if (length(s) == 0) {
      emptyStr = true;
   } else {
      emptyStr = false;
   }
   return emptyStr;
}

bool startsWith(string s,string x) // 1.1.1.24
{
   for (int i = 0; i < length(x); i++) {
      if (s[i] != x[i]) return false;
   }

   return true;
}

bool endsWith(string s,string x) // 1.1.1.25
{
   // Extrae y Compara unicamente la subcadena final con la misma cantidad de caracteres que x
   int indx = length(s) - length(x);
   string strToCompare = substring(s, indx);
   
   // Funcion startsWith usado para verificar igualdad entre cadenas
   if ( startsWith(strToCompare, x) ) return true;

   return false;
}

bool contains(string s,char c) // 1.1.1.26
{
   for (int i = 0; i < length(s); i++) {
      if (s[i] == c) return true; 
   }
   return false;
}

string replace(string s,char oldChar,char newChar) // 1.1.1.27
{
   string newStr = "";

   for (int i = 0; i < length(s); i++) {
      if ( s[i] == oldChar) {
         newStr = newStr + newChar;
      } else {
         newStr = newStr + s[i];
      }
   }
   return newStr;
}

string insertAt(string s,int pos,char c) // 1.1.1.28
{
   string strPt1 = substring(s, 0, pos);
   string strPt2 = substring(s, pos);

   string newStr = strPt1 + c + strPt2;

   return newStr;
}

string removeAt(string s,int pos) // 1.1.1.29
{
   string strPt1 = substring(s, 0, pos);
   string strPt2 = substring(s, pos + 1);

   string newStr = strPt1 + strPt2;

   return newStr;
}

string ltrim(string s) // 1.1.1.30
{
   int i;
   for (i = 0; s[i] == 32; i++);
   string newStr = substring(s, i); 
   
   return newStr;
}

string rtrim(string s) // 1.1.1.31
{
   int i;
   for (i = length(s) - 1; s[i] == 32; i--);
   string newStr = substring(s, 0, i + 1);
   // (i + 1) por que la funcion no incluye a esa posicion
   
   return newStr;
}

string trim(string s) // 1.1.1.32
{
   string str;
   str = ltrim(s);
   str = rtrim(str);
   
   return str;
}

string replicate(char c,int n) // 1.1.1.33
{
   string str = "";

   for (int i = 0; i < n; i++) {
      str = str + c;
   }
   return str;
}

string spaces(int n) // 1.1.1.34
{
   string str = replicate(' ', n);
   return str;
}

string lpad(string s,int n,char c) // 1.1.1.35
{
   int a = n - length(s);
   string str = replicate(c, a) + s;

   return str;
}

string rpad(string s,int n,char c) // 1.1.1.36
{
   int a = n - length(s);
   string str = s + replicate(c, a);

   return str;
}

string cpad(string s,int n,char c) // 1.1.1.37
{
   int a = n - length(s);
   string str = "";
   
   int h = a / 2;
   if ((a % 2) == 0) {
      str = replicate(c, h) + s + replicate(c, h);
   } else {
      // El caracter que se omite haciendo la division de un impar entre 2
      // se complementa sumando directamente a la parte izquierda
      str = replicate(c, h) + c + s + replicate(c, h);
   }
   return str;
}

bool isDigit(char c) // 1.1.1.38
{
   if ((c >= 48) && (c <= 57)) return true;
   return false;
}

bool isLetter(char c) // 1.1.1.39
{
   if ((c >= 65) && (c <= 90)) return true; // Mayuscula
   if ((c >= 97) && (c <= 122)) return true; // Minuscula
   return false;
}

bool isUpperCase(char c) // 1.1.1.40
{
   if ((c >= 65) && (c <= 90)) return true;
   return false;
}

bool isLowerCase(char c) // 1.1.1.41
{
   if ((c >= 97) && (c <= 122)) return true;
   return false;
}

char toUpperCase(char c) // 1.1.1.42
{
   if (isLowerCase(c)) {
      c = c - 32;
   }
   return c;
}

char toLowerCase(char c) // 1.1.1.43
{
   if (isUpperCase(c)) {
      c = c + 32;
   }
   return c;
}

string toUpperCase(string s) // 1.1.1.44
{
   string str = "";

   for (int i = 0; i < length(s); i++) {
      char c = s[i];
      if (isLowerCase(c)) {
         str = str + toUpperCase(c);
      } else {
         str = str + c;
      }
   }
   return str;
}

string toLowerCase(string s) // 1.1.1.45
{
   string str = "";

   for (int i = 0; i < length(s); i++) {
      char c = s[i];
      if (isUpperCase(c)) {
         str = str + toLowerCase(c);
      } else {
         str = str + c;
      }
   }
   return str;
}

int cmpString(string a,string b) // 1.1.1.46
{
   if (a > b) return 1;
   if (a < b) return -1;
   return 0;
}

int cmpDouble(double a,double b) // 1.1.1.47
{
   double n = a - b;
   return n;
}

#endif
