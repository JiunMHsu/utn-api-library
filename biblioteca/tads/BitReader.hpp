
#ifndef _TARR_BITREADER_
#define _TARR_BITREADER_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../funciones/strings.hpp"

using namespace std;

struct BitReader
{
   FILE *file;
   string byte;
};

BitReader bitReader(FILE *f)
{
   return {f, ""};
}

// typedef unsigned char uchar;
string binToString(unsigned char c)
{
   string s = "";
   for (int i = 0; i < 8; i++)
   {
      u_char mask = (char)pow(2, i);
      u_char res = c & mask;
      s = (res == 0) ? '0' + s : '1' + s;
   }
   return s;
}

int bitReaderRead(BitReader &br)
{
   if (isEmpty(br.byte))
   {
      u_char ucByte = read<u_char>(br.file);
      br.byte = binToString(ucByte);
   }
   char bit = br.byte[0];
   br.byte = removeAt(br.byte, 0);

   return (bit == '0') ? 0 : 1;
}

#endif