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
	//Sound(Setting h, int media, int call, int navi, int noti);//Parameter constructor
	Sound(Setting h);
	Sound& operator =(Sound& m);						//Assignment operator
	~Sound();											//Destructor
	void nhapThongTin();								//Polymorphism method form Setting Class
	void xuatThongTin();								//Polymorphism method form Setting Class
	unique_ptr<Sound> clone();
	unique_ptr<Sound> create();
	
	/*--getter---*/
	int getMediaLevel();
	int getCallLevel();
	int getNaviLevel();
	int getNotificationLevel();
	/*---setter---*/
	void setMediaLevel(int medialv);
	void setCallLevel(int calllv);
	void setNaviLevel(int navilv);
	void setNotificationLevel(int notilv);

private:
	int m_media_level;
	int m_call_level;
	int m_navi_level;
	int m_notification_level;
};

