

#include "CRA_Account.h"

using namespace std;
using namespace sict;


void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
	
	bool valid = false;

	if ((sin > min_sin) && (sin < max_sin)) {
		valid = true;
	}
	else {
		valid = false;
	}

	if (valid) {
		strcpy(fName, familyName);
		strcpy(gName, givenName);
		this->sin = sin;
	}

}

bool CRA_Account::isEmpty() const {
	return ( max_sin > sin && sin > min_sin ) ? false: true;
}

void CRA_Account::display() const {
	if (!isEmpty()) {
		cout << "Family Name: " << fName << endl;
		cout << "Given Name : " << gName << endl;
		cout << "CRA Account: " << sin << endl;
	}
	else {
		cout << "Account object is empty!" << endl;
	}
}