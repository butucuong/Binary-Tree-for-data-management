#include "Sound.h"

Sound::Sound() : Setting() {
	navi_level = media_level = call_level = notification_level = 0;
}
Sound::Sound(Setting h, int media, int call, int navi, int noti) : Setting(h)
{ //Copy constructor for inheritance
	media_level = media;
	call_level = call;
	navi_level = navi;
	notification_level = noti;
}

Sound::Sound(const Sound& h) :Setting(h) {
	this->call_level = h.call_level;
	this->navi_level = h.navi_level;
	this->notification_level = h.notification_level;
	this->media_level = h.media_level;

}
Sound& Sound:: operator =(Sound& m) {
	if (this == &m) return *this;
	Setting(*this) = Setting::operator=(m);
	this->call_level = m.call_level;
	this->navi_level = m.navi_level;
	this->notification_level = m.notification_level;
	this->media_level = m.media_level;

};
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
	set_media_level(a);
	cout << "Call volume level: ";
	cin >> cb;
	if (isdigit(cb[0])) {
		b = atoi(cb);
	}
	set_call_level(b);
	cout << "Navigation volume level: ";
	cin >> cc;
	if (isdigit(cc[0])) {
		c = atoi(cc);
	}
	set_navi_level(c);

	cout << "Notification volume level: ";
	cin >> cd;
	if (isdigit(cd[0])) {
		d = atoi(cd);
	}
	set_notification_level(d);
}
/*---Dung getter de xuat thong tin---*/
void Sound::xuatThongTin() {


	cout << "\nMedia volume level: " << get_media_level();
	cout << endl;
	cout << "Call volume level: " << get_call_level(); cout << endl;
	cout << "Navigation volume level: " << get_navi_level();
	cout << endl;
	cout << "Notification volume level: " << get_notification_level(); cout << endl;

}

int Sound::get_media_level() {
	return media_level;
}

int Sound::get_call_level() {
	return call_level;
}

int Sound::get_navi_level() {
	return navi_level;
}

int Sound::get_notification_level() {
	return notification_level;

}

void Sound::set_media_level(int medialv) {
	media_level = medialv;
}

void Sound::set_call_level(int calllv) {
	call_level = calllv;
}

void Sound::set_navi_level(int navilv) {
	navi_level = navilv;
}

void Sound::set_notification_level(int notilv) {
	notification_level = notilv;
}

