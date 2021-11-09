#include"DateType.h"
#include<fstream>
#include<ostream>
#include<iomanip>
#include<ctime>
#include<cctype>
#include<cstdlib>

using namespace std;

int main(){
	srand(time(0));					// Only need to seed once

	DateType date1, date2;		//2 DateType objects for testing
	ofstream fout;				//file output
	ifstream fin;				//file input
	char fileName[50];			//for storing the file name

	int i;	//For storing integers
		
	bool inMenu = true;	// while the user is using the program this var is set to true and the menu keeps looping.
						// when the user wants to quit, it is set to false and the loop ends.

	char keyPressed;	// This var stores which menu selection the user picks.

	while (inMenu){
		cout<< endl << endl << endl;
		cout << "****************************************************" << endl;
		cout  <<"**  MENU:(press a character to select an option)  **" << endl;
 		cout << "****************************************************" << endl;
		cout<<"Q. [QUIT]     Quit."<<endl;
		cout << endl;

		cout<<"S. [Set random dates] Test the SetRandomDate method,"<<endl;
		cout << endl;

		cout<<"R. [Relational Opetators]  Test all the relational operators"<<endl;
		cout << endl;

		cout<<"A. [Arithmatic Operatos]    Test all the arithmatic operators" << endl;
		cout << endl;
		cout<<"C. [Console input / output]  Test \"cout << date\" and \"cin >> date\" "<<endl;
		cout << endl;
		cout<<"F. [File input / output]  Test \"fout << date\" and \"fin >> date\" "<<endl;
		cout << endl;

		cout << "****************************************************" <<endl<< endl;

		cout<<"Your choice is: ";
		cin >> keyPressed;

		switch(keyPressed) {
		case 'Q': case 'q':						//Quit
			cout << "[QUIT]:" << endl;
			inMenu = false;
			break;

		case 'S': case 's':
			cout << endl << endl << "******************************************************************" << endl;
			cout << "***   Test 1: Call date1, a DateType object declared in the main function," << endl;
			cout << "***		to perform the SetRandomDate method 10 times " << endl;
			cout << "***		to generate 10 random dates." << endl;
			cout << "******************************************************************" << endl << endl;

		for (i=0; i<10; i++){
			date1.SetRandomDate();
			cout << endl << "Set a new random date: "<<endl;
			date1.PrintDate();

		}

		cout << endl << endl << "*****************************************" << endl
			 << "*  Do the dates above really look random? " << endl
			 << "*****************************************" << endl;

		break;

		case 'R': case 'r':
			cout << endl << endl << "******************************************************************" << endl;
			cout << "***   Test 2: test all the relational operators " << endl;
			cout << "***		on two DateType objects, date1 and date2 declared " << endl;
			cout << "***		in the main function                           " << endl;
			cout << "******************************************************************" << endl;

			cout << endl << endl << "Read a date into date1:" << endl ;
			date1.ReadDate();
		    
			cout << endl << endl << endl << "Read a date into date2:" << endl ;
			date2.ReadDate();

			cout << endl << endl << "Date 1 = ";
			date1.PrintDate();

			cout << endl << "Date 2 = ";
			date2.PrintDate();

			cout << endl << endl << "Test whether date1 > date2" << endl ; // > overloaded operator test
			if (date1 > date2) {
				cout << "Yes. (date1 > date2) is true " << endl;
			}
			else {
				cout << "No. (date1 > date2) is false " << endl;
			}
		    
			cout << endl << endl << "Test whether date1 < date2" << endl ; // < overloaded operator test
			if (date1 < date2) {
				cout << "Yes. (date1 < date2) is true " << endl;
			}
			else {
				cout << "No. (date1 < date2) is false " << endl;
			}

			cout << endl << endl << "Test whether date1 == date2" << endl ; // == overloaded operator test
			if (date1 == date2) {
				cout << "Yes. (date1 == date2) is true " << endl;
			}
			else {
				cout << "No. (date1 == date2) is false " << endl;
			}

			cout << endl << endl << "Test whether date1 != date2" << endl ; // != overloaded operator test
			if (date1 != date2) {
				cout << "Yes. (date1 != date2) is true " << endl;
			}
			else {
				cout << "No. (date1 != date2) is false " << endl;
			}

			cout << endl << endl << "Test whether date1 >= date2" << endl ; // >= overloaded operator test
			if (date1 >= date2) {
				cout << "Yes. (date1 >= date2) is true " << endl;
			}
			else {
				cout << "No. (date1 >= date2) is false " << endl;
			}

			cout << endl << endl << "Test whether date1 <= date2" << endl ; // <= overloaded operator test
			if (date1 <= date2) {
				cout << "Yes. (date1 <= date2) is true " << endl;
			}
			else {
				cout << "No. (date1 <= date2) is false " << endl;
			}

			break;

		case 'A': case 'a':
			cout << endl << endl << "******************************************************************" << endl;
			cout << "***   Test 3: test all the arithmetic operators " << endl;
			cout << "***		on two DateType objects, date1 and date2 declared " << endl;
			cout << "***		in the main function                           " << endl;
			cout << "******************************************************************" << endl;

			cout << endl << endl << "Read a date into date1:" << endl ;
			date1.ReadDate();
		    
			cout << endl << endl << "Read a date into date2:" << endl ;
			date2.ReadDate();

			cout << endl << endl << "Test the result of date1 - date2" << endl ; // - overloaded operator test
			cout << "(date1 - date2) equals " << date1 - date2 << endl;

		    
			cout << endl << endl << "Test the result of date2 = date1 - i;" << endl ; // - overloaded operator test
			cout << "(Give me an integer i, i = ";
			cin >> i;
			cout << endl << "Let date2 = date1 - " << i << endl;
			date2 = date1 - i;

			cout << " Now after \"date2 = date1 - i;\" we have date1 as " << endl;
			date1.PrintDate();
			cout << " Now after \"date2 = date1 - i;\" we have date2 as " << endl;
			date2.PrintDate();
		    
			cout << endl << endl << "Test the result of date2 = date1 + i;" << endl ; // + overloaded operator test
			cout << "(Give me an integer i, i = ";
			cin >> i;
			cout << endl << "Let date2 = date1 + " << i << endl;
			date2 = date1 + i;

			cout << " Now after \"date2 = date1 - i;\" we have date1 as " << endl;
			date1.PrintDate();
			cout << " Now after \"date2 = date1 - i;\" we have date2 as " << endl;
			date2.PrintDate();

			break;

		case 'C': case 'c':// 4. 

			cout << endl << endl << "******************************************************************" << endl;
			cout << "*** Test 4: Test \"cout << date\" and \"cin >> date\" " << endl;
			cout << "******************************************************************" << endl;

			cout << endl << endl << "Now do \"cin >> date1\" " << endl ;
			cin >> date1;

			cout << endl << endl << "The following is the result of \"cout << date1\" " << endl;
			cout << "after doing \"cin >> date1\" above " << endl ; 
			cout << date1 << endl;

			break;

		case 'F': case 'f':// 5.

		 cout << endl << endl << "******************************************************************" << endl;
		 cout << "*** Test 5: Test \"fout << date\" and \"fin >> date\" where" << endl;
		 cout << "***	fout is an ofstream object for file output, and  " << endl;
		 cout << "***	fin is an ifstream object for file input, and  " << endl;
		 cout  << "******************************************************************" << endl;

		 cout << endl << endl << "Give me a date to store into date1: ";
		 cin >> date1;

		 cout << endl << endl << "Now give me a file name and store date1 into the file: ";
		 cin >> fileName;

			cout << endl << endl << "Now do \"fout.open(" << fileName << ")\" to open the file" << endl ;
			fout.open(fileName);

			cout << endl << endl << "Now do \"fout << date1\" to store date1 into the file: " << fileName << endl ;
			fout << date1;
			fout.close();

			cout << endl << endl << "Now do \"fin.open(" << fileName << ")\" for file input" << endl ;
			fin.open(fileName);
			cout << endl << endl << "Now do \"fin >> date2\" to read the date back into date2" << endl ;
			fin >> date2;
			fin.close();

			cout << endl << endl << "The following is the result of \"cout << date2\" " << endl;
			cout << "after doing \"fin >> date2\" above to read the date from the file: ";
			cout << fileName << endl ; 
			cout << date2 << endl;

			break;

		default:
			cout << "[?? UNKNOWN COMMAND]:" << endl;		// Unrecognized key, do nothing
			break;
		}
	}
	return 0;
}