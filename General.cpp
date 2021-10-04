#include "General.h"
#include "CommonInfo.h"


//external vector
extern vector<CommonInfo> g_timezone_list;
extern vector<CommonInfo> g_language_list;

General::General() :Setting()                    //Default constructor
{
	m_timezone = m_language = "";
}
//General::General(Setting h, string time, string ngonngu) : Setting(h)
//{ //Parameter constructor
//	m_timezone = time;
//	m_language = ngonngu;
//}
General::General(Setting h)
	: Setting(h)

{
	const string C_DEFAULT_TIMEZONE = "(GMT-12:00)";
	const string C_DEFAULT_LANGUAGE = "Mandarin (entire branch)";
	m_timezone = C_DEFAULT_TIMEZONE;
	m_language = C_DEFAULT_LANGUAGE;
}
General::~General() {                                //Destructor

}
General::General(const General& h) :Setting(h), m_language(h.m_language), m_timezone(h.m_timezone) {
}

General& General::operator = (General& m) {            //Assign operator
	if (this == &m) return *this;

	Setting(*this) = Setting::operator=(m);
	this->m_language = m.m_language;
	this->m_timezone = m.m_timezone;
	return *this;
}

void General::nhapThongTin() {
	char ca[5], cb[5];
	bool flag{ false };

	int a{}, b{};
	cout << "\n--- SELECT TIMEZONE DATA ---\n";
	printData(g_timezone_list);
	try {
		while (flag != true) {

			cout << "\nYOUR SELECTION: ";
			cin >> ca;
			if (isdigit(ca[0])) {
				a = atoi(ca);
			}
			else continue;
			a = a - 1;
			if (a > 31) {
				cout << "Illegal choice, there are 32 timezones in data, please choose again." << endl;									//Xuat thong bao va bat dau lai vong lap neu nhap so lon hon du lieu
				continue;
			}
			cout << g_timezone_list.at(a).getNumber() << ":" << g_timezone_list.at(a).getName();

			setTimezone(g_timezone_list.at(a).getNumber());


			flag = true;
		}
	}
	catch (...) {
		cerr << "Illegal input" << endl;
		return;
	}

	flag = false;
	cout << "\n\n--- SELECT LANGUAGE DATA ---\n ";

	printData(g_language_list);
	try {
		while (flag != true) {

			cout << "\nYOUR SELECTION: ";
			cin >> cb;
			if (isdigit(cb[0])) {
				b = atoi(cb);
			}
			else continue;
			b = b - 1;
			if (b > 29) {
				cout << "Illegal choice, there are 30 languages in data." << endl;									//Xuat thong bao va bat dau lai vong lap neu nhap so lon hon du lieu
				continue;
			}
			cout << g_language_list.at(b).getNumber() << ":" << g_language_list.at(b).getName();
			setLanguage(g_language_list.at(b).getName());
			cout << endl;
			flag = true;
			system("pause");
		}
	}
	catch (...) {
		cerr << "Illegal input." << endl;
		system("pause");
		return;
	}
}

void General::xuatThongTin() {

	cout << "\nTimezone: " << getTimezone() << endl;
	cout << "Language: " << getLanguage() << endl;
}

unique_ptr<General> General::clone()
{
	return make_unique<General>(*this);
}

unique_ptr<General> General::create()
{
	return make_unique<General>();
}

string General::getLanguage() {
	return m_language;
}

string General::getTimezone() {
	return m_timezone;
}

void General::setTimezone(string data) {
	m_timezone = data;
}

void General::setLanguage(string data1) {
	m_language = data1;
}
bool General::operator > (const General& right)
{
	bool status;

	if (m_personal_key > right.m_personal_key)
		status = true;
	else
		status = false;

	return status;
}

bool General::operator < (const General& right)
{
	bool status;

	if (m_personal_key < right.m_personal_key)
		status = true;
	else
		status = false;

	return status;
}

bool General::operator == (const General& right)
{
	bool status;

	if (m_personal_key == right.m_personal_key)
		status = true;
	else
		status = false;

	return status;
}

bool operator==(const General& lhs, const General& rhs) {
	bool status;
	if (lhs.m_car_name == rhs.m_car_name) {
		status = true;
	}
	else
		status = false;
	return status;
}
bool operator<(const General& lhs, const General& rhs) {
	bool status;
	if (lhs.m_car_name < rhs.m_car_name) {
		status = true;
	}
	else
		status = false;
	return status;
}
bool operator>(const General& lhs, const General& rhs) {
	bool status;
	if (lhs.m_car_name > rhs.m_car_name) {
		status = true;
	}
	else
		status = false;
	return status;
}