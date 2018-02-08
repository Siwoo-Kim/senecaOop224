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

#include "CRA_Account.h"

using namespace std;
using namespace sict;


void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
	
	bool valid = false;

	if (validateNames(familyName) && validateNames(givenName)) {
		if ((sin > min_sin) && (sin < max_sin)) {
			if (validateSin(sin)) {
				valid = true;
			}
		}
	}

	if (valid) {
		strcpy(fName, familyName);
		strcpy(gName, givenName);
		this->sin = sin;
	}

}

bool CRA_Account::validateNames(const char* name) {
	int lengthOfString = strlen(name);
	return lengthOfString < max_name_length && lengthOfString > 0 ? true : false;
}

bool CRA_Account::validateSin(int ssn) {
	int accumulate = 0;
	int otherAlternate = 0;

	for (int i = 8; i >= 1; i--) {
		if (i % 2 != 0) {
			int setOfNums = getPartOfNumber(ssn, i) * 2;
			accumulate += getSetOfNumber(setOfNums, i - 1);
		}
		else {
			otherAlternate += getPartOfNumber(ssn, i);
		}
	}

	int accumulate2 = 0;

	for (int i = 7; i >= 0; i--) {
		accumulate2 += getPartOfNumber(accumulate, i);
	}

	int nextHightestInteger = ceil((accumulate2 + otherAlternate) / 10.0) * 10;
	int difference = nextHightestInteger - (accumulate2 + otherAlternate);

	int lastDigit = getPartOfNumber(ssn, 0);
	return lastDigit == difference;
}



int CRA_Account::getSetOfNumber(int ssn, int position) {
	int decimalPoint = 1;

	for (int i = 0; i<position; i++) { decimalPoint *= 10; }

	return (int)(ssn * decimalPoint);
}

int  CRA_Account::getPartOfNumber(int ssn, int position) {
	int decimalPoint = 1;

	for (int i = 0; i<position; i++) {
		decimalPoint *= 10;
	}


	int result = (int)(ssn / decimalPoint);

	int nextPosition = decimalPoint > max_sin ? -1 : (int)(ssn / (decimalPoint * 10));

	if (nextPosition != -1) {
		result = result - (nextPosition * 10);
	}

	return result;
}


void CRA_Account::set(int year, double balance) {

	bool valid = false;

	if (numOfYears < max_yrs && !isEmpty() ) {
		valid = true;
	}
	

	if (valid) {
		this->balanceOwed[numOfYears] = balance;
		this->taxReturnYears[numOfYears++] = year;
	}

}

bool CRA_Account::isEmpty() const {
	return ( max_sin > sin && sin > min_sin ) ? false: true;
}

void CRA_Account::display() const {
	bool isNotEmpty = !isEmpty();
	


	if (isNotEmpty) {
		cout << "Family Name: " << fName << endl;
		cout << "Given Name : " << gName << endl;
		cout << "CRA Account: " << sin << endl;

		for (int i = 0; i < max_yrs; i++) {
			cout.setf(ios::fixed);
			cout.precision(2);

			if (balanceOwed[i] > 2) {
				cout << "Year (" << taxReturnYears[i];
				cout.precision(2);
				cout<<") balance owing: " << balanceOwed[i] << endl;
				cout.precision(0);
			}
			else if (balanceOwed[i] < -2 ){

				cout << "Year (" << taxReturnYears[i];
				cout.precision(2);
				cout << ") refund due: " << -balanceOwed[i] << endl;
				cout.precision(0);

			}
			else {
				cout << "Year (" << taxReturnYears[i];
				cout << ") No balance owing or refund due!" << endl;

			}
		}
	}
	else {
		cout << "Account object is empty!" << endl;
	}
}