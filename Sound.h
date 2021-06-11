#pragma once
#include "Setting.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Sound : public Setting {
public:
	Sound();
	Sound(const Sound& h);									//Copy constructor
	Sound(Setting h, int media, int call, int navi, int noti);//Parameter constructor
	Sound& operator =(Sound& m);						//Assignment operator
	~Sound();											//Destructor
	void nhapThongTin();								//Polymorphism method form Setting Class
	void xuatThongTin();								//Polymorphism method form Setting Class
	/*--getter---*/
	int get_media_level();
	int get_call_level();
	int get_navi_level();
	int get_notification_level();
	/*---setter---*/
	void set_media_level(int medialv);
	void set_call_level(int calllv);
	void set_navi_level(int navilv);
	void set_notification_level(int notilv);

private:
	int media_level;
	int call_level;
	int navi_level;
	int notification_level;
};

