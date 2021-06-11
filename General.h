#pragma once
#include "Setting.h"
#include "CommonInfo.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class General : public Setting,public CommonInfo {
public:
	
	General();
	General(const General& h);							//Copy method
	General(Setting h, string time, string ngonngu);//Copy constructor
	General& operator = (General& m);				//Assign operator
	~General();										//Destructor		
	void nhapThongTin();							//virtual method from base class
	void xuatThongTin();							//virtual method from base class		
	
	//Getter
	string get_language();
	string get_timeZone();


	//Setter
	void set_timeZone(string data);
	void set_language(string data1);
	
	bool operator < (const General& right);
	bool operator > (const General& right);
	bool operator == (const General& right);
	friend  bool operator==(const General& lhs, const General& rhs);
	friend  bool operator<(const General& lhs, const General& rhs);
	friend  bool operator>(const General& lhs, const General& rhs);

private:
	string timeZone;
	string language;
};

