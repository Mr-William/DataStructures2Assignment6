//***********************************************************
//
//	File:		 Stock.h
//	
//	Description: Header file for stock class
//
//***********************************************************

#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>

class Stock
{
private:
	std::string name;
	std::string symbol;
	double price;
	double freq;
public:
	Stock();
	Stock(std::string, std::string, double);
	Stock(const Stock&);
	int getNumStocks(std::istream&);
	void display() const;
	inline std::string getName() const { return name; };
	inline std::string getSymbol() const { return symbol; };
	inline double getPrice() const { return price; };
	inline int hash(int size) { return size % 10; };
	inline bool operator ==(const Stock& rhs) const { return rhs.symbol == symbol; };
	inline bool operator !=(const Stock& rhs) const { return !(rhs.symbol == symbol); };
	inline bool operator <(const Stock& r) const { return r.symbol < symbol; };
	inline bool operator >(const Stock& r) const { return !(r.symbol < symbol); };
	friend std::ostream& operator <<(std::ostream&, const Stock&);
	friend std::istream& operator >>(std::istream&, Stock&);
};

#endif