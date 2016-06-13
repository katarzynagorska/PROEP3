#pragma once
#include <iostream>
#include <ctime>
#include "mynode.h"

template <typename T> class myNode;

//Lista
template <typename T> class myList {
public:
	myList();
	myList(myList<T> &_list);
	~myList();

	//Elements edition
	void push_back(const T& data);
	void push_front(const T& data);
	void pop_back();
	void pop_front();
	void insert(int idx, const T& data);
	void erase(int idx);

	void print();

	int size() { return _size; };	//Returns the number of elements in the list container.
	bool empty();


	T& operator[](int idx);
	T& at(int idx);
	T& back(){ return last->data; }
	T& front(){ return first->data; }
	//Assignement operator, creates copy of the list
	myList<T>& operator=(myList<T> &_list);
	double nodeCreationTime(int idx);

private:
	myNode<T> *last, *first;			//<pointers to first and last element
	int _size;							//<list size
};

//Constructs an empty container, with no elements.
template <typename T> myList<T>::myList() {
	last = NULL;
	first = NULL;
	_size = 0;
}

//Constructs new container, copying contents and modyfying its size.
template <typename T>myList<T>::myList(myList<T> &_list) {
	myNode<T> *currentPtr = _list.first;

	for (int i = 0; i < _list.size(); i++)
	{
		push_back(currentPtr->data);
		currentPtr = currentPtr->next;
	}
}

template<typename T> myList<T>::~myList() {
	if (!empty()) {
		myNode<T> *currentPtr = first;
		myNode<T> *tempPtr;

		while (currentPtr != 0) {
			tempPtr = currentPtr;
			currentPtr = currentPtr->next;
			delete tempPtr;
		}
	}
	first = NULL;
	last = NULL;
}

//Printing list to console
template <typename T> void myList<T>::print() {
	if (empty()) {
		cout << "empty" << endl << endl;
		return;
	}
	int itr = 0;
	myNode<T> *currentPtr = first;
	while (currentPtr)
	{
		cout << itr++ << ". " << currentPtr->data << endl;
		currentPtr = currentPtr->next;
	}
	cout << endl << endl << "first element: " << first->data << endl << "last emlement: " << last->data << endl << "list size: " << size() << endl << endl;
}

//Returns true if list is empty
template <typename T> bool myList<T>::empty() {
	return ((last == NULL) && (first == NULL));
}

//Adds a new element at the end of the list, after its current last element.
template <typename T> void myList<T>::push_back(const T& data) {

	myNode<T> *newPtr = new myNode<T>(data);

	if (empty()) {
		last = newPtr;
		first = newPtr;
	}
	else {
		last->next = newPtr;
		last = newPtr;
	}
	_size++;
}

//Inserts a new element at the beginning of the list, right before its current first element
template <typename T> void myList<T>::push_front(const T& data) {

	myNode<T> *newPtr = new myNode<T>(data);

	if (empty()) {
		last = newPtr;
		first = newPtr;
	}
	else {
		newPtr->next = first;
		first = newPtr;
	}
	_size++;
}
//Removes the first element in the list container, effectively reducing its size by one.
template <typename T> void myList<T>::pop_front() {
	if (_size == 1) {
		delete first;
		first = NULL;
		last = NULL;
		_size--;
	}
	else if (!empty()) {
		myNode<T> *tmpPtr = first;
		first = first->next;
		delete tmpPtr;
		_size--;
	}

}
//Removes the last element in the list container, effectively reducing its size by one.
template <typename T> void myList<T>::pop_back() {
	if (_size == 1) {
		delete first;
		first = NULL;
		last = NULL;
		_size--;
	}
	else if (!empty()) {
		myNode<T> *currentPtr = first;

		while (currentPtr->next->next)
			currentPtr = currentPtr->next;

		delete currentPtr->next;
		last = currentPtr;
		last->next = NULL;
		_size--;
	}
}
//The container is extended by inserting new elements before the element at the specified position.
template <typename T>  void myList<T>::insert(int idx, const T& data) {
	if ((idx > _size) || (idx < 0)) {
		//throw out_of_range("index out of range");
		cout << "out of range" << endl;
		return;
	}
	else if (idx == _size) {
		push_back(data);
	}
	else if (idx == 0) {
		push_front(data);
	}
	else {
		myNode<T> *currentPtr = first;
		myNode<T> *tmp;
		myNode<T> *newNode = new myNode<T>(data);
		for (int i = 0; i < idx - 1; i++)
		{
			currentPtr = currentPtr->next;
		}
		tmp = currentPtr->next;
		currentPtr->next = newNode;
		newNode->next = tmp;
		_size++;
	}
}
//Removes from the list container either a single element at the specified position
//This effectively reduces the container size by the number of elements removed, which are destroyed.
template <typename T> void myList<T>::erase(int idx) {
	if ((idx > _size - 1) || (idx < 0)) {
		//throw out_of_range("index out of range");
		cout << "out of range" << endl;
	}
	else if (idx == _size - 1) {
		pop_back();
	}
	else if (idx == 0) {
		pop_front();
	}
	else {
		myNode<T> *toErase;
		myNode<T> *currentPtr = first;
		for (int i = 0; i < idx - 1; i++)
			currentPtr = currentPtr->next;

		toErase = currentPtr->next;
		currentPtr->next = currentPtr->next->next;

		delete toErase;

		_size--;
	}
}
//Returns a reference to the element at position idx in the list container.
template <typename T> T& myList<T>::operator[](int idx) {

	if ((idx > size() - 1) || (idx < 0)) {
		//throw out_of_range("index out of range");
		return last->next->data;
	}
	else {
		myNode<T> *currentPtr = first;

		for (int i = 0; i < idx; i++)
			currentPtr = currentPtr->next;

		return currentPtr->data;
	}
}

template <typename T> T& myList<T>::at(int idx) {

	if ((idx > size() - 1) || (idx < 0)) {
		//throw out_of_range("index out of range");
		return last->next->data;
	}
	else {
		myNode<T> *currentPtr = first;

		for (int i = 0; i < idx; i++)
			currentPtr = currentPtr->next;

		return currentPtr->data;
	}
}

//Returns node at index idx age; Returns -1 if idx out of range.
template <typename T> double myList<T>::nodeCreationTime(int idx) {
	if ((idx > size() - 1) || (idx < 0))
		return -1;

	myNode<T> *currentPtr = first;
	for (int i = 0; i < idx; i++) {
		currentPtr = currentPtr->next;
	}
	return currentPtr->getCreationTime();
}
//Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
template <typename T> myList<T>& myList<T>::operator=(myList<T> &_list) {

	while (!empty())
		pop_back();

	myNode<T> *currentPtr = _list.first;

	for (int i = 0; i < _list.size(); i++) {
		push_back(currentPtr->data);
		currentPtr = currentPtr->next;
	}
	return *this;
}