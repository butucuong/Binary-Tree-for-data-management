#include "Car.h"



Car::Car() {}
Car::~Car() {
	l_display.~Display();
	l_general.~General();
	l_sound.~Sound();
}

Car& Car::operator=(Car& m) {						//assign
	if (this == &m) return *this;
	Setting(*this) = Setting::operator=(m);
	this->l_display = m.l_display;
	this->l_general = m.l_general;
	this->l_sound = m.l_sound;
}
Car::Car(const Car& h):Setting(h) {									//copy
	Display dis(h.l_display);
	Sound snd(h.l_sound);
	General gen(h.l_general);

	this->l_display =dis;
	this->l_general = gen;
	this->l_sound = snd;
}
Car::Car(Setting h, Sound &snd, Display &dis, General &gen): Setting(h) {

	l_sound = snd;
	l_display = dis;
	l_general = gen;

}
void Car::xuatThongTin() {
	cout << endl;
	cout << setw(5) << " " << setw(20) << left << "Owner name" << setw(25) << left << "Email" << setw(20) << left << "Key number" << setw(20) << left << "ODO number" << setw(20) << left << "Remind service (km)" << endl;
	cout << setw(5) << " " << setw(20) << left << l_display.getCarName() << setw(25) << left << l_display.getEmail() << setw(20) << left << l_display.getPersonalKey() << setw(20) << left << l_display.getODO() << setw(20) << left << l_display.getServiceRemind() << endl;

	//------------------------------------------------------------------------

	cout << setw(5) << " " << setw(20) << left << "Display: " << setw(15) << left << "Light" << setw(15) << left << "Screen Light" << setw(15) << left << "Taplo Light" << endl;
	cout << setw(5) << " " << setw(20) << left << " " << setw(15) << left << l_display.get_light_level() << setw(15) << left << l_display.get_screen_light_level() << setw(15) << left << l_display.get_taplo_light_level() << endl;

	//------------------------------------------------------------------------

	cout << setw(5) << " " << setw(20) << left << "Sound: " << setw(15) << left << "Media" << setw(15) << left << "Call" << setw(15) << left << "Navigation" << setw(15) << left << "Notification" << endl;
	cout << setw(5) << " " << setw(20) << left << " " << setw(15) << left << l_sound.get_media_level() << setw(15) << left << l_sound.get_call_level() << setw(15) << left << l_sound.get_navi_level() << setw(15) << left << l_sound.get_notification_level() << endl;

	//------------------------------------------------------------------------

	cout << setw(5) << " " << setw(20) << left << "General: " << setw(15) << left << "Timezone" << setw(15) << left << "Language" << endl;
	cout << setw(5) << " " << setw(20) << left << "  " << setw(15) << left << l_general.get_timeZone() << setw(15) << left << l_general.get_language() << endl << endl;

	cout<<setfill('-') << setw(110)<<"-" <<endl;
	cout << setfill(' ');
}

void Car::xuatThongTinDisplay() {
	cout << setw(20) << left << l_display.getCarName() << setw(25) << left << l_display.getEmail() << setw(20) << left << l_display.getPersonalKey() << setw(20) << left << l_display.getODO() << setw(20) << left << l_display.getServiceRemind() << setw(20) << left << l_display.get_light_level() << setw(20) << left << l_display.get_taplo_light_level() << setw(20) << left << l_display.get_screen_light_level() << endl;
}
void Car::xuatThongTinSound(){
	cout << setw(20) << left << l_sound.getCarName() << setw(25) << left << l_sound.getEmail() << setw(20) << left << l_sound.getPersonalKey() << setw(20) << left << l_sound.getODO() << setw(20) << left << l_sound.getServiceRemind() << setw(20) << left << l_sound.get_media_level() << setw(20) << left << l_sound.get_call_level() << setw(20) << left << l_sound.get_navi_level() << setw(20) << left << l_sound.get_notification_level() << endl;
}

void Car::xuatThongTinGeneral() {
cout << setw(20) << left << l_general.getCarName() << setw(25) << left << l_general.getEmail() << setw(20) << left << l_general.getPersonalKey() << setw(20) << left << l_general.getODO() << setw(20) << left << l_general.getServiceRemind() << setw(15) << left << l_general.get_timeZone() << setw(30) << left << l_general.get_language() << endl;
}

void Car::writetofileSetting(){
	ofstream f;
	f.open("Setting.txt", ios_base::out | ios_base::app);
	if (f.fail()) {
		cerr << "Can't open the Setting.txt file to read!";
		return;
	}
	else {
		try {
			
				f << setw(10) << left << "Common:" << setw(20) << getCarName() << "/" << setw(25) << getEmail() << "/" << setw(8) << getPersonalKey() << "/" << setw(7) << getODO() << "/" << setw(7) << getServiceRemind() << " " << setw(10) << left << "Sound:" << setw(2) << l_sound.get_media_level() << "/" << setw(2) << l_sound.get_call_level() << "/" << setw(2) << l_sound.get_navi_level() << "/" << setw(2) << l_sound.get_notification_level() << " " << setw(10) << left << "Display:" << setw(2) << l_display.get_light_level() << "/" << setw(2) << l_display.get_screen_light_level() << "/" << setw(2) << l_display.get_taplo_light_level() << " " << setw(10) << left << "General: " << setw(11) << l_general.get_timeZone() << "/" << setw(20) << l_general.get_language() << endl;
		
		}
		catch (...) {
			cerr << "Can't read the Setting.txt file.";
			return;
		}
	}
	f.close();

}