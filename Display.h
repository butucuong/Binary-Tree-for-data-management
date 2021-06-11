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

	 ~Display();
	void nhapThongTin();									//Virtual method from Setting class
	void xuatThongTin();									//Virtual method from Setting class
	//Getter
	int get_light_level();
	int get_screen_light_level();
	int get_taplo_light_level();

	//Setter
	void set_light_level(int lightlv);
	void set_screen_light_level(int scrlilv);
	void set_taplo_light_level(int taplilv);
private:
	int light_level;
	int screen_light_level;
	int taplo_light_level;
};

