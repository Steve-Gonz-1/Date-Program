#ifndef MY_DATETYPE_H
#define MY_DATETYPE_H

#define LESS	-1
#define EQUAL	 0
#define GREATER	 1

#include <iostream>

using namespace std;

class DateType{
 public:
  DateType();											//primary constructor

  DateType(int newMonth, int newDay, int newYear);		//secondary constructor

  int YearIs();       // returns year
  int MonthIs();      // returns month
  int DayIs();        // returns day

  bool SetDate(int newMonth, int newDay, int newYear);

  void ReadDate();

  void PrintDate();

  int ComparedTo(DateType aDate);

  int ComparedCentury(DateType aDate);

  void AdvanceDays(int NumDays);

  void BackDays(int NumDays);

  bool IsValidDate (int Month, int Day, int Year);

  void SetRandomDate();

  bool operator> (const DateType& aDate);

  bool operator< (const DateType& aDate);

  bool operator== (const DateType& aDate);

  bool operator!= (const DateType& aDate);

  bool operator>= (const DateType& aDate);

  bool operator<= (const DateType& aDate);

  DateType operator+ (int numDays);

  DateType operator- (int numDays);

  int operator- (const DateType& aDate);

  friend ostream& operator<< (ostream& output, const DateType& aDate);

  friend istream& operator>> (istream& input, DateType& aDate);

private:
	int year;
	int month;
	int day;
};

#endif