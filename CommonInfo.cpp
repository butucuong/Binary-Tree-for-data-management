#include "CommonInfo.h"
CommonInfo::CommonInfo() {};
CommonInfo::~CommonInfo() {};
void CommonInfo::doc(ifstream& in)					//Xu li chuoi doc tu file
{
	string a{}, b{}, c{};
	in >> a >> b;									//a:So ; b:Dau '/'
	in.seekg(1, 1);									//Bo qua khoang trang

	getline(in, c);									//c:chuoi
	this->setName(c);
	this->setNumber(a);
}
istream& operator>>(istream& is, CommonInfo& p) {	//Phuong thuc Friend de mo rong cach su dung cua toan tu >>
	is >> p.number >> p.dash >> p.name;
	return is;
}
ostream& operator<<(ostream& os, const CommonInfo& p) {

	os << setw(5) << p.number << setw(30) << p.name;
	return os;

}
CommonInfo::CommonInfo(const CommonInfo& h) {
	this->dash = h.dash;
	this->name = h.name;
	this->number = h.number;

}
CommonInfo& CommonInfo:: operator=(CommonInfo& m) {
	if (this == &m) return (*this);
	this->dash = m.dash;
	this->name = m.name;
	this->number = m.number;

}

bool CommonInfo::operator > (const CommonInfo& right)
{
	bool status;

	if (extractTime(number) > extractTime(right.number))
		status = true;
	else
		status = false;

	return status;
}

bool CommonInfo::operator < (const CommonInfo& right)
{
	bool status;

	if (extractTime(number) < extractTime(right.number))
		status = true;
	else
		status = false;

	return status;
}

bool CommonInfo::operator == (const CommonInfo& right)
{
	bool status;

	if (extractTime(number) == extractTime(right.number))
		status = true;
	else
		status = false;

	return status;
}

bool operator==(const CommonInfo& lhs, const CommonInfo& rhs) {
	bool status;
	if (lhs.name == rhs.name) {
		status = true;
	}

	else
		status = false;
	return status;
}
bool operator<(const CommonInfo& lhs, const CommonInfo& rhs) {
	bool status;
	if (lhs.name < rhs.name) {
		status = true;
	}
	else
		status = false;
	return status;
}
bool operator>(const CommonInfo& lhs, const CommonInfo& rhs) {
	bool status;
	if (lhs.name > rhs.name) {
		status = true;
	}
	else
		status = false;
	return status;
}

int CommonInfo::extractTime(string str) {
	int a;
	string temp;
	for (auto x : str) {
		if (isdigit(x) || x == '+' || x == '-') {
			temp += x;

		}
	}
	a = stoi(temp);

	return a;
}