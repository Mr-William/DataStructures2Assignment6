#include "Stock.h"
#include "SortedList.h"
#include <iostream>
#include <fstream>

using namespace std;

void processMenu(string);

int main()
{
	int arrChoice;
	char choice = ' ';
	fstream sFile;
	sFile.open("stocks.txt");
	Stock s;
	int i = 0;
	int size = s.getNumStocks(sFile);							//Number of stocks in stocks.txt
	SortedList<int>* intArr = new SortedList<int>(size);
	SortedList<Stock>* stockArray = new SortedList<Stock>(size);

	while ((!(sFile.eof())) && (i < size))
	{
		sFile >> s;
		stockArray->insert(s);

		intArr->insert(i);

		i++;
	}

	sFile.close();

	cout << "Two arrays have been created: \n(1)Stocks\n(2)Integers\n";
	do
	{
		cout << "Which array would you like to work with (enter 1 for Stocks or 2 for Integers):";
		cin >> arrChoice;
		cin.ignore();

		switch (arrChoice)
		{
		case 1:
			do
			{
				processMenu("Stock");
				cin.get(choice);

				switch (toupper(choice))
				{
				case 'A':
					stockArray->display();
					break;
				case 'B':
					stockArray->quickSortA();
					break;
				case 'C':
					stockArray->quickSortD();
					break;
				case 'D':
					stockArray->heapSortA();
					break;
				case 'E':
					stockArray->heapSortD();
					break;
				case 'F':
					stockArray->randomise();
				default:
					cout << "Invalid menu selection, please try again.\n" << endl;
					break;
				}
			} while ((toupper(choice) != 'S')  && (toupper(choice) != 'Q'));
			break;
		case 2:
			do
			{
				processMenu("Integer");
				cin.get(choice);

				switch (toupper(choice))
				{
				case 'A':
					intArr->display();
					break;
				case 'B':
					intArr->quickSortA();
					break;
				case 'C':
					intArr->quickSortD();
					break;
				case 'D':
					intArr->heapSortA();
					break;
				case 'E':
					intArr->heapSortD();
					break;
				case 'F':
					intArr->randomise();
				default:
					cout << "Invalid menu selection, please try again.\n" << endl;
					break;
				}

			} while ((toupper(choice) != 'S') && (toupper(choice) != 'Q'));
			break;
		default:
			cout << "Invalid choice. Please select from the menu options provided.\n\n";
		}
	} while (toupper(choice) != 'Q');

	cout << "\nProgram Terminating. Goodbye.\n" << endl;
	
	return 0;
}

void processMenu(string choiceArr)
{
	cout << string(20, '#') << endl;
	cout << "Choose an option for the " << choiceArr << " array." << endl;
	cout << "A: Display the array." << endl;
	cout << "B: QuickSort the array into ASCENDING order and display." << endl;
	cout << "C: QuickSort the array into DESCENDING order and display." << endl;
	cout << "D: HeapSort the array into ASCENDING order and display." << endl;
	cout << "E: HeapSort the array into DESCENDING order and display." << endl;
	cout << "F: Randomise the array." << endl;
	cout << "S: Switch your array choice." << endl;
	cout << "Q: Quit the program." << endl;
}