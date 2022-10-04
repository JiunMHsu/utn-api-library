
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
	Stack<int> st = stack<int>();

	stackPush<int>(st, 1);
	stackPush<int>(st, 2);
	stackPush<int>(st, 3);
	stackPush<int>(st, 4);
	stackPush<int>(st, 5);

	cout << stackSize<int>(st) << endl;

	while (!stackIsEmpty<int>(st))
	{
		int n = stackPop<int>(st);
		cout << n << ", ";
	}
	cout << endl;
	cout << endl;

	cout << stackSize<int>(st) << endl;

	return 0;
}

#endif
