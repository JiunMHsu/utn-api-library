
#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template <typename T>
void write(FILE *f, T t) // 1.4.1.1
{
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   //
   fseek(f, 0, SEEK_CUR);
   fwrite(&t, sizeof(T), 1, f);
}

template <typename T>
T read(FILE *f) // 1.4.1.2
{
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   //
   fseek(f, 0, SEEK_CUR);
   T t;
   fread(&t, sizeof(T), 1, f);
   return t;
}

template <typename T>
void seek(FILE *f, int n) // 1.4.1.3
{
   int tSize = sizeof(T);
   fseek(f, tSize * n, SEEK_SET);
}

template <typename T>
int fileSize(FILE *f) // 1.4.1.4
{
   // int curr = ftell(f);
   int i;
   seek<T>(f, 0);
   read<T>(f); // Bucle infinito si se usa solo el '!feof'
   for (i = 0; !feof(f); i++)
      read<T>(f);
   seek<T>(f, 0);
   return i;
}

template <typename T>
int filePos(FILE *f) // 1.4.1.5
{
   return ftell(f) / sizeof(T);
}

#endif
