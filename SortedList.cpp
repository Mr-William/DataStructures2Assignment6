//***********************************************************
//
//	File:		 SortedList.cpp
//
//	Description: Function definitions for Sorted sList template class.
//
//***********************************************************

#include "SortedList.h"
#include <time.h>

template <typename T>
SortedList<T>::SortedList(int s)
{
	size = s;
	numValues = 0;
	sList = new T[size];
}

template <typename T>
SortedList<T>::~SortedList()
{
	delete[] sList;
	sList = nullptr;
	size = 0;
	numValues = 0;
}

template <typename T>
T* SortedList<T>::partition(T sList[], T* low, T* high)
{
	int pivot = sList[(low + high) / 2];
	swap(sList[low], sList[(low + high) / 2]);
	int small = low;
	int index;

	for (int i = low + 1; i <= high; ++i)
	{
		index = i;
		if (pivot > sList[index])
		{
			++small;
			swap(sList[small], sList[index]);
		}
	}
	swap(sList[low], sList[small]);
	return small;
}

template <typename T>
void SortedList<T>::swap(T* val1, T* val2)
{
	int temp = *val1;
	*val1 = *val2; 
	*val2 = temp;
};

template <typename T>
void SortedList<T>::insert(const T& item)
{
	sList[numValues] = item;
	numValues++;
}

template <typename T>
void SortedList<T>::randomise()
{
	srand(time(0));
	T* temp;

	for (int i = size - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		swap(&sList[i], &sList[j]);
	}
}

template <typename T>
void SortedList<T>::heapify(int n, int root)
{
	int largest = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	if ((left < n) && (sList[left] > sList[largest]))
	{
		largest = left;
	}
	
	if ((right < n) && (sList[right] > sList[largest]))
	{
		largest = right;
	}

}

template <typename T>
void SortedList<T>::quickSortA()
{
	int n = sizeof(sList) / sizeof(sList[0]);
	int low = 0;
	int high = n - 1;

	if (low < high)
	{
		T pivot = partition(sList, low, high);
		quickSortA(sList, low, pivot - 1);
		quickSortA(sList, pivot + 1, high);
	}
}

template <typename T>
void SortedList<T>::quickSortD()
{
	int n = sizeof(sList) / sizeof(sList[0]);
	int low = 0;
	int high = n - 1;

	if (low < high)
	{
		T pivot = partition(sList, low, high);
		quickSortA(sList, low, pivot - 1);
		quickSortA(sList, pivot + 1, high);
	}
}

template <typename T>
void SortedList<T>::heapSortA()
{
	for (int i = numValues / 2 - 1; i >= 0; i--)
	{
		heapify(sList, numValues, i);
	}

	for (int i = numValues - 1; i >= 0; i--)
	{
		swap(sList[0], sList[i]);

		heapify(sList, i, 0);
	}
}

template <typename T>
void SortedList<T>::heapSortD()
{
	for (int i = numValues / 2 - 1; i >= 0; i--)
	{
		heapify(sList, numValues, i);
	}

	for (int i = numValues - 1; i >= 0; i--)
	{
		swap(sList[0], sList[i]);

		heapify(sList, i, 0);
	}
}

template <typename T>
void SortedList<T>::display()const
{
	if (numValues > 0)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << sList[i] << std::endl;
			std::cout << "------------\n" << std::endl;
		}
	}

	else
	{
		std::cout << "There are no values in that array.\n" << std::endl;
	}
}