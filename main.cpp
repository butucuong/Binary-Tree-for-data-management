#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <algorithm>
#include <utility>
#include <regex>
#include <numeric>

#include "General.h"
#include "Display.h"
#include "Sound.h"
#include "CommonInfo.h"
#include "list.h"
#include "Setting.h"

using namespace std;

//Vector de luu tru tam thoi du lieu , thuan tien trong viec nhap du lieu


List Vehicle;


vector<CommonInfo> g_timezone_list;
vector<CommonInfo> g_language_list;
const char G_NO_SORT = '0';
const char G_SORT_BY_ID = '1';
const char G_SORT_BY_NAME = '2';
void nhapThongTinCaiDat();
void xuatThongTinCaiDat();

void xuatThongTinCaiDat_Sound();
void choosePrintForm(const string);
void xuatThongTinCaiDat_General();
void xuatThongTinCaiDat_Display();
void xuatTatCaThongTinCaiDat();

void nhapThongTinCaiDat_Sound();
void nhapThongTinCaiDat_General();
void nhapThongTinCaiDat_Display();

void downloadTimeZone();
void downloadLanguage();

void readFromFileSetting();
void writeToFileSetting();

void menu();

void insertAnotherUser();

void sortTimezone();									//Sap xep Timezone
void sortLanguage();									//Sap xep Language
void sortVector(vector<CommonInfo>& v, int choose);
bool cmpByNum(CommonInfo obj1, CommonInfo obj2);
bool cmpByAlphabet(CommonInfo obj1, CommonInfo obj2);



/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	downloadLanguage();
	downloadTimeZone();


	char decision = 'c';								//Tiep tuc nha du lieu cho xe tiep theo hay khong
	bool flag_while{ false };									//Flag cho while

	readFromFileSetting();


	while (flag_while != true) {
		decision = 'c';

		cout << "There is (are) " << Vehicle.size() << " car(s) in the system." << endl;
		cout << "Will you import another user? (y/n) :";//Goi y chon tao doi tuong moi
		cin >> decision;
		if (toupper(decision) == 'Y') {

			cin.ignore(1);
			system("cls");

			cout << "Car number: " << Vehicle.size() + 1 << endl;

			insertAnotherUser();						//Doi tuong mac dinh moi  duoc tao ra

		}
		else {
			if (toupper(decision) == 'N') {
				cin.clear();
				cin.ignore(100, '\n');
				menu();

				flag_while = true;
			}
			else {
				cout << "Unknown selection." << endl;
				cin.clear();
				cin.ignore(100, '\n');

				continue;

			}
		}
	}



	return 0;
}

void insertAnotherUser()
{
	Setting data;

	data.nhapThongTin();

	Display DIS(data);					//Tao doi tuong cua lop Display ke thua du lieu tu lop Setting
	Sound SND(data);				//Tao doi tuong cua lop Sound ke thua du lieu tu lop Setting
	General GEN(data);					//Tao doi tuong cua lop General ke thua du lieu tu lop Setting
	Car newcar(data, SND, DIS, GEN);
	Vehicle.insertNode(newcar);
}

