#include "Date.cpp"
using namespace std;

int main()
{
	//given a declaration of a Date with 3 ints paramters following the correct Date format ,when the constructors executes, expect the attributs to have the given parameters
    Date dateCorrecteMultiParametres(5,5,2010);

    if(dateCorrecteMultiParametres.getDay()==5 && dateCorrecteMultiParametres.getMonth()==5 && dateCorrecteMultiParametres.getYear()==2010){
        cout<<"initiate Date with multiple int parametres given a correct date Format [passed]"<<endl;
    } 
    else{
         cout<<"initiate Date with multiple int parametres given a correct date Format [failed]"<<endl; 
         cout<<"expected day=5,month=5,year=2020 got: day= "<<dateCorrecteMultiParametres.getDay()<<"Month= "<<dateCorrecteMultiParametres.getMonth()<<"year= "<<dateCorrecteMultiParametres.getYear()<<endl;
    }
    //given a declaration of a Date with 3 ints paramters following an incorrect day ,when the constructors executes, expect an Exception 
    try{
    Date dateCorrecteMultiParametresIncorrectDay(32,5,2010);
    cout<<"Detection of an incorrect day on a date initiated with multiple Parameters [failed]\n no exception thrown"<<endl;

    }catch (const runtime_error& e){
         cout<<"Detection of an incorrect day on a date initiated with multiple Parameters [passed]"<<endl ;

    }


    //given a declaration of a Date with 3 ints paramters following an incorrect month ,when the constructors executes, expect an Exception 
    try{
    Date dateMultiParametresIncorrectMonth(10,15,2010);
    cout<<"Detection of an incorrect month  on a date initiated with multiple Parameters [failed]\n no exception thrown"<<endl;

    }catch (const runtime_error& e){
         cout<<"Detection of an incorrect month on a date initiated with multiple Parameters [passed]"<<endl;

    }

     //given a declaration of a Date with 3 ints paramters following an incorrect year ,when the constructors executes, expect an Exception 
    try{
    Date dateMultiParametresIncorrectYear(10,5,1945);
    cout<<"Detection of an incorrect year  on a date initiated with multiple Parameters [failed] \n no exception thrown"<<endl;

    }catch (const runtime_error& e){
         cout<<"Detection of an incorrect year on a date initiated with multiple Parameters [passed]"<<endl;

    }
    
    //given a declaration of a Date with a string parameter,when the constructor executes, excpect the attributes to have the given parameter
    Date dateStringFormat("5/5/2010");
    if(dateStringFormat.getDay()==5 && dateStringFormat.getMonth()==5 && dateStringFormat.getYear()==2010){
        cout<<"initiate Date with string  parametre given a correct date Format [passed]"<<endl;
    } 
    else{
         cout<<"initiate Date with string   parametre given a correct date Format [failed]"<<endl; 
         cout<<"expected day=5,month=5,year=2020 got: day= "<<dateCorrecteMultiParametres.getDay()<<"Month= "<<dateCorrecteMultiParametres.getMonth()<<"year= "<<dateCorrecteMultiParametres.getYear()<<endl;
    }

       
    //given a declaration of a Date with a string parameter,and that the day section is written with a 0 on its left side,when the constructor executes, excpect the attributes to have the given parameter
    Date dateStringFormatSpecialDayFormat("05/5/2010");
    if(dateStringFormatSpecialDayFormat.getDay()==5 && dateStringFormatSpecialDayFormat.getMonth()==5 && dateStringFormatSpecialDayFormat.getYear()==2010){
        cout<<"initiate Date with string   parametre given a correct date Format with a 0 on the left side of a single digit day [passed]"<<endl;
    } 
    else{
         cout<<"initiate Date with string   parametre given a correct date Format with a 0 on the left side of a single digit day [failed]"<<endl; 
         cout<<"expected day=5,month=5,year=2020 got: day= "<<dateStringFormatSpecialDayFormat.getDay()<<"Month= "<<dateStringFormatSpecialDayFormat.getMonth()<<"year= "<<dateStringFormatSpecialDayFormat.getYear()<<endl;
    }
    

    //given a declaration of a Date with a random string parameter,when the constructor execute , expect an exception
    try{
        Date dateRandomStringFormat("random");
        cout<<"detection of a wrong string format parameter on a date declaration [failed] \n no exception thrown"<<endl;
    }catch(const runtime_error& e){
        cout<<"detection of a wrong string format parameter on a date declaration [passed]"<<endl;
    }
    //given a declaration of a Date with a string  parameter with 0 on the left side of a double digit moouth ,when the constructor execute , expect the attributes to have the given paramter
    
    Date dateStringFormatSpecialMonthFormat("05/05/2010");
     if(dateStringFormatSpecialMonthFormat.getDay()==5 && dateStringFormatSpecialMonthFormat.getMonth()==5 && dateStringFormatSpecialMonthFormat.getYear()==2010){
        cout<<"initiate Date with string format with 0 on the left side of a single digit month [passed]"<<endl;
    } 
    else{
         cout<<"initiate Date with stirng format with 0 on the left side of a single digit month  [failed]"<<endl; 
         cout<<"expected day=5,month=5,year=2020 got: day= "<<dateStringFormatSpecialMonthFormat.getDay()<<"Month= "<<dateStringFormatSpecialMonthFormat.getMonth()<<"year= "<<dateStringFormatSpecialMonthFormat.getYear()<<endl;
    }
   
   //given a declaration of a Date with a string parameter with incorrect seperators,when the constructor execute, expect an exception 
    try{
        Date dateWrongSeparator("5*5*2010");
        cout<<"detection of the wrong seperator [failed]\n no exeption thrown"<<endl;
    }catch(const runtime_error& e){
        cout<<"detection of the wrong seperator [passed]"<<endl;
    }
       //given a declaration of a Date with a string parameter with multiple right seperators,when the constructor execute, expect an exception 
    try{
        Date dateMultipleSeperators("5//5/2010");
        cout<<"detection of multiple seperators [failed]\n no exeption thrown"<<endl;
    }catch(const runtime_error& e){
        cout<<"detection of multiples right seperator [passed]"<<endl;
    }
       //given a declaration of a Date with a string parameter with multiple 0 on the left side of  a day ,month and year,when the constructor execute, expect the attributes to have the given parameters
  
        Date dateMultipleZeroLeft("00005/000005/0000002010");
          if(dateMultipleZeroLeft.getDay()==5&& dateMultipleZeroLeft.getMonth()==5 && dateMultipleZeroLeft.getYear()==2010){
        cout<<"initiate Date with string format with multiple 0 on the left side of a day ,month , and year [passed]"<<endl;
    } 
    else{
         cout<<"initiate Date with string format with multiple 0 on the left side of a day [failed]"<<endl; 
         cout<<"expected day=5,month=5,year=2020 got: day= "<<dateMultipleZeroLeft.getDay()<<"Month= "<<dateMultipleZeroLeft.getMonth()<<"year= "<<dateMultipleZeroLeft.getYear()<<endl;
    }
 
       //given an incorrect amount of seperators,when the constructor execute,expect an exception
        try{
            Date dateIncorrectAmountOfSeperators("5/15");
            cout<<"detection of incorrect amount of seperator [failed]\n no exception thrown"<<endl;
        }catch(const runtime_error& e){
             cout<<"detection of incorrect amount of seperator [passed]"<<endl;
        }
    //given a date on a 30 day month and the day parameter is given 31, when constructor executes, and exception should be thrown
    try{
        Date incorrectMonthDayDualityDate(31,4,2010);
        cout<<"detection of wrong month and day duality [failed]\n excepcted exception"<<endl;
    }catch(const runtime_error& e){
         cout<<"detection of wrong month and day duality [passed]"<<endl;
    }
    //given a correct initiated Date   where the following day does not fall in a new month or year , when incremented, expect the right date to update
    Date simpleDateToIncrement(4,5,2010);

    simpleDateToIncrement++;

     if(simpleDateToIncrement.getDay()==5 && simpleDateToIncrement.getMonth()==5 && simpleDateToIncrement.getYear()==2010){
        cout<<"incement a date  where the following day does not fall in a new month or year  [passed]"<<endl;
    } 
    else{
         cout<<"incement a date  [failed]"<<endl; 
         cout<<"expected day=5,month=5,year=2010 got: day= "<<simpleDateToIncrement.getDay()<<"Month= "<<simpleDateToIncrement.getMonth()<<"year= "<<simpleDateToIncrement.getYear()<<endl;
    }
    //given a correct initiated Date with a 31 day month where the following day does fall in a new month but not in a new year , when incremented, expect the right date to update
    Date endOfMonthDateToIncrement(31,1,2010);

    endOfMonthDateToIncrement++;
     if(endOfMonthDateToIncrement.getDay()==1 && endOfMonthDateToIncrement.getMonth()==2 && endOfMonthDateToIncrement.getYear()==2010){
        cout<<"incement a date with a 31 day month where the following day does  fall in a new month but no in a new year  [passed]"<<endl;
    } 
    else{
         cout<<"incement a date  [failed]"<<endl; 
         cout<<"expected day=1,month=2,year=2010 got: day= "<<simpleDateToIncrement.getDay()<<"Month= "<<simpleDateToIncrement.getMonth()<<"year= "<<simpleDateToIncrement.getYear()<<endl;
    }
     //given a correct initiated Date with a 30 day month where the following day does fall in a new month but not in a new year , when incremented, expect the right date to update
    Date endOfLongMonthDateToIncrement(30,4,2010);

    endOfLongMonthDateToIncrement++;
     if(endOfLongMonthDateToIncrement.getDay()==1 && endOfLongMonthDateToIncrement.getMonth()==5 && endOfLongMonthDateToIncrement.getYear()==2010){
        cout<<"incement a date with a 30 day month where the following day does  fall in a new month but no in a new year   [passed]"<<endl;
    } 
    else{
         cout<<"incement a date with a 30 day month where the following day does  fall in a new month but no in a new year  [failed]"<<endl; 
         cout<<"expected day=1,month=5,year=2010 got: day= "<<endOfLongMonthDateToIncrement.getDay()<<"Month= "<<endOfLongMonthDateToIncrement.getMonth()<<"year= "<<endOfLongMonthDateToIncrement.getYear()<<endl;
    }

    //given a date with leap year, when initiated, should detect a leap year
    try{
    Date leapYearDate(29,2,1992);
    Date leapYearDate2(29,2,1996);
    Date leapYearDate3(29,2,1988);

    cout<<"leap year detection [passed]"<<endl;
    }catch(const runtime_error& e){
        cout<<"leap year detection [failed]"<<endl;
    }
    //given a date with leap year, when incremented from february to mars, should update to the right date
   Date leapYearDateToIncrement(29,2,1996);
   leapYearDateToIncrement++;
     if(leapYearDateToIncrement.getDay()==1 && leapYearDateToIncrement.getMonth()==3 && leapYearDateToIncrement.getYear()==1996){
        cout<<"increment date on a leap year from february to mars [passed]"<<endl;
    } 
    else{
         cout<<"increment date on a leap year from february to mars  [failed]"<<endl; 
         cout<<"expected day=1,month=5,year=1996 got: day= "<<leapYearDateToIncrement.getDay()<<"Month= "<<leapYearDateToIncrement.getMonth()<<"year= "<<leapYearDateToIncrement.getYear()<<endl;
    }
    //given a date where the following day does fall iun a new year, when incremented,expect a correct date update
    Date endOfYearDate(31,12,2021);
    endOfYearDate++;
      if(endOfYearDate.getDay()==1 && endOfYearDate.getMonth()==1 && endOfYearDate.getYear()==2022){
        cout<<"increment date on the end of the year [passed]"<<endl;
    } 
    else{
         cout<<"increment date on the end of the year  [failed]"<<endl; 
         cout<<"expected day=1,month=3,year=2010 got: day= "<<endOfYearDate.getDay()<<"Month= "<<endOfYearDate.getMonth()<<"year= "<<endOfYearDate.getYear()<<endl;
    }
    //given 2 correctly initiated dates where the first date is greater than the second one, when compared,expect a correct boolean output
    Date date1ToCompare(1,1,2010);
    Date date2ToCompare(1,1,2020);
    Date date3ToCompare(1,2,2010);
    Date date4ToCompare(5,2,2010);
    if(date1ToCompare<date2ToCompare &&  date1ToCompare<date3ToCompare  && date1ToCompare<date4ToCompare){
        cout<<"comparaison of dates using the opeator '<' overload [passed] "<<endl;
    }
    else{
        cout<<"comparaison of dates using the opeator overload [failed] "<<endl;
    }
    //given 2 correctly initiated dates where both have the same date, when compared,expect a correct boolean output 
    Date date5ToCompare(1,1,2010);
    Date date6Tocompare(1,1,2010);
    if (date5ToCompare==date6Tocompare){
        cout<<"comparaison of dates using the '==' operator overload [passed] "<<endl;
    }
    else {cout<<"comparaison of dates using the '==' operator overload [failed]"<<endl;
    }
}
