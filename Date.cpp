#include <string>
#include <cstring>
#include <iostream>
#include <stdexcept>
#define minYear 1950
#define maxYear 2100
using namespace std;
#include "Date.h"
bool Date::isLeapYear(int y)
{
	return (((y%100==0) && (y%400==0))|| (y%4==0));
}
bool Date::isValidDate(int d,int m, int y)
{
	if ((y>maxYear) ||(y<minYear)) return false;
	if ((m>12)||(m<1)) return false;
	if (d<1||d>31) return false;
	if (((m==4)||(m==6)||(m==9)||(m==11)) && (d>30) )return false;
	if ((m==2) && isLeapYear(y) && (d<1||d>29)) return false;
	if ((m==2) && !isLeapYear(y) && (d<1||d>28)) return false;
	return true;
}
bool Date::isValidDateStringFormat(string date)
{
	int slashCounter=0;
	if ( !isdigit(date[0]) ||!isdigit(date[strlen(date.c_str())-1])) return false;
	for(int i=1;i<strlen(date.c_str())-1;i++)
		{
		if ((!isdigit(date[i])) && (date[i]!='/')) return false;
		if ((date[i-1]=='/') && (date[i]=='/')) return false;
		if (date[i]=='/') slashCounter++;
		if (slashCounter>2)  return false;
		}
	return true;
}
troisEntiers Date::dateFromStringToIntegers(string date)
{
	struct troisEntiers dateEntiers;
	string holder="";
	int position=0;//deux positions dans le string jour 0 mois 1
	for(int i=0;i<strlen(date.c_str());i++)
	{
		if (date[i]=='/')
			{
				switch(position)
				{
					case(0):dateEntiers.d=stoi(holder);
					case(1):dateEntiers.m=stoi(holder);
				}
				holder="";
				position++;
			}
		else holder+=date[i];
	}
	dateEntiers.y=stoi(holder);
	return dateEntiers;
}
int Date::getDay()const
{
	return day;
}
int Date::getMonth()const
{
	return month;
}
int Date::getYear()const
{
	return year;
}
Date::Date(int d=0,int m=0,int y=0){
 
		if (!isValidDate(d,m,y))
			throw runtime_error("Date invalide!");
		else
			{
				day=d;
				month=m;
				year=y;
			}
 

}
Date::Date(string date){
    int d,m,y;
		if (!isValidDateStringFormat(date))
			throw runtime_error("Date invalide!");
		else
			{
				struct troisEntiers dateEntiers=dateFromStringToIntegers(date);
				 d=dateEntiers.d;
				 m=dateEntiers.m;
				 y=dateEntiers.y;
			}
		if (!isValidDate(d,m,y))
			throw runtime_error("Date invalide!");
		else
			{
				day=d;
				month=m;
				year=y;
			}
}
void Date::incrementDate()
{
    if ((month==12) && (day==31))
    {
     day=1;
     month=1;
     year++;
    }
    else if (((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)) && (day==31))
    {
     day=1;
     month++;
    }
	else if (((month==4)||(month==6)||(month==9)||(month==11)) && (day==30) )
    {
     day=1;
     month++;
    }
	else if ((month==2) && !isLeapYear(year) && (day==28))
    {
     day=1;
     month++;
    }
    else if ((month==2) && isLeapYear(year) && (day==29))
    {
     day=1;
     month++;
    }
    else day++;
}
Date operator++ (Date& date,int)
{
    if ((date.month==12) && (date.day==31))
    {
     date.day=1;
     date.month=1;
     date.year++;
    }
    else if (((date.month==1)||(date.month==3)||(date.month==5)||(date.month==7)||(date.month==8)||(date.month==10)) && (date.day==31))
    {
     date.day=1;
     date.month++;
    }
	else if (((date.month==4)||(date.month==6)||(date.month==9)||(date.month==11)) && (date.day==30) )
    {
     date.day=1;
     date.month++;
    }
	else if ((date.month==2) && !date.isLeapYear(date.year) && (date.day==28))
    {
     date.day=1;
     date.month++;
    }
    else if ((date.month==2) && date.isLeapYear(date.year) && (date.day==29))
    {
     date.day=1;
     date.month++;
    }
    else date.day++;
    return date;
}

ostream& operator<< (ostream& flux,const Date& dateToPrint )
{
	flux<<dateToPrint.day<<"/"<<dateToPrint.month<<"/"<<dateToPrint.year;
	return flux;
}
int main()
{
	Date date("28/2/2001");
    cout<<date<<endl;
	date.incrementDate();
    cout<<date<<endl;
    cout<<date++<<endl;
}
