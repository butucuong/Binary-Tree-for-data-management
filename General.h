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
	General(Setting h);								//Paratemersize constructor 
	General& operator = (General& m);				//Assign operator
	~General();										//Destructor		
	void nhapThongTin();							//virtual method from base class
	void xuatThongTin();							//virtual method from base class		
	
	//Getter
	string getLanguage();
	string getTimezone();


	//Setter
	void setTimezone(string timezone);
	void setLanguage(string language);
	
	bool operator < (const General& right);
	bool operator > (const General& right);
	bool operator == (const General& right);
	//lhs= left-hand-size 
	//rhs= right-hand-size
	friend  bool operator==(const General& lhs, const General& rhs);
	friend  bool operator<(const General& lhs, const General& rhs);
	friend  bool operator>(const General& lhs, const General& rhs);

private:
	string m_timezone;
	string m_language;
};

