#include "Sound.h"

Sound::Sound() : Setting() {
	m_navi_level = m_media_level = m_call_level = m_notification_level = 0;
}
//Sound::Sound(Setting h, int media, int call, int navi, int noti) : Setting(h)
//{ //Copy constructor for inheritance
//	m_media_level = media;
//	m_call_level = call;
//	m_navi_level = navi;
//	m_notification_level = noti;
//}


Sound::Sound(Setting h)
	:Setting(h)

{
	const int C_DEFAULT_MEDIA_LEVEL = 1;
	const int C_DEFAULT_CALL_LEVEL = 1;
	const int C_DEFAULT_NAVI_LEVEL = 1;
	const int C_DEFAULT_NOTIF_LEVEL = 1;

	m_media_level = C_DEFAULT_MEDIA_LEVEL;
	m_call_level = C_DEFAULT_CALL_LEVEL;
	m_navi_level = C_DEFAULT_NAVI_LEVEL;
	m_notification_level = C_DEFAULT_NOTIF_LEVEL;

}

Sound::Sound(const Sound& h) :Setting(h), m_call_level(h.m_call_level), m_navi_level(h.m_navi_level), m_notification_level(h.m_notification_level), m_media_level(h.m_media_level) {
}
Sound& Sound:: operator =(Sound& m) {
	if (this == &m) return *this;
	Setting(*this) = Setting::operator=(m);
	this->m_call_level = m.m_call_level;
	this->m_navi_level = m.m_navi_level;
	this->m_notification_level = m.m_notification_level;
	this->m_media_level = m.m_media_level;
	return *this;
}
Sound::~Sound() {}
/*---Dung setter de nhap thong tin---*/
void Sound::nhapThongTin() {
	char ca[10], cb[10], cc[10], cd[10];

	int a{}, b{}, c{}, d{};

	cout << "\nMedia volume level: ";
	cin >> ca;
	if (isdigit(ca[0])) {
		a = atoi(ca);
	}
	setMediaLevel(a);
	cout << "Call volume level: ";
	cin >> cb;
	if (isdigit(cb[0])) {
		b = atoi(cb);
	}
	setCallLevel(b);
	cout << "Navigation volume level: ";
	cin >> cc;
	if (isdigit(cc[0])) {
		c = atoi(cc);
	}
	setNaviLevel(c);

	cout << "Notification volume level: ";
	cin >> cd;
	if (isdigit(cd[0])) {
		d = atoi(cd);
	}
	setNotificationLevel(d);
}
/*---Dung getter de xuat thong tin---*/
void Sound::xuatThongTin() {


	cout << "\nMedia volume level: " << getMediaLevel();
	cout << endl;
	cout << "Call volume level: " << getCallLevel(); cout << endl;
	cout << "Navigation volume level: " << getNaviLevel();
	cout << endl;
	cout << "Notification volume level: " << getNotificationLevel(); cout << endl;

}

unique_ptr<Sound> Sound::clone()
{
	return make_unique<Sound>(*this);
}

unique_ptr<Sound> Sound::create()
{
	return make_unique<Sound>();
}



int Sound::getMediaLevel() {
	return m_media_level;
}

int Sound::getCallLevel() {
	return m_call_level;
}

int Sound::getNaviLevel() {
	return m_navi_level;
}

int Sound::getNotificationLevel() {
	return m_notification_level;

}

void Sound::setMediaLevel(int medialv) {
	m_media_level = medialv;
}

void Sound::setCallLevel(int calllv) {
	m_call_level = calllv;
}

void Sound::setNaviLevel(int navilv) {
	m_navi_level = navilv;
}

void Sound::setNotificationLevel(int notilv) {
	m_notification_level = notilv;
}

