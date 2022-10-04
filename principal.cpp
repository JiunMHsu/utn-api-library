
#ifndef _MAIN
#define _MAIN

#include <iostream>

#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Array.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Coll.hpp"

#include "biblioteca/tads/huffman/HuffmanSetup.hpp"
#include "biblioteca/tads/BitReader.hpp"
#include "biblioteca/tads/BitWriter.hpp"

#include "principal.hpp"

using namespace std;

int cmpInt(int a, int b)
{
	return a - b;
}

int main()
{
	FILE *h = fopen("test.dat", "w+b");

	write<char>(h, 'A');
	write<char>(h, 'H');

	fclose(h);

	FILE *f = fopen("test.dat", "r+b");

	BitReader tstBr = bitReader(f);

	// 01000001 01001000

	// u_char uc = read<u_char>(f);
	// string byte = binToString(uc);
	// cout << byte << endl;

	// cout << endl;

	// uc = read<u_char>(f);
	// byte = binToString(uc);
	// cout << byte << endl;
	
	// cout << endl;

	int bit = bitReaderRead(tstBr);
	while (!feof(f))
	{
		cout << bit << ".";
		bit = bitReaderRead(tstBr);
	}

	fclose(f);

	return 0;
}

#endif
