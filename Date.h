#include <string>
#include <cstring>
#include <iostream>
#include <stdexcept>
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
		bool isLeapYear(int y) ;
		bool isValidDate(int d,int m, int y) ;
		bool isValidDateStringFormat(string date);
		troisEntiers dateFromStringToIntegers(string date);
	public:
		friend ostream& operator<< (ostream& flux,const Date& dateToPrint );
		friend Date operator++ (Date& date,int);
		int getYear()const;
		int getMonth()const;
		int getDay()const;
		Date(int d,int m,int y);
		Date(string date);
		void incrementDate();
};