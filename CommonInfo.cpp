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
	is >> p.m_number >> p.m_dash >> p.m_name;
	return is;
}
ostream& operator<<(ostream& os, const CommonInfo& p) {

	os << setw(5) << p.m_number << setw(30) << p.m_name;
	return os;

}
CommonInfo::CommonInfo(const CommonInfo& h) {
	this->m_dash = h.m_dash;
	this->m_name = h.m_name;
	this->m_number = h.m_number;

}
CommonInfo& CommonInfo:: operator=(CommonInfo& m) {
	if (this == &m) return (*this);
	this->m_dash = m.m_dash;
	this->m_name = m.m_name;
	this->m_number = m.m_number;
	return (*this);
}

bool CommonInfo::operator > (const CommonInfo& right)
{
	bool status;

	if (extractTime(m_number) > extractTime(right.m_number))
		status = true;
	else
		status = false;

	return status;
}

bool CommonInfo::operator < (const CommonInfo& right)
{
	bool status;

	if (extractTime(m_number) < extractTime(right.m_number))
		status = true;
	else
		status = false;

	return status;
}

bool CommonInfo::operator == (const CommonInfo& right)
{
	bool status;

	if (extractTime(m_number) == extractTime(right.m_number))
		status = true;
	else
		status = false;

	return status;
}

bool operator==(const CommonInfo& lhs, const CommonInfo& rhs) {
	bool status;
	if (lhs.m_name == rhs.m_name) {
		status = true;
	}

	else
		status = false;
	return status;
}
bool operator<(const CommonInfo& lhs, const CommonInfo& rhs) {
	bool status;
	if (lhs.m_name < rhs.m_name) {
		status = true;
	}
	else
		status = false;
	return status;
}
bool operator>(const CommonInfo& lhs, const CommonInfo& rhs) {
	bool status;
	if (lhs.m_name > rhs.m_name) {
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