void menu() {
	char menu_selection('c');
	char add_user_decision('c');
	bool flag_menu{ false }, flag_add_user{ false };		//Flag ket thuc vong lap while
	Vehicle.updateTreeAVL();
	while (flag_menu != true) {
		system("cls");
		cout << "--- SELECT MENU ---\n";
		cout << "1. Input setting information" << endl;		//Thong tin nhap vao duoc luu tru tam trong vetor
		cout << "2. Print setting information" << endl;		//Khi chon xuat thong tin thi thong tin se duoc cap nhat vao binary tree
		cout << "3. Add another vehicle\n";
		cout << "4. Exit\nYour seclection: ";

		cin >> menu_selection;
		try {
			switch (menu_selection) {						//Switch-case nhu menu
			case '1':
				nhapThongTinCaiDat();
				cin.clear();
				cin.ignore(100, '\n');
				break;
			case '2':
				xuatThongTinCaiDat();
				cin.clear();
				cin.ignore(100, '\n');
				break;
			case '4':

				cout << "\nGood bye.";
				cout << endl;
				system("pause");
				flag_menu = true;
				break;
			case '3':
				while (flag_add_user != true) {
					add_user_decision = 'c';

					cout << "There is (are) " << Vehicle.size() << " car(s) in the system." << endl;
					cout << "Will you import another user? (y/n) :";//Goi y chon tao doi tuong moi
					cin >> add_user_decision;
					if (toupper(add_user_decision) == 'Y') {

						cin.ignore(1);
						system("cls");

						cout << "Car number: " << Vehicle.size() + 1 << endl;

						insertAnotherUser();


					}
					else {
						if (toupper(add_user_decision) == 'N') {
							cin.clear();
							cin.ignore(100, '\n');
							menu();

							flag_add_user = true;
						}
						else {
							cout << "Unknown selection." << endl;
							cin.clear();
							cin.ignore(100, '\n');

							continue;

						}
					}
				}

				break;
			default:
				cout << "Unknown selection. Please try again!!!" << endl;
				cin.clear();
				cin.ignore(100, '\n');
				system("pause");
			}
		}
		catch (...) {
			cerr << "Unknown selection!!! Please try again.";
			continue;
		}
	}
}

void nhapThongTinCaiDat() {
	char information_selection;			//Chon xe de cai dat thong tin Display/Sound/General
	bool menu_flag{ false };			//Flag cho while 


	while (menu_flag != true) {
		system("cls");
		cout << "--- SELECT MENU ---" << endl;
		cout << "1. Display setting " << endl;
		cout << "2. Sound setting " << endl;
		cout << "3. General setting" << endl;
		cout << "0. Back\nYour selection: ";
		cin >> information_selection;

		try {
			switch (information_selection) {
			case '1':																//Nhap thong tin cho Display
				system("cls");
				cin.clear();
				cin.ignore(100, '\n');
				cout << " --- Ban nhap thong tin Display --- " << endl;			//Xuat thong bao da chon Input Display

				nhapThongTinCaiDat_Display();							//Ham Input Display


				break;

			case '2':
				system("cls");
				cin.clear();
				cin.ignore(100, '\n');
				cout << " --- Ban nhap thong tin Sound --- " << endl;			//Xuat thong bao da chon Input Sound

				nhapThongTinCaiDat_Sound();								//Ham Input Sound

				break;

			case '3':
				cin.clear();
				cin.ignore(100, '\n');
				system("cls");
				cout << " --- Ban nhap thong tin General --- " << endl;
				nhapThongTinCaiDat_General();

				break;
			case '0':
				system("cls");

				menu_flag = true;
				break;

			default:
				cout << "Unknown selection. Please try again!!!" << endl;
				cin.clear();
				cin.ignore(100, '\n');
				system("pause");
				continue;
			}
		}
		catch (...) {
			cerr << "Unknown selection. Please try again!!";
			system("pause");
			continue;
		}
	}
}

void nhapThongTinCaiDat_Sound()
{
	Vehicle.nhapThongTinSound();
	system("pause");

}

void nhapThongTinCaiDat_General() {


	sortLanguage();
	sortTimezone();
	Vehicle.nhapThongTinGeneral();
	system("pause");
}
void nhapThongTinCaiDat_Display()
{

	Vehicle.nhapThongTinDisplay();


	system("pause");

}

void xuatThongTinCaiDat() {
	char print_info_selection = 'c';						//Chon che do xuat

	bool flag{ false };
	while (flag != true) {
		system("cls");
		cout << "--- SELECT MENU ---\n";
		cout << "1. Print Display setting information\n";
		cout << "2. Print Sound setting information\n";
		cout << "3. Print General setting information\n";
		cout << "4. Print all setting information\n";
		cout << "0. Back\nYour selection: ";
		cin >> print_info_selection;
		writeToFileSetting();
		system("cls");
		Vehicle.updateTreeAVL();
		switch (print_info_selection) {
		case '1':
			cout << "--- Display setting ---\n";
			cin.clear();
			cin.ignore(100, '\n');
			xuatThongTinCaiDat_Display();					//Ham xuat thong tin cai dat Display
			break;
		case '2':
			cout << "--- Sound setting ---\n";
			cin.clear();
			cin.ignore(100, '\n');
			xuatThongTinCaiDat_Sound();						//Ham xuat thong tin cai dat Sound
			break;
		case '3':
			cout << "--- General setting ---\n";
			cin.clear();
			cin.ignore(100, '\n');
			xuatThongTinCaiDat_General();					//Ham xuat thong tin cai dat General
			break;
		case '4':
			cout << "--- All setting ---\n";					//Ham xuat thong tin tat cacai dat 
			cin.clear();
			cin.ignore(100, '\n');
			xuatTatCaThongTinCaiDat();
			break;
		case '0':													//Ket thuc Ham Xuat Thong Tin Cai Dat
			system("cls");
			cin.clear();
			cin.ignore(100, '\n');
			flag = true;
			break;
		default:
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Illegal choice, please input again!!\n";
			system("pause");
		}
	}


}


void xuatThongTinCaiDat_Sound() {
	const string kind_info = "Sound";
	choosePrintForm(kind_info);
	cout << endl;
	cout << setw(20) << left << "Owner name" << setw(25) << left << "Email" << setw(20) << left << "Key number" << setw(20) << left << "ODO number" << setw(20) << left << "Remind service" << setw(20) << left << "Media" << setw(20) << left << "Call" << setw(20) << left << "Navigation" << setw(20) << left << "Notification" << endl;							//Format String
	Vehicle.xuatThongTinSound();
	system("pause");
}

void choosePrintForm(const string kind_info)
{
	char form_choice{};
	bool choose_form_flag{ false };

	while (choose_form_flag != true) {
		system("cls");
		cout << "Sorting "<<kind_info <<" data by :\n1. Personal Key\n2. Car Name\n";
		cout << "Your choice: ";
		cin >> form_choice;

		if (form_choice == G_SORT_BY_ID) {
			Vehicle.BSTByID();
			cin.clear();
			cin.ignore(100, '\n');
			choose_form_flag = true;
		}
		else if (form_choice == G_SORT_BY_NAME) {
			Vehicle.BSTByName();
			cin.clear();
			cin.ignore(100, '\n');
			choose_form_flag = true;
		}
		else {
			cout << "Illegal choice, please try again.\n";
			cin.clear();
			cin.ignore(100, '\n');
			system("pause");
			continue;

		}
	}
}


void xuatThongTinCaiDat_General() {
	const string kind_info = "General";
	choosePrintForm(kind_info);
	cout << endl;
	cout << setw(20) << left << "Owner name" << setw(25) << left << "Email" << setw(20) << left << "Key number" << setw(20) << left << "ODO number" << setw(20) << left << "Remind service" << setw(15) << left << "TimeZone" << setw(30) << left << "Language" << endl;
	Vehicle.xuatThongTinGeneral();
	system("pause");
}

void xuatThongTinCaiDat_Display() {
	const string kind_info = "Display";
	choosePrintForm(kind_info);
	cout << endl;
	cout << setw(20) << left << "Owner name" << setw(25) << left << "Email" << setw(20) << left << "Key number" << setw(20) << left << "ODO number" << setw(20) << left << "Remind service" << setw(20) << left << "Light level" << setw(20) << left << "Taplo light level" << setw(20) << left << "Screen light level" << endl;

	Vehicle.xuatThongTinDisplay();
	system("pause");
}

