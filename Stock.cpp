//***********************************************************
//
//	File:		 Stock.cpp
//
//	Description: Function definitions for Stock class.
//
//***********************************************************

#include "Stock.h"


Stock::Stock()
{
	name = "";
	symbol = "";
	price = 0;
}

Stock::Stock(std::string n, std::string s, double p)
{
	name = n;
	symbol = s;
	price = p;
}

Stock::Stock(const Stock& s)
{
	name = s.name;
	symbol = s.symbol;
	price = s.price;
}

int Stock::getNumStocks(std::istream& f)
{
	int count = 0;
	Stock s;

	while (f)
	{
		f >> s;
		count++;
	}

	f.clear();

	return count;
}

void Stock::display()const
{
	std::cout << getName() << getSymbol() << getPrice() << std::endl;
}

std::ostream& operator <<(std::ostream& os, const Stock& s)
{
	os << "Name: " << s.getName() << std::endl;
	os << "Symbol: " << s.getSymbol() << std::endl;
	os << "Price: " << s.getPrice() << std::endl;

	return os;
}

std::istream& operator >>(std::istream& is, Stock& s)
{
	getline(is, s.name);
	getline(is, s.symbol);
	is >> s.price;
	is.ignore();

	return is;
}