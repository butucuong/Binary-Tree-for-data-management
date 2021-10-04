#include "Car.h"



Car::Car() {}
Car::~Car() {
	m_display_concrete.~Display();
	m_general_concrete.~General();
	m_sound_concrete.~Sound();
}

Car& Car::operator=(Car& m) {						//assign
	if (this == &m) return *this;
	Setting(*this) = Setting::operator=(m);
	this->m_display_concrete = m.m_display_concrete;
	this->m_general_concrete = m.m_general_concrete;
	this->m_sound_concrete = m.m_sound_concrete;
	return *this;
}
Car::Car(const Car& h):Setting(h) {									//copy
	Display dis(h.m_display_concrete);
	Sound snd(h.m_sound_concrete);
	General gen(h.m_general_concrete);

	this->m_display_concrete =*dis.clone();
	this->m_general_concrete = *gen.clone();
	this->m_sound_concrete = *snd.clone();
}

Car::Car(Setting h, Sound &snd, Display &dis, General &gen): Setting(h) {

	this->m_sound_concrete = snd;
	this->m_display_concrete = dis;
	this->m_general_concrete = gen;

}

void Car::nhapThongTin() {
	Setting m_set_info;
	m_set_info.nhapThongTin();
	Sound sound_obj(m_set_info);
	Display display_obj(m_set_info);
	General general_obj(m_set_info);
	
	m_car_name = m_set_info.getCarName();
	m_email = m_set_info.getEmail();
	m_personal_key = m_set_info.getPersonalKey();
	m_odo = m_set_info.getODO();
	m_service_remind = m_set_info.getServiceRemind();

	this->m_display_concrete = *display_obj.clone();
	this->m_general_concrete = *general_obj.clone(); 
	this->m_sound_concrete = *sound_obj.clone();


}
void Car::xuatThongTin() {
	cout << endl;
	cout << setw(5) << " " << setw(20) << left << "Owner name" << setw(25) << left << "Email" << setw(20) << left << "Key number" << setw(20) << left << "ODO number" << setw(20) << left << "Remind service (km)" << endl;
	cout << setw(5) << " " << setw(20) << left << m_display_concrete.getCarName() << setw(25) << left << m_display_concrete.getEmail() << setw(20) << left << m_display_concrete.getPersonalKey() << setw(20) << left << m_display_concrete.getODO() << setw(20) << left << m_display_concrete.getServiceRemind() << endl;

	//------------------------------------------------------------------------

	cout << setw(5) << " " << setw(20) << left << "Display: " << setw(15) << left << "Light" << setw(15) << left << "Screen Light" << setw(15) << left << "Taplo Light" << endl;
	cout << setw(5) << " " << setw(20) << left << " " << setw(15) << left << m_display_concrete.getLightLevel() << setw(15) << left << m_display_concrete.getScreenLightLevel() << setw(15) << left << m_display_concrete.getTaploLightLevel() << endl;

	//------------------------------------------------------------------------

	cout << setw(5) << " " << setw(20) << left << "Sound: " << setw(15) << left << "Media" << setw(15) << left << "Call" << setw(15) << left << "Navigation" << setw(15) << left << "Notification" << endl;
	cout << setw(5) << " " << setw(20) << left << " " << setw(15) << left << m_sound_concrete.getMediaLevel() << setw(15) << left << m_sound_concrete.getCallLevel() << setw(15) << left << m_sound_concrete.getNaviLevel() << setw(15) << left << m_sound_concrete.getNotificationLevel() << endl;

	//------------------------------------------------------------------------

	cout << setw(5) << " " << setw(20) << left << "General: " << setw(15) << left << "Timezone" << setw(15) << left << "Language" << endl;
	cout << setw(5) << " " << setw(20) << left << "  " << setw(15) << left << m_general_concrete.getTimezone() << setw(15) << left << m_general_concrete.getLanguage() << endl << endl;

	cout<<setfill('-') << setw(110)<<"-" <<endl;
	cout << setfill(' ');
}

void Car::xuatThongTinDisplay() {
	cout << setw(20) << left << m_display_concrete.getCarName() << setw(25) << left << m_display_concrete.getEmail() << setw(20) << left << m_display_concrete.getPersonalKey() << setw(20) << left << m_display_concrete.getODO() << setw(20) << left << m_display_concrete.getServiceRemind() << setw(20) << left << m_display_concrete.getLightLevel() << setw(20) << left << m_display_concrete.getTaploLightLevel() << setw(20) << left << m_display_concrete.getScreenLightLevel() << endl;
}
void Car::xuatThongTinSound(){
	cout << setw(20) << left << m_sound_concrete.getCarName() << setw(25) << left << m_sound_concrete.getEmail() << setw(20) << left << m_sound_concrete.getPersonalKey() << setw(20) << left << m_sound_concrete.getODO() << setw(20) << left << m_sound_concrete.getServiceRemind() << setw(20) << left << m_sound_concrete.getMediaLevel() << setw(20) << left << m_sound_concrete.getCallLevel() << setw(20) << left << m_sound_concrete.getNaviLevel() << setw(20) << left << m_sound_concrete.getNotificationLevel() << endl;
}

void Car::xuatThongTinGeneral() {
cout << setw(20) << left << m_general_concrete.getCarName() << setw(25) << left << m_general_concrete.getEmail() << setw(20) << left << m_general_concrete.getPersonalKey() << setw(20) << left << m_general_concrete.getODO() << setw(20) << left << m_general_concrete.getServiceRemind() << setw(15) << left << m_general_concrete.getTimezone() << setw(30) << left << m_general_concrete.getLanguage() << endl;
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
			
				f << setw(10) << left << "Common:" << setw(20) << getCarName() << "/" << setw(25) << getEmail() << "/" << setw(8) << getPersonalKey() << "/" << setw(7) << getODO() << "/" << setw(7) << getServiceRemind() << " " << setw(10) << left << "Sound:" << setw(2) << m_sound_concrete.getMediaLevel() << "/" << setw(2) << m_sound_concrete.getCallLevel() << "/" << setw(2) << m_sound_concrete.getNaviLevel() << "/" << setw(2) << m_sound_concrete.getNotificationLevel() << " " << setw(10) << left << "Display:" << setw(2) << m_display_concrete.getLightLevel() << "/" << setw(2) << m_display_concrete.getScreenLightLevel() << "/" << setw(2) << m_display_concrete.getTaploLightLevel() << " " << setw(10) << left << "General: " << setw(11) << m_general_concrete.getTimezone() << "/" << setw(20) << m_general_concrete.getLanguage() << endl;
		
		}
		catch (...) {
			cerr << "Can't read the Setting.txt file.";
			return;
		}
	}
	f.close();

}

Sound Car::getSoundConcrete()
{
	return m_sound_concrete;

}

Display Car::getDisplayConcrete()
{
	return m_display_concrete;
}

General Car::getGeneralConcrete()
{
	return m_general_concrete;
}