void xuatTatCaThongTinCaiDat() {
	char update_confirm = 'c';
	string user_id;
	bool update_user_flag{ false };
	
	cout << endl << endl;
	const string kind_info = "All";
	choosePrintForm(kind_info);
	writeToFileSetting();
	cout << endl;
	Vehicle.xuatThongTinTatCa();
	
	//Sau khi xuat tat ca thong tin tren he thong, hoi nguoi dung co muon update mot user nao do khong

	while (update_user_flag != true) {
		update_user_flag = false;
		cout << "\nWould you like to update user data? [yes/no]" << endl;

		cin >> update_confirm;
		if (toupper(update_confirm) == 'Y') {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Which car (input Key Number): ";
			cin >> user_id;
			if (Vehicle.searchNodeByID(user_id)) {
				Vehicle.updateData(user_id);
			}
			else {
				cout << "\nIllegal choice. Could you try again?";
				cin.clear();
				cin.ignore(100, '\n');
			}
		}
		if (toupper(update_confirm) == 'N') {
			cin.clear();
			cin.ignore(100, '\n');
			update_user_flag = true;
		}
		else {
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	system("pause");
}

void downloadTimeZone() {
	ifstream ifs_timezone;									//Doi tuong cua ifstream de mo file	
	CommonInfo timezone_objs[32];											//Mang  doi tuong
	ifs_timezone.open("timezones.txt");									//Lenh mo file
	if (!ifs_timezone) {													//Neu mo khong thanh cong
		cerr << "Can't open timezones.txt file!" << endl;
		return;
	}
	else {
		try {													//Exception Handle neu khong doc thanh cong file
			for (int i = 0; i < 32; i++) {						//Neu doc duoc 
				cout << flush;									//Vi input la string nen xoa bo nho dem
				timezone_objs[i].doc(ifs_timezone);									//Ham Friend doc duoc dinh nghia trong Class CommonInfo
				g_timezone_list.push_back(timezone_objs[i]);					//Them vao vector

			}
			cout << "The TimeZoneList download process is successfull.\n";
		}
		catch (...) {
			cerr << "Can't read this file !" << endl;

			return;
		}
	}
	ifs_timezone.close();
}


void downloadLanguage() {
	ifstream ifs_language;													//Doi tuong cua ifstream de mo file	
	CommonInfo language_objs[30];										//Mang  doi tuong
	ifs_language.open("languages.txt");									//Lenh mo file
	if (ifs_language.fail()) {												//Neu mo khong thanh cong
		cerr << "Can't open the languages.txt file!";
		return;

	}
	else {
		try {													//Exception Handle neu khong doc thanh cong file
			for (int i = 0; i < 30; i++) {						//Neu doc duoc 
				cout << flush;									//Vi input la string nen xoa bo nho dem
				language_objs[i].doc(ifs_language);
				g_language_list.push_back(language_objs[i]);				//Them vao vector
			}
			cout << "The LanguageList download process is successfull.\n";
		}
		catch (...) {
			cerr << "Can't read the language.txt file!";
			return;
		}
	}
	ifs_language.close();
}

void readFromFileSetting() {
	ifstream ifs_setting;
	string begin_word;
	string string_word, parameter_in_string;
	int parameter{};
	ifs_setting.open("Setting.txt", ios::in);
	if (ifs_setting.fail()) {
		cerr << "Can't open the Setting.txt file to read!";
		return;
	}
	else {
		try {

			ifs_setting.seekg(0, ios::end);
			size_t size = ifs_setting.tellg();
			if (size == 0) {
				cout << "Ready to write on file.";
				system("cls");
				cout << "Car number: " << 1 << endl;
				insertAnotherUser();	
			}
			else {
				ifs_setting.seekg(0);
				while (!ifs_setting.eof()) {
					Setting data;

					ifs_setting >> begin_word;
					ifs_setting.seekg(3, 1);
					getline(ifs_setting, string_word, '/');
					data.setCarName(string_word);

					getline(ifs_setting, string_word, '/');
					data.setEmail(string_word);

					getline(ifs_setting, string_word, '/');
					data.setPersonalKey(string_word);

					getline(ifs_setting, parameter_in_string, '/');
					parameter = stoi(parameter_in_string);
					data.setODO(parameter);

					getline(ifs_setting, parameter_in_string, 'S');
					parameter = stoi(parameter_in_string);

					data.setServiceRemind(parameter);


					getline(ifs_setting, begin_word, ':');
					ifs_setting.seekg(4, 1);

					Sound SND(data, 0, 0, 0, 0);

					getline(ifs_setting, parameter_in_string, '/');
					parameter = stoi(parameter_in_string);
					SND.setMediaLevel(parameter);

					getline(ifs_setting, parameter_in_string, '/');
					parameter = stoi(parameter_in_string);
					SND.setCallLevel(parameter);

					getline(ifs_setting, parameter_in_string, '/');
					parameter = stoi(parameter_in_string);
					SND.setNaviLevel(parameter);

					getline(ifs_setting, parameter_in_string, 'D');
					parameter = stoi(parameter_in_string);
					SND.setNotificationLevel(parameter);

					Display DIS(data, 0, 0, 0);

					getline(ifs_setting, begin_word, ':');
					ifs_setting.seekg(2, 1);

					getline(ifs_setting, parameter_in_string, '/');
					parameter = stoi(parameter_in_string);
					DIS.setLightLevel(parameter);

					getline(ifs_setting, parameter_in_string, '/');
					parameter = stoi(parameter_in_string);
					DIS.setScreenLightLevel(parameter);

					getline(ifs_setting, parameter_in_string, 'G');
					parameter = stoi(parameter_in_string);
					DIS.setTaploLightLevel(parameter);


					General GEN(data, "", "");



					getline(ifs_setting, begin_word, ':');
					ifs_setting.seekg(2, 1);
					getline(ifs_setting, string_word, '/');
					GEN.setTimezone(string_word);

					getline(ifs_setting, string_word);
					GEN.setLanguage(string_word);
					ifs_setting.ignore(1);
					Car newCar(data, SND, DIS, GEN);
					Vehicle.insertNode(newCar);							//Them cac doi tuong vao binary tree them vao DATA_b de kiem tra

				}

			}
			return;
		}
		catch (...) {
			cerr << "Can't read the Setting.txt file.";
			system("pause");
			return;
		}
	}
	ifs_setting.close();
}
void writeToFileSetting() {			
	Vehicle.writetofileSetting();

}
void sortTimezone() {
	const int C_SORT_BY_INDEX = 1;
	const int C_SORT_BY_NAME = 2;
	
	char sort_form_choice('c');
	bool sort_decision_flag = false;
	cout << "\nSorting Timezone list by:";
	cout << "\n1. Index\n2. Alphabet\n0. Leave it alone.\n";

	while (sort_decision_flag != true) {
		sort_decision_flag = false;
		cout << "Your choice: ";
		cin >> sort_form_choice;
		switch (sort_form_choice) {
		case G_NO_SORT:
			cout << "\nNo change in your list.\n";
			sort_decision_flag = true;
			break;
		case G_SORT_BY_ID:
			cout << "\nTimezone list was sorted by GMT Index.\n";
			sortVector(g_timezone_list, C_SORT_BY_INDEX);
			sort_decision_flag = true;
			break;
		case G_SORT_BY_NAME:
			cout << "Timezone list was sorted by Alphabet.\n";
			sortVector(g_timezone_list, C_SORT_BY_NAME);
			sort_decision_flag = true;
			break;

		default:
			cout << "Illegal input, please try again." << endl;
			break;
		}
	}

}

void sortLanguage() {
	const int C_SORT_BY_INDEX = 1;
	const int C_SORT_BY_NAME = 2;

	char sort_form_choice('c');
	bool sort_decision_flag = false;
	cout << "\nSorting Language list by:";
	cout << "\n1. Index\n2. Alphabet\n0. Leave it alone.\n";
	while (sort_decision_flag != true) {
		sort_decision_flag = false;
		cout << "Your choice: ";
		cin >> sort_form_choice;
		switch (sort_form_choice) {

		case '0':
			cout << "\nNo change in your list.\n";

			sort_decision_flag = true;
			break;
		case '2':
			cout << "Language list was sorted by Alphabet.\n";
			sortVector(g_language_list, C_SORT_BY_NAME);

			sort_decision_flag = true;
			break;
		case '1':
			cout << "Language list was sorted by Index.\n";
			sortVector(g_language_list, C_SORT_BY_NAME);
			sort_decision_flag = true;
			break;
		default:
			cout << "Illegal input, please try again." << endl;

			break;
		}
	}

}



void sortVector(vector<CommonInfo>& v, int choose) {
	// a=1: sortbyNumber
	// a=2: sortbyName

	switch (choose) {

	case 1:
		sort(v.begin(), v.end(), cmpByNum);
		break;

	case 2:
		sort(v.begin(), v.end(), cmpByAlphabet);
		break;
	}
}

bool cmpByAlphabet(CommonInfo obj1, CommonInfo obj2){
	return operator<(obj1, obj2);
}

bool cmpByNum(CommonInfo obj1, CommonInfo obj2) {

	return obj1 < obj2;
}