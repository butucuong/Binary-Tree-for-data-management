#pragma once
#include <regex>
#include <memory>
#include "Setting.h"
#include "Sound.h"
#include "Display.h"
#include "General.h"
class Car:public Setting
{
private:

		
	Sound m_sound_concrete;
	Display m_display_concrete;
	General m_general_concrete;


public:


	Car();
	Car(Setting h,Sound &snd, Display &dis, General &gen);
	Car(const Car&);
	
	Car& operator=( Car& h);
	void nhapThongTin();
	
	void xuatThongTin();							 //Xuat tat ca thong tin cai dat

	void xuatThongTinDisplay();						
	void xuatThongTinSound();
	void xuatThongTinGeneral();
	void writetofileSetting();
	Sound getSoundConcrete();
	Display getDisplayConcrete();
	General getGeneralConcrete();
	~Car();
};

