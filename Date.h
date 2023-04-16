#ifndef DATE_H
#define DATE_H

#include <string>
#include <cstring>
#include <iostream>
#include <stdexcept>
#define minYear 1950
#define maxYear 2100
using namespace std;
struct troisEntiers
{
   int d,m,y;
};
class Date{
	private:
		int day;
		int month;
		int year;
		static bool isLeapYear(int y) ;
		static int numberOfMonths(const Date& Date) ;
		static bool isValidDate(int d,int m, int y) ;
		static bool isValidDateStringFormat(string date);
		troisEntiers dateFromStringToIntegers(string date);
	public:
		friend ostream& operator<< (ostream& flux,const Date& dateToPrint );
		friend istream& operator>> (istream& flux, Date& dateToInput );
		friend Date operator++ (Date& date,int);
		friend bool  operator== (const Date& date1,const Date& date2);
		friend bool operator<(const Date& date1,const Date& date2);
		int getYear()const;
		int getMonth()const;
		int getDay()const;
		Date(int d,int m,int y);
		Date(string date);
		void incrementDate();
};

#endif // DATE_H