#pragma once

#ifndef sict_sca_account_h
#define sict_sca_account_h

#include <cstring>
#include <iostream>

namespace sict {
	static const int max_name_length  = 40;
	static const int min_sin = 100000000;
	static const int max_sin = 999999999;


	class CRA_Account{
		char fName[max_name_length + 1];
		char gName[max_name_length + 1];
		int sin;
	public:
		CRA_Account() {
			strcpy(fName, "");
			strcpy(gName, "");
			sin = 0;
		}
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};

}

#endif // !1