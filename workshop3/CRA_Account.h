/**********************************************************
// Workshop 3: Classes and Privacy
// w3_in_lab.cpp
// Version 2.1
// 2017/09/09
// Chris Szalwinski
// Description
// This workshop demonstrates classes in C++ and
// how member variables are defined privately, but
// accessed through public member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Siwoo Kim        2018/02/06            134958164
///////////////////////////////////////////////////////////
**********************************************************/

#pragma once
#ifndef sict_sca_account_h
#define sict_sca_account_h

#include <cmath>
#include <cstring>
#include <iostream>

namespace sict {
	static const int max_name_length  = 40;
	static const int min_sin = 100000000;
	static const int max_sin = 999999999;
	static const int max_yrs = 4;

	class CRA_Account{
		char fName[max_name_length + 1];
		char gName[max_name_length + 1];
		int sin;
		int taxReturnYears[max_yrs];
		double balanceOwed[max_yrs];
		int numOfYears;
	public:
		CRA_Account() {
			strcpy(fName, "");
			strcpy(gName, "");
			sin = 0;
			numOfYears = 0;
		}

		void set(const char* familyName, const char* givenName, int sin);
		void set(int year, double balance); //stores the balance in the object
		

		bool validateSin(int ssn);
		bool validateNames(const char* name);
		
		int getPartOfNumber(int ssn, int position);
		int getSetOfNumber(int setOfNumber, int posistion);

		bool isEmpty() const;
		void display() const;
	};

}

#endif // !1
