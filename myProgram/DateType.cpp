#include "DateType.h"
#include <iostream>
#include <string>
#include<iomanip>
#include<ctime>
#include<fstream>
#include<ostream>
#include<cctype>
#include<cstdlib>

using namespace std;

DateType::DateType(){												// Default constructor

	year = 2000;
	month = 1;
	day = 1;
}

DateType::DateType(int newMonth, int newDay, int newYear){							// secondary constructor
	year = newYear;
	month = newMonth;
	day = newDay;

	if (IsValidDate(month, day, year) == false) {
		char bell = '%' - 30;
		cout << endl << endl << bell << "Error! " << month << "/" << day << "/" << year << " is not a an invalid date. Date initialized to 1/1/2000" << endl << endl;
		system("pause");
	}
}

bool DateType::SetDate(int newMonth, int newDay, int newYear)
{
	year = newYear;
	month = newMonth;
	day = newDay;

	if (IsValidDate(month, day, year) == true) {
		return true;
	}
	else {
		return false;
	}
}

int DateType::MonthIs(){
// Accessor function for data member month.
	return month;
}

int DateType::YearIs(){
// Accessor function for data member year.
	return year;
}


int DateType::DayIs(){
// Accessor function for data member day.
	return day;
}

void DateType::ReadDate(){
	cout << endl
		<< "Read in the information of a date (e.g. 8/8/1994): ";

	cout << endl << "The month is: ";
	cin >> month;
	cout << endl << "The day is: ";
	cin >> day;
	cout << endl << "The year is: ";
	cin >> year;

	while (IsValidDate(month, day, year) == false) {
		char bell = '%' - 30;
		cout << endl << endl << bell << "Error!" << "/" << month << "/" << day << "/" << year << " is an invalid date. Read in the information of a date(e.g. 8 / 8 / 1994) : " << endl;

		cout << endl << "The month is: ";
		cin >> month;
		cout << endl << "The day is: ";
		cin >> day;
		cout << endl << "The year is: ";
		cin >> year;

	}
}

void DateType::PrintDate(){
	cout << month << "/" << day << "/" << year << endl;

}

int DateType::ComparedTo(DateType aDate){
	if (month == aDate.month && day == aDate.day && year == aDate.year) {
		return EQUAL;
	}
	else if (year < aDate.year || (year <= aDate.year && month < aDate.month) || (year <= aDate.year && month <= aDate.month && day < aDate.day)) {
		return LESS;
	}
	else if (year > aDate.year || (year >= aDate.year && month > aDate.month) || (year >= aDate.year && month >= aDate.month && day > aDate.day)) {
		return GREATER;
	}
}

int DateType::ComparedCentury(DateType aDate){
	int sYear = year, otheryear = aDate.year;			// to avoid changing member variables here

	year / 100;
	otheryear / 100;

	if (year < otheryear) {
		return LESS;
	}
	else if (year == otheryear) {
		return EQUAL;
	}
	else if (year > year) {
		return GREATER;
	}
}

void DateType::AdvanceDays(int NumDays) {

	if (NumDays == 0) {
		return;
	}

	int monthDays, yearDays;

	bool isLeapYear = (((year % 4 == 0) && (year % 400 == 0)) || ((year % 4 == 0) && (year % 100 != 0))) ? true : false;

	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		monthDays = 31;
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		monthDays = 30;
		break;
	}

	if (isLeapYear == true) {
		yearDays = 366;
		if (month == 2) {
			monthDays = 29;
		}
	}
	else {
		yearDays = 365;
		if (month == 2) {
			monthDays = 28;
		}
	};

	if (NumDays > 0) {			// positive enter choice

		while (NumDays > 0) {		// start copy

			while (month <= 12 && NumDays > 0) {

				isLeapYear = (((year % 4 == 0) && (year % 400 == 0)) || ((year % 4 == 0) && (year % 100 != 0))) ? true : false;	// leap year and month day calculations

				switch (month) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					monthDays = 31;
					break;

				case 4:
				case 6:
				case 9:
				case 11:
					monthDays = 30;
					break;
				case 13:
					monthDays = 31;
					break;
				}

				if (isLeapYear == true) {
					yearDays = 366;
					if (month == 2) {
						monthDays = 29;
					}
				}
				else {
					yearDays = 365;
					if (month == 2) {
						monthDays = 28;
					}
				}							// end of leap year and monthDay calculations

				while (NumDays < 0 && NumDays > yearDays && isLeapYear == false) {		// year shortcut
					NumDays -= yearDays;
					year++;
					continue;
				}

				while (day < monthDays && NumDays > 0) {	// primary day loop
					day++;
					NumDays--;
				}

				if (NumDays == 0) {
					break;
				}
				if (NumDays == 0 && day < monthDays) {
					break;
				}
				else if (day == monthDays && NumDays > 0) {
					month++;
					if (month != 13) {
						day = 1;
					}
					NumDays--;
				}

				if (month == 13 && day == 31) {		// here
					month = 1;
					day = 1;
					year++;
				}

			}

			if (NumDays <= 0) {
				break;
			}
		}			// end copy
	}													// split +/-
	else if (NumDays < 0) {
		while (NumDays < 0) {		// start copied

			while (month >= 1 && NumDays < 0) {

				isLeapYear = (((year % 4 == 0) && (year % 400 == 0)) || ((year % 4 == 0) && (year % 100 != 0))) ? true : false;	// leap year and month day calculations

				switch (month) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					monthDays = 31;
					break;

				case 4:
				case 6:
				case 9:
				case 11:
					monthDays = 30;
					break;
				case 13:
					monthDays = 31;
					break;
				}

				if (isLeapYear == true) {
					yearDays = 366;
					if (month == 2) {
						monthDays = 29;
					}
				}
				else {
					yearDays = 365;
					if (month == 2) {
						monthDays = 28;
					}
				}							// end of leap year and monthDay calculations

				while (NumDays < 0 && NumDays > yearDays && isLeapYear == false) {		// year shortcut
					NumDays += yearDays;
					year--;
					continue;
				}

				while (day > 1 && NumDays < 0) {	// primary day loop
					day--;
					NumDays++;
				}

				if (NumDays == 0) {
					break;
				}
				if (day > 1) {
					continue;
				}
				else if (day == 1 && NumDays < 0) {		// use of leap year calculation
					month--;
					if (month > 0) {
						switch (month) {
						case 1:
						case 3:
						case 5:
						case 7:
						case 8:
						case 10:
						case 12:
							monthDays = 31;
							break;

						case 4:
						case 6:
						case 9:
						case 11:
							monthDays = 30;
							break;
						}

						if (isLeapYear == true) {
							if (month == 2) {
								monthDays = 29;
							}
						}
						else {
							if (month == 2) {
								monthDays = 28;
							}
						}

						day = monthDays;
					}
					NumDays++;
				}

				if (month == 0 && day == 1) {		// change of year
					month = 12;
					day = 31;
					year--;
				}

			}			// month loop

			if (NumDays >= 0) {
				break;
			}		// outer loop
		}			// end copy
	}				// end of < 0
	else {
		char bell = '%' - 30;
		cout << endl << endl << "Error! In function 'AdvanceDays'" << bell << endl << endl;
		return;
	}
};

void DateType::BackDays(int NumDays) {
	if (NumDays == 0) {
		return;
	}

	int monthDays, yearDays, i = NumDays;

	bool isLeapYear = (((year % 4 == 0) && (year % 400 == 0)) || ((year % 4 == 0) && (year % 100 != 0))) ? true : false;		// leap year checker

	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		monthDays = 31;
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		monthDays = 30;
		break;
	}

	if (isLeapYear == true) {
		yearDays = 366;
		if (month == 2) {
			monthDays = 29;
		}
	}
	else {
		yearDays = 365;
		if (month == 2) {
			monthDays = 28;
		}
	};

	if (i > 0) {			// positive enter choice

		i = 0 - NumDays;

		while (i < 0) {		// start copied

			while (month >= 1 && i < 0) {

				isLeapYear = (((year % 4 == 0) && (year % 400 == 0)) || ((year % 4 == 0) && (year % 100 != 0))) ? true : false;	// leap year and month day calculations

				switch (month) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					monthDays = 31;
					break;

				case 4:
				case 6:
				case 9:
				case 11:
					monthDays = 30;
					break;
				case 13:
					monthDays = 31;
					break;
				}

				if (isLeapYear == true) {
					yearDays = 366;
					if (month == 2) {
						monthDays = 29;
					}
				}
				else {
					yearDays = 365;
					if (month == 2) {
						monthDays = 28;
					}
				}							// end of leap year and monthDay calculations

				while (i < 0 && i > yearDays && isLeapYear == false) {		// year shortcut
					i += yearDays;
					year--;
					continue;
				}

				while (day > 1 && i < 0) {	// primary day loop
					day--;
					i++;
				}

				if (i == 0) {
					break;
				}
				if (day > 1) {
					continue;
				}
				else if (day == 1 && i < 0) {		// use of leap year calculation
					month--;
					if (month > 0) {
						switch (month) {
						case 1:
						case 3:
						case 5:
						case 7:
						case 8:
						case 10:
						case 12:
							monthDays = 31;
							break;

						case 4:
						case 6:
						case 9:
						case 11:
							monthDays = 30;
							break;
						}

						if (isLeapYear == true) {
							if (month == 2) {
								monthDays = 29;
							}
						}
						else {
							if (month == 2) {
								monthDays = 28;
							}
						}

						day = monthDays;
					}
					i++;
				}

				if (month == 0 && day == 1) {		// change of year
					month = 12;
					day = 31;
					year--;
				}
			}			// month loop

			if (i >= 0) {
				break;
			}		// outer loop
		}			// end copy
			
	}
	else if (i < 0) {

		while (i < 0) {		// start copy

			while (month <= 12 && i < 0) {

				isLeapYear = (((year % 4 == 0) && (year % 400 == 0)) || ((year % 4 == 0) && (year % 100 != 0))) ? true : false;	// leap year and month day calculations

				switch (month) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					monthDays = 31;
					break;

				case 4:
				case 6:
				case 9:
				case 11:
					monthDays = 30;
					break;
				}

				if (isLeapYear == true) {
					yearDays = 366;
					if (month == 2) {
						monthDays = 29;
					}
				}
				else {
					yearDays = 365;
					if (month == 2) {
						monthDays = 28;
					}
				}							// end of leap year and monthDay calculations

				while (i < 0 && i > yearDays && isLeapYear == false) {		// year shortcut
					i -= yearDays;
					year++;
					continue;
				}

				while (day < monthDays && i < 0) {	// primary day loop
					day++;
					i++;
				}

				if (i == 0) {
					break;
				}
				if (i == 0 && day < monthDays) {
					break;
				}
				else if (day == monthDays && i < 0) {
					month++;
					if (month != 13) {
						day = 1;
					}
					i++;
				}

				if (month == 13 && day == 31) {
					month = 1;
					day = 1;
					year++;
				}
			}

			if (i <= 0) {
				break;
			}
		}			// end copy
	}													// split +/-
	else if (i < 0) {
		while (i < 0) {		// start copied

			while (month <= 13 && i < 0) {

				isLeapYear = (((year % 4 == 0) && (year % 400 == 0)) || ((year % 4 == 0) && (year % 100 != 0))) ? true : false;	// leap year and month day calculations

				switch (month) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					monthDays = 31;
					break;

				case 4:
				case 6:
				case 9:
				case 11:
					monthDays = 30;
					break;
				case 13:
					monthDays = 31;
					break;
				}

				if (isLeapYear == true) {
					yearDays = 366;
					if (month == 2) {
						monthDays = 29;
					}
				}
				else {
					yearDays = 365;
					if (month == 2) {
						monthDays = 28;
					}
				}							// end of leap year and monthDay calculations

				while (i < 0 && (i <= 0 - yearDays) && isLeapYear == false) {		// year shortcut
					i += yearDays;
					year++;
					continue;
				}

				while (day > 1 && i < 0) {	// primary day loop
					day++;
					i++;
				}

				if (i >= 0) {
					break;
				}
				if (day > 1) {
					continue;
				}
				else if (day == monthDays && i < 0) {
					month++;
					day = 1;
					i++;
				}

				if (month == 13 && day == 1) {		// change of year
					month = 1;
					year++;
				}

			}			// month loop

			if (i >= 0) {
				break;
			}		// outer loop
		}			// end copy
	}
	else {
		char bell = '%' - 30;
		cout << endl << endl << "Error! In function 'BackDays'" << bell << endl << endl;
		return;
	}
};

bool DateType::IsValidDate(int newMonth, int newDay, int newYear) {

	bool isLeapYear = (((newYear % 4 == 0) && (newYear % 400 == 0)) || ((newYear % 4 == 0) && (newYear % 100 != 0))) ? true : false;

	if (newMonth < 1 || newMonth > 12) {
		return false;
	}

	if (newDay > 31 || newDay < 0) {
		return false;
	}
	// 30 days
	if (newMonth == 4 || newMonth == 6 || newMonth == 9 || newMonth == 11) {
		if (newDay > 30) {
			return false;
		}
	}

	if (newMonth == 2) {
		if (isLeapYear == true) {
			if (newDay > 29) {
				return false;
			}
		}
		else if (isLeapYear == false) {
			if (newDay > 28) {
				return false;
			}
		}
	}
	return true;
}

void DateType::SetRandomDate() {
	int day = 0, month = 0, year = 0, monthDays = 0;
	bool isLeapYear = (((year % 4 == 0) && (year % 400 == 0)) || ((year % 4 == 0) && (year % 100 != 0))) ? true : false;

	month = (rand() % 12) + 1;

	year = rand ();

	isLeapYear = (((year % 4 == 0) && (year % 400 == 0)) || ((year % 4 == 0) && (year % 100 != 0))) ? true : false;

	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		monthDays = 31;
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		monthDays = 30;
		break;
	}

	if (isLeapYear == true) {
		if (month == 2) {
			monthDays = 29;
		}
	}
	else {
		if (month == 2) {
			monthDays = 28;
		}
	}

	day = (rand() % monthDays) + 1;

	if (IsValidDate(month, day, year) == true) {
		SetDate(month, day, year);
	}
	else {
		char bell = '%' - 30;
		cout << endl << endl << "Error! In the random date function. " << bell << system("pause") << endl << endl;
	}
}

bool DateType::operator> (const DateType& aDate) {				// operation overload, >
	bool greaterThan = (year > aDate.year || (year >= aDate.year && month > aDate.month) || (year >= aDate.year) && (month >= aDate.month) && (day > aDate.day)) ? true : false;

	return greaterThan;
}

bool DateType::operator< (const DateType& aDate) {				// operation overload, <
	bool lessThan = (year < aDate.year || (year <= aDate.year && month < aDate.month) || (year <= aDate.year) && (month <= aDate.month) && (day < aDate.day)) ? true : false;

	return lessThan;
}

bool DateType::operator== (const DateType& aDate) {				// operation overload, ==
	bool equalTo = (day == aDate.day && month == aDate.month && year == aDate.year) ? true : false;

	return equalTo;
}

bool DateType::operator!= (const DateType& aDate){				// operation overload, !=
	bool inEqualTo = (day != aDate.day || month != aDate.month || year != aDate.year) ? true : false;

	return inEqualTo;
}

bool DateType::operator>= (const DateType& aDate) {				// operation overload, >=
	bool GreaterEqualTo = (year > aDate.year || (year >= aDate.year && month > aDate.month) || (year >= aDate.year) && (month >= aDate.month) && (day >= aDate.day)) ? true : false;

	return GreaterEqualTo;
}

bool DateType::operator<= (const DateType& aDate) {				// operation overload, <=
	bool lessEqualTo = (year < aDate.year || (year <= aDate.year && month < aDate.month) || (year <= aDate.year) && (month <= aDate.month) && (day <= aDate.day)) ? true : false;

	return lessEqualTo;
}

DateType DateType::operator+ (int numDays) {					// operation overload, +
	DateType RHV;
	int i = numDays;

	if (IsValidDate(month, day, year) == true) {
		RHV.SetDate(month, day, year);
	}
	else {
		char bell = '%' - 30;
		cout << endl << endl << "Error! In the 'operator+' function" << bell << endl << endl;
	}

	RHV.AdvanceDays(i);

	return RHV;
}

DateType DateType::operator- (int numDays) {					// operation overload, -
	DateType RHV;
	int i = numDays;

	if (IsValidDate(month, day, year) == true) {
		RHV.SetDate(month, day, year);
	}
	else {
		char bell = '%' - 30;
		cout << endl << endl << "Error! In the 'operator-' function. " << bell << system("pause") << endl << endl;
	}

	RHV.BackDays(i);

	return RHV;
}

int DateType::operator- (const DateType& aDate) {
	bool isLeap = false;
	int yearDays, monthDays, answer = 0, tempMonth = month, tempYear = year, tempDay = day;
	isLeap = (((tempYear % 4 == 0) && (tempYear % 400 == 0)) || ((tempYear % 4 == 0) && (tempYear % 100 != 0))) ? true : false;

	if (tempDay == aDate.day && tempMonth == aDate.month && tempYear == aDate.year) {
		return 0;
	}
	else if (tempYear == aDate.year && tempMonth == aDate.month && tempDay >= aDate.day) {
		return (tempDay - aDate.day);
	}

	switch (tempMonth) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		monthDays = 31;
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		monthDays = 30;
		break;
	}
	if (isLeap == true) {
		yearDays = 366;
		if (tempMonth == 2) {
			monthDays = 29;
		}
	}
	else {
		yearDays = 365;
		if (tempMonth == 2) {
			monthDays = 28;
		}
	};											// end of initial setting of variables
												// loop for year, then month, then day

	isLeap = (((tempYear % 4 == 0) && (tempYear % 400 == 0)) || ((tempYear % 4 == 0) && (tempYear % 100 != 0))) ? true : false;

		while (tempYear > aDate.year) {			// year loop, 1st = greater
			isLeap = (((tempYear % 4 == 0) && (tempYear % 400 == 0)) || ((tempYear % 4 == 0) && (tempYear % 100 != 0))) ? true : false;
			if (isLeap == true) {
				yearDays = 366;
			}
			else {
				yearDays = 365;
			};
			tempYear--;
			answer += yearDays;
		}										// end year loop

		while (tempYear < aDate.year) {			// year loop, 1st = less
			isLeap = (((tempYear % 4 == 0) && (tempYear % 400 == 0)) || ((tempYear % 4 == 0) && (tempYear % 100 != 0))) ? true : false;
			if (isLeap == true) {
				yearDays = 366;
			}
			else {
				yearDays = 365;
			};
			tempYear++;
			answer -= yearDays;
		}										// end year loop

		if (tempMonth < aDate.month) {
			isLeap = (((tempYear % 4 == 0) && (tempYear % 400 == 0)) || ((tempYear % 4 == 0) && (tempYear % 100 != 0))) ? true : false;
			while (tempMonth < aDate.month && tempMonth != 13) {
				switch (tempMonth) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					monthDays = 31;
					break;

				case 4:
				case 6:
				case 9:
				case 11:
					monthDays = 30;
					break;
				}
				if (isLeap == true) {
					if (tempMonth == 2) {
						monthDays = 29;
					}
				}
				else {
					if (tempMonth == 2) {
						monthDays = 28;
					}
				};
				tempMonth++;
				answer -= monthDays;

			}
		}
		else if (tempMonth > aDate.month) {
			isLeap = (((tempYear % 4 == 0) && (tempYear % 400 == 0)) || ((tempYear % 4 == 0) && (tempYear % 100 != 0))) ? true : false;
			while (tempMonth > aDate.month && tempMonth != 0) {
				switch (tempMonth) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					monthDays = 31;
					break;

				case 4:
				case 6:
				case 9:
				case 11:
					monthDays = 30;
					break;
				}
				if (isLeap == true) {
					if (tempMonth == 2) {
						monthDays = 29;
					}
				}
				else {
					if (tempMonth == 2) {
						monthDays = 28;
					}
				};
				tempMonth--;
				answer += monthDays;

			}
		}				// end of month checker. check day, same method as used to check month
		
		if (tempDay == aDate.day) {
			return answer;
		}
		else if (tempDay > aDate.day) {
			while (tempDay > aDate.day && tempDay != aDate.day) {
				tempDay--;
				answer++;
			}
			return answer;
		}
		else if (tempDay < aDate.day){
			while (tempDay < aDate.day && tempDay != aDate.day) {
				tempDay++;
				answer--;
			}
			return answer;
		}

	//return answer;
}

ostream& operator<< (ostream& output, const DateType& aDate) {
	if (&output == &cout) {
		return cout << aDate.month << '/' << aDate.day << '/' << aDate.year;
	}
	else if (&output != &cout) {

		output << aDate.month << ' ' << aDate.day << ' ' << aDate.year;
		
		return output;
	}
	else {
		char bell = '%' - 30;
		cout << endl << endl << "Error! In ofstream function in DateType.cpp" << bell << endl << endl;
		system("pause");
	}
}

 istream& operator>> (istream& input, DateType& aDate) {
	 if (&input == &cin) {
		 int localDay = aDate.day, localMonth = aDate.month, localYear = aDate.year;
		 string date;

		aDate.ReadDate();
		
		return input;
	 }
	 else if (&input != &cin) {
		 int localDay, localMonth, localYear;
		 string date;
		
		 input >> localDay >> localMonth >> localYear;

		 if (aDate.IsValidDate(localMonth, localDay, localYear)) {

			 aDate.SetDate(localMonth, localDay, localYear);
		 }

		return input;
		 
	 }
	 else {
		 char bell = '%' - 30;
		 cout << endl << endl << "Error! In ifstream function in DateType.cpp" << bell << endl << endl;
		 system("pause");
	 }
 }