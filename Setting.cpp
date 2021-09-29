#include "Setting.h"
#include <regex>
#include <cctype>

Setting::Setting()
{
	m_car_name="";
	m_personal_key="" ; 
	m_email= "";			
	m_odo=0;
	m_service_remind=0;
}
Setting::Setting(string name, string key, string mail, int n1, int n2) {
	m_car_name = name;
	m_personal_key = key;
	m_email = mail;
	m_odo = n1;
	m_service_remind = n2;
}
Setting::Setting(const Setting& h) {
	this->m_car_name = h.m_car_name;
	this->m_email = h.m_email;
	this->m_personal_key = h.m_personal_key;
	this->m_odo = h.m_odo;
	this->m_service_remind = h.m_service_remind;
}
Setting::~Setting(){
	
}
Setting& Setting::operator =(Setting& m) {
	if (this == &m) return *this;					//Avoid self-assigning

	this->m_car_name = m.m_car_name;
	this->m_email = m.m_email;
	this->m_personal_key = m.m_personal_key;
	this->m_odo = m.m_odo;
	this->m_service_remind = m.m_service_remind;
	return *this;
}
 
string Setting::getEmail()
{
	return m_email;
}

string Setting::getCarName() {
	return m_car_name;
}

string Setting::getPersonalKey() {

	return m_personal_key;
}

int Setting::getODO() {
	return m_odo;
}

int Setting::getServiceRemind() {
	return m_service_remind;
}



void Setting::setCarName(string data) {

	m_car_name = data;
}
void Setting::setPersonalKey(string data2) {
	m_personal_key = data2;

}
void Setting::setEmail(string data1)
{
	m_email = data1;
}

void Setting::setODO(int data3) {
	m_odo = data3;

}
void Setting::setServiceRemind(int data4) {
	m_service_remind = data4;

}

void Setting::nhapThongTin() {
	string a{}, b{}, c{};
	int d{}, e{};
	bool flag{ false };
	char cd[10], ce[10];


	cout << "--- Input Personal Data ---\n";
	cout << "Owner name: ";
	getline(cin, a);								//Nhap ten chu xe
	setCarName(a);

	/*---Nhap email---*/
	while (flag != true) {
		cout << "Email: ";
		getline(cin, b);
		size_t at = b.find('@');					//Tim trong chuoi nhap vao co ki tu '@' hay khong
		if (at == string::npos) {					//
			cout << "This is not an legel email, please follow this form: \"abc@xyz.def \" " << endl;

			continue;
		}
		size_t dot = b.find('.', at + 1);				//Tim trong chuoi nhap vao co ki tu '.' hay khong

		if (dot == string::npos) {					//
			cout << "This is not an legel email, please follow this form: \"abc@xyz.def \" " << endl;

			continue;
		}
		flag = true;


	}setEmail(b);									//Dap ung du dieu kien thi set gia tri cho Email
	cout << flush;


	/*---Nhap PersonalKey---*/
	flag = false;
	while (flag != true) {
		cout << "Key number: ";
		getline(cin, c);
		regex e("^-?\\d+");							//Bien e la 1 chi chua gia tri la so nguyen

		if (regex_match(c, e) && c.length() == 8) {		//Neu chuoi C nhap vao MATCH voi bien e va co do dai la 8 kis tu
			flag = true;							//Ket thuc vong lap, lay gia tri do gan vao PersonalKey
		}
		else {
			cout << "Please enter an integer have 8 numbers" << endl;
		}

	}setPersonalKey(c); cout << flush;				//Set PersonalKey va xoa bo nho dem

/*---Input Odo---*/
	cout << "ODO number: ";
	cin >> cd;
	if (isdigit(cd[0])) {
		d = atoi(cd);
	}
	setODO(d);
	/*---Input lich trinh bao duong---*/
	cout << "Remind service (km): ";
	cin >> ce;
	if (isdigit(ce[0])) {
		e = atoi(ce);
	}
	setServiceRemind(e);


}

void Setting::xuatThongTin() {

	cout << "Owner name: " << getCarName() << endl;
	cout << "Email: " << getEmail() << endl;
	cout << "Key number: " << getPersonalKey() << endl;
	cout << "ODO number: " << getODO() << endl;
	cout << "Remind service (km): " << getServiceRemind() << endl;

}
void Setting::print_user_data() {
	cout << "Owner name: " << getCarName() << endl;
	cout << "Email: " << getEmail() << endl;
	cout << "Key number: " << getPersonalKey() << endl;
	cout << "ODO number: " << getODO() << endl;
	cout << "Remind service (km): " << getServiceRemind() << endl;
}



bool Setting::operator > (const Setting& right)
{
	bool status;

	if (m_personal_key > right.m_personal_key)
		status = true;
	else
		status = false;

	return status;
}

bool Setting::operator < (const Setting& right)
{
	bool status;

	if (m_personal_key < right.m_personal_key)
		status = true;
	else
		status = false;

	return status;
}

bool Setting::operator == (const Setting& right)
{
	bool status;

	if (m_personal_key == right.m_personal_key)
		status = true;
	else
		status = false;

	return status;
}

bool operator==(const Setting& lhs, const Setting& rhs) {
	bool status;
	if (lhs.m_car_name == rhs.m_car_name) {
		status = true;
	}
	else
		status = false;
	return status;
}
bool operator<(const Setting& lhs, const Setting& rhs) {
	bool status;
	if (lhs.m_car_name < rhs.m_car_name) {
		status = true;
	}
	else
		status = false;
	return status;
}
bool operator>(const Setting& lhs, const Setting& rhs) {
	bool status;
	if (lhs.m_car_name > rhs.m_car_name) {
		status = true;
	}
	else
		status = false;
	return status;
}