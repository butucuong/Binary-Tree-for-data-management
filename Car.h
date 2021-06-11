#pragma once
#include "Setting.h"
#include "Sound.h"
#include "Display.h"
#include "General.h"
class Car:public Setting
{
private:

public:
	Sound l_sound;
	Display l_display;
	General l_general;

	Car();
	Car(Setting h,Sound &snd, Display &dis, General &gen);
	Car(const Car&);

	Car& operator=( Car& h);
	
	
	void xuatThongTin();							 //Xuat tat ca thong tin cai dat
	void xuatThongTinDisplay();						
	void xuatThongTinSound();
	void xuatThongTinGeneral();
	void writetofileSetting();
	~Car();
};

