#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class CommonInfo{
public:
	CommonInfo();
	CommonInfo(const CommonInfo& h);
	CommonInfo& operator=(CommonInfo& m);
	~CommonInfo();
	string getNumber() {
		return number;
	};
	string getName() {
		return name;
	};
	
	void setNumber(string data) {
		number = data;
	};
	
	void setName(string data1) {
		name = data1;
	};
	
	void printData(vector<CommonInfo>a) {
		for (size_t i = 0; i < a.size(); i++) {
			cout << setw(3) << i + 1 << ": " << setw(20)<<left << a.at(i).getNumber() << setw(30)<< a.at(i).getName() << endl;
		}
	};
		
	void doc(ifstream&);
	friend istream& operator>>(istream& is, CommonInfo& p);
	friend ostream& operator<<(ostream& os, const CommonInfo& p);

	int extractTime(string str);
	//Compare by Timezone
	bool operator < (const CommonInfo& right);
	bool operator > (const CommonInfo& right);
	bool operator == (const CommonInfo& right);
	//Compare by Alphalbet
	friend bool operator==(const CommonInfo& lhs, const CommonInfo& rhs);
	friend bool operator<(const CommonInfo& lhs, const CommonInfo& rhs);
	friend bool operator>(const CommonInfo& lhs, const CommonInfo& rhs);
protected:
	string number{""};
	string name{ "" };
	string dash{""};
};

