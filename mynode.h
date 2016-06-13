#pragma once
#include <iostream>
#include <ctime>
#include "mylist.h"

template <typename T> class myList;

//List node class
template <typename T> class myNode {

	friend class myList<T>;

public:
	myNode(T);
	myNode();
	///Returns node age in milliseconds
	double getCreationTime();

private:
	T data;				//<Data stored in nodes
	myNode* next;		//<Pointer to next node
	clock_t creation;	//<Node age in ticks
};

template <typename T>
myNode<T>::myNode(T _data)
{
	data = _data;
	next = NULL;
	creation = clock();
}

template <typename T>
myNode<T>::myNode() {
	next = NULL;
	creation = clock();
}

template <typename T>
double myNode<T>::getCreationTime() {

	return ((double)(creation) / (double)(CLOCKS_PER_SEC)* 1000);
}
