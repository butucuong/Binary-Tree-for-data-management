#pragma once
#include "Setting.h"
#include <iostream>
#include <string>
using namespace std;

class Display : public Setting{

public:
	Display();
	Display(const Display& h);									//Copy constructor
	Display& operator =(Display& m);						//Assignment operator
	
	Display(Setting h, int n1, int n2, int n3);				//Parametar constructor
	Display(Setting h);

	 ~Display();
	void nhapThongTin();									//Virtual method from Setting class
	void xuatThongTin();									//Virtual method from Setting class
	//Getter
	int getLightLevel();
	int getScreenLightLevel();
	int getTaploLightLevel();

	//Setter
	void setLightLevel(int lightlv);
	void setScreenLightLevel(int scrlilv);
	void setTaploLightLevel(int taplilv);
private:
	int m_light_level;
	int m_screen_light_level;
	int m_taplo_light_level;
};

