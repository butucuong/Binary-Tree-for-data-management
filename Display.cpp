#include "Display.h"

Display::Display() : Setting()
{
	light_level = screen_light_level = taplo_light_level = 0;
}
Display::Display(Setting h, int n1, int n2, int n3) : Setting(h)	//Copy constructor for inheritance
{
	light_level = n1;
	screen_light_level = n2;
	taplo_light_level = n3;
}

Display::Display(const Display& h) :Setting(h) {						//Copy method
	this->light_level = h.light_level;
	this->screen_light_level = h.screen_light_level;
	this->taplo_light_level = h.taplo_light_level;
}
Display& Display:: operator =(Display& m) {						//Assign operator
	if (this == &m) return *this;
	Setting(*this) = Setting::operator=(m);
	this->light_level = m.light_level;
	this->screen_light_level = m.screen_light_level;
	this->taplo_light_level = m.taplo_light_level;
}
Display::~Display() {
}

int Display::get_light_level() {
	return light_level;
}

int Display::get_screen_light_level() {
	return	screen_light_level;
}

int Display::get_taplo_light_level() {
	return taplo_light_level;
}

void Display::set_light_level(int lightlv) {
	light_level = lightlv;
}

void Display::set_screen_light_level(int scrlilv) {
	screen_light_level = scrlilv;
}

void Display::set_taplo_light_level(int taplilv) {
	taplo_light_level = taplilv;
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

	set_light_level(a);
	cout << "Screen light level: ";
	cin >> cb;
	if (isdigit(cb[0])) {
		b = atoi(cb);
	}
	set_screen_light_level(b);
	cout << "Taplo light level: ";
	cin >> cc;
	if (isdigit(cc[0])) {
		c = atoi(cc);
	}
	set_taplo_light_level(c);
}
void Display::xuatThongTin() {							//Xuat thong tin bang Getter

	cout << endl;
	cout << "Ligth level: " << get_light_level();
	cout << "\nScreen light level: " << get_screen_light_level();
	cout << "\nTaplo light level: " << get_taplo_light_level();
}

