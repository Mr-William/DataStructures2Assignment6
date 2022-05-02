//***********************************************************
//
//	File:		 SortedList.h
//	
//	Description: Header file for Sorted List template class
//
//***********************************************************

#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>
#include <string>

template <typename T>
class SortedList
{
private:
	T* sList;
	int size;
	int numValues;
public:
	SortedList(int);
	SortedList() { size = 0; numValues = 0; };
	~SortedList();
	T* partition(T [], T*, T*);
	void swap(T*, T*);
	void insert(const T&);
	void randomise();
	void heapify(int, int);
	void quickSortA();
	void quickSortD();
	void heapSortA();
	void heapSortD();
	void display() const;
};

#endif