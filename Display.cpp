#include "Display.h"

Display::Display() : Setting()
{
	m_light_level = m_screen_light_level = m_taplo_light_level = 0;
}
//Display::Display(Setting h, int n1, int n2, int n3) : Setting(h)	//Copy constructor for inheritance
//{
//	m_light_level = n1;
//	m_screen_light_level = n2;
//	m_taplo_light_level = n3;
//}

Display::Display(Setting h)
	:Setting(h)
{
	const int C_DEFAULT_LIGHT_LEVEL = 1;
	const int C_DEFAULT_SCREEN_LIGHT_LEVEL = 1;
	const int C_DEFAULT_TAPLO_LIGHT_LEVEL = 1;
	m_light_level = C_DEFAULT_LIGHT_LEVEL;
	m_screen_light_level = C_DEFAULT_SCREEN_LIGHT_LEVEL;
	m_taplo_light_level = C_DEFAULT_TAPLO_LIGHT_LEVEL;

}

Display::Display(const Display& h) :Setting(h), m_light_level(h.m_light_level), m_screen_light_level(h.m_screen_light_level), m_taplo_light_level(h.m_taplo_light_level)
{
	//Copy method
}
Display& Display:: operator =(Display& m) {						//Assign operator
	if (this == &m) return *this;
	Setting(*this) = Setting::operator=(m);
	this->m_light_level = m.m_light_level;
	this->m_screen_light_level = m.m_screen_light_level;
	this->m_taplo_light_level = m.m_taplo_light_level;
	return *this;
}
Display::~Display() {
}

int Display::getLightLevel() {
	return m_light_level;
}

int Display::getScreenLightLevel() {
	return	m_screen_light_level;
}

int Display::getTaploLightLevel() {
	return m_taplo_light_level;
}

unique_ptr<Display> Display::clone()
{
	return make_unique<Display>(*this);
}

unique_ptr<Display> Display::create()
{
	return make_unique<Display>();
}

void Display::setLightLevel(int lightlv) {
	m_light_level = lightlv;
}

void Display::setScreenLightLevel(int scrlilv) {
	m_screen_light_level = scrlilv;
}

void Display::setTaploLightLevel(int taplilv) {
	m_taplo_light_level = taplilv;
}

void Display::nhapThongTin() {							//Nhap thong tin tu ban phim bang setter
	char ca[5], cb[5], cc[5];

	int a{}, b{}, c{};
	cout << endl;
	cout << "\nLigth level: ";
	cin >> ca;
	if (isdigit(ca[0])) {
		a = atoi(ca);
	}

	setLightLevel(a);
	cout << "Screen light level: ";
	cin >> cb;
	if (isdigit(cb[0])) {
		b = atoi(cb);
	}
	setScreenLightLevel(b);
	cout << "Taplo light level: ";
	cin >> cc;
	if (isdigit(cc[0])) {
		c = atoi(cc);
	}
	setTaploLightLevel(c);
}
void Display::xuatThongTin() {							//Xuat thong tin bang Getter

	cout << endl;
	cout << "Ligth level: " << getLightLevel();
	cout << "\nScreen light level: " << getScreenLightLevel();
	cout << "\nTaplo light level: " << getTaploLightLevel();
}

