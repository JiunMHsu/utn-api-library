
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

template <typename T>
void showList(Node<T> *p)
{
	Node<T> *node = p;
	cout << "{ ";
	while (node != NULL)
	{
		cout << node->data;
		cout << ", ";
		node = node->next;
	}
	cout << "}" << endl;
}

int cmpIntString(int a, string b)
{
	return a - stringToInt(b);
}

int main()
{
	List<int> lst = list<int>();

	listAdd<int>(lst, 2);
	listAdd<int>(lst, 5);
	listAdd<int>(lst, 1);
	listAdd<int>(lst, 7);
	listAdd<int>(lst, 6);
	listAdd<int>(lst, 3);
	listAdd<int>(lst, 6);
	listAdd<int>(lst, 4);
	listAdd<int>(lst, 5);

	listReset<int>(lst);
	while (listHasNext<int>(lst))
	{
		int *e = listNext<int>(lst);
		cout << *e;
		cout << ", ";
	}
	cout << endl;
	cout << endl;

	bool endOfList = false;

	listReset<int>(lst);
	while (!endOfList)
	{
		int *e = listNext<int>(lst, endOfList);
		cout << *e;
		cout << ", ";
	}
	cout << endl;
	cout << endl;

	listFree<int>(lst);

	// cout << lst.aux->data << endl;

	return 0;
}

#endif
