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


vector<CommonInfo> timezoneList;
vector<CommonInfo> languageList;

void NhapThongTinCaiDat();
void XuatThongTinCaiDat();

void XuatThongTinCaiDat_Sound();
void XuatThongTinCaiDat_General();
void XuatThongTinCaiDat_Display();
void XuatTatCaThongTinCaiDat();

void NhapThongTinCaiDat_Sound();
void NhapThongTinCaiDat_General();
void NhapThongTinCaiDat_Display();

void downloadTimeZone();
void downloadLanguage();

void readfromfileSetting();
void writetofileSetting();
int menu();

void sortTimezone();									//Sap xep Timezone
void sortLanguage();									//Sap xep Language
void sort_vector(vector<CommonInfo>& v, int a);
bool cmpnum(CommonInfo obj1, CommonInfo obj2);
bool cmpalpha(CommonInfo obj1, CommonInfo obj2);



/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	downloadLanguage();
	downloadTimeZone();



	char decision = 'c';								//Tiep tuc nha du lieu cho xe tiep theo hay khong
	bool flag{ false };									//Flag cho while

	readfromfileSetting();


	while (flag != true) {
		decision = 'c';

		cout << "There is (are) " << Vehicle.size() << " car(s) in the system." << endl;
		cout << "Will you import another user? (y/n) :";//Goi y chon tao doi tuong moi
		cin >> decision;
		if (toupper(decision) == 'Y') {

			cin.ignore(1);
			system("cls");

			cout << "Car number: " << Vehicle.size() + 1 << endl;

			Setting data;

			data.nhapThongTin();

			Display DIS(data, 1, 1, 1);					//Tao doi tuong cua lop Display ke thua du lieu tu lop Setting
			Sound SND(data, 1, 1, 1, 1);				//Tao doi tuong cua lop Sound ke thua du lieu tu lop Setting
			General GEN(data, "(GMT-12:00)", "Mandarin (entire branch)");					//Tao doi tuong cua lop General ke thua du lieu tu lop Setting



			Car newcar(data, SND, DIS, GEN);
			Vehicle.insertNode(newcar);



			

		}
		else {
			if (toupper(decision) == 'N') {
				cin.clear();
				cin.ignore(100, '\n');
				menu();

				flag = true;
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

int menu() {
	char a('c');
	char decision('c');
	int selection{};										//Chon che do
	bool flag{ false }, flagadd{ false };										//Flag cho vong lap while
	Vehicle.updateTreeAVL();
	while (flag != true) {
		system("cls");
		cout << "--- SELECT MENU ---\n";
		cout << "1. Input setting information" << endl;		//Thong tin nhap vao duoc luu tru tam trong vetor
		cout << "2. Print setting information" << endl;		//Khi chon xuat thong tin thi thong tin se duoc cap nhat vao binary tree
		cout << "3. Add another vehicle\n";
		cout << "4. Exit\nYour seclection: ";
		
		cin >> a;
		try {
			switch (a) {							//Switch-case nhu menu
			case '1':
				NhapThongTinCaiDat();
				cin.clear();
				cin.ignore(100, '\n');
				break;
			case '2':
				XuatThongTinCaiDat();
				cin.clear();
				cin.ignore(100, '\n');
				break;
			case '4':

				cout << "\nGood bye.";
				cout << endl;
				system("pause");
				flag = true;
				break;
			case '3':
				while (flagadd != true) {
					decision = 'c';

					cout << "There is (are) " << Vehicle.size() << " car(s) in the system." << endl;
					cout << "Will you import another user? (y/n) :";//Goi y chon tao doi tuong moi
					cin >> decision;
					if (toupper(decision) == 'Y') {

						cin.ignore(1);
						system("cls");

						cout << "Car number: " << Vehicle.size() + 1 << endl;

						Setting data;

						data.nhapThongTin();

						Display DIS(data, 1, 1, 1);					//Tao doi tuong cua lop Display ke thua du lieu tu lop Setting
						Sound SND(data, 1, 1, 1, 1);				//Tao doi tuong cua lop Sound ke thua du lieu tu lop Setting
						General GEN(data, "(GMT-12:00)", "Mandarin (entire branch)");					//Tao doi tuong cua lop General ke thua du lieu tu lop Setting



						Car newcar(data, SND, DIS, GEN);
						Vehicle.insertNode(newcar);

					}
					else {
						if (toupper(decision) == 'N') {
							cin.clear();
							cin.ignore(100, '\n');
							menu();

							flagadd = true;
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
	}return selection;
}

void NhapThongTinCaiDat() {
	char choose;										//Chon xe de cai dat thong tin Display/Sound/General
	char indx[10];
	bool flag{ false }, flagbis{ false };				//Flag cho while 


	while (flag != true) {
		system("cls");
		cout << "--- SELECT MENU ---" << endl;
		cout << "1. Display setting " << endl;
		cout << "2. Sound setting " << endl;
		cout << "3. General setting" << endl;
		cout << "0. Back\nYour selection: ";
		cin >> choose;

		try {
			switch (choose) {
			case '1':																//Nhap thong tin cho Display
				system("cls");
				cin.clear();
				cin.ignore(100, '\n');
				cout << " --- Ban nhap thong tin Display --- " << endl;			//Xuat thong bao da chon Input Display

				NhapThongTinCaiDat_Display();							//Ham Input Display


				break;

			case '2':
				system("cls");
				cin.clear();
				cin.ignore(100, '\n');
				cout << " --- Ban nhap thong tin Sound --- " << endl;			//Xuat thong bao da chon Input Sound

				NhapThongTinCaiDat_Sound();								//Ham Input Sound

				break;

			case '3':
				cin.clear();
				cin.ignore(100, '\n');
				system("cls");
				cout << " --- Ban nhap thong tin General --- " << endl;
				NhapThongTinCaiDat_General();

				break;
			case '0':
				system("cls");

				flag = true;
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

void NhapThongTinCaiDat_Sound()
{
	Vehicle.nhap_thong_tin_sound();
	system("pause");

}

void NhapThongTinCaiDat_General() {


	sortLanguage();
	sortTimezone();
	Vehicle.nhap_thong_tin_general();
	system("pause");
}
void NhapThongTinCaiDat_Display()
{

	Vehicle.nhap_thong_tin_display();


	system("pause");

}

void XuatThongTinCaiDat() {
	char selection = 'c';											//Chon che do xuat

	bool flag{ false };
	while (flag != true) {
		system("cls");
		cout << "--- SELECT MENU ---\n";
		cout << "1. Print Display setting information\n";
		cout << "2. Print Sound setting information\n";
		cout << "3. Print General setting information\n";
		cout << "4. Print all setting information\n";
		cout << "0. Back\nYour selection: ";
		cin >> selection;


		writetofileSetting();
		system("cls");
		Vehicle.updateTreeAVL();
		switch (selection) {
		case '1':
			cout << "--- Display setting ---\n";
			cin.clear();
			cin.ignore(100, '\n');
			XuatThongTinCaiDat_Display();					//Ham xuat thong tin cai dat Display
			break;
		case '2':
			cout << "--- Sound setting ---\n";
			cin.clear();
			cin.ignore(100, '\n');
			XuatThongTinCaiDat_Sound();						//Ham xuat thong tin cai dat Sound
			break;
		case '3':
			cout << "--- General setting ---\n";
			cin.clear();
			cin.ignore(100, '\n');
			XuatThongTinCaiDat_General();					//Ham xuat thong tin cai dat General
			break;
		case '4':
			cout << "--- All setting ---\n";					//Ham xuat thong tin tat cacai dat 
			cin.clear();
			cin.ignore(100, '\n');
			XuatTatCaThongTinCaiDat();
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


void XuatThongTinCaiDat_Sound() {
	char choose{};
	bool flag{ false };


	while (flag != true) {
		system("cls");
		cout << "Sorting sound data by :\n1. Personal Key\n2. Car Name\n";
		cout << "Your choice: ";
		cin >> choose;

		if (choose == '1') {
			Vehicle.BST_by_ID();
			cin.clear();
			cin.ignore(100, '\n');
			flag = true;
		}
		else if (choose == '2') {
			Vehicle.BST_by_name();
			cin.clear();
			cin.ignore(100, '\n');
			flag = true;
		}
		else {
			cout << "Illegal choice, please try again.\n";
			cin.clear();
			cin.ignore(100, '\n');
			system("pause");
			continue;

		}
	}
	cout << endl;
	cout << setw(20) << left << "Owner name" << setw(25) << left << "Email" << setw(20) << left << "Key number" << setw(20) << left << "ODO number" << setw(20) << left << "Remind service" << setw(20) << left << "Media" << setw(20) << left << "Call" << setw(20) << left << "Navigation" << setw(20) << left << "Notification" << endl;							//Format String
	Vehicle.xuat_thong_tin_sound();
	system("pause");
}


void XuatThongTinCaiDat_General() {
	bool flag{ false };
	char choose('c');
	while (flag != true) {
		system("cls");
		cout << "Sorting general data by :\n1. Personal Key\n2. Car Name\n";
		cout << "Your choice";
		cin >> choose;
		if (choose == '1') {
			Vehicle.BST_by_ID();
			cin.clear();
			cin.ignore(100, '\n');
			flag = true;
		}
		else if (choose == '2') {
			Vehicle.BST_by_name();
			cin.clear();
			cin.ignore(100, '\n');
			flag = true;
		}
		else {
			cout << "Illegal choice, please try again.\n";
			cin.clear();
			cin.ignore(100, '\n');
			system("pause");
			continue;

		}
	}
	cout << endl;
	cout << setw(20) << left << "Owner name" << setw(25) << left << "Email" << setw(20) << left << "Key number" << setw(20) << left << "ODO number" << setw(20) << left << "Remind service" << setw(15) << left << "TimeZone" << setw(30) << left << "Language" << endl;
	Vehicle.xuat_thong_tin_general();
	system("pause");
}

void XuatThongTinCaiDat_Display() {
	bool flag{ false };
	char choose('c');

	while (flag != true) {
		system("cls");
		cout << "Sorting display data by :\n1. Personal Key\n2. Car Name\n";
		cout << "Your choice: ";
		cin >> choose;
		if (choose == '1') {
			Vehicle.BST_by_ID();
			cin.clear();
			cin.ignore(100, '\n');
			flag = true;
		}
		else if (choose == '2') {
			Vehicle.BST_by_name();
			cin.clear();
			cin.ignore(100, '\n');
			flag = true;
		}
		else {
			cout << "Illegal choice, please try again.\n";
			cin.clear();
			cin.ignore(100, '\n');
			system("pause");
			continue;

		}
	}
	cout << endl;
	cout << setw(20) << left << "Owner name" << setw(25) << left << "Email" << setw(20) << left << "Key number" << setw(20) << left << "ODO number" << setw(20) << left << "Remind service" << setw(20) << left << "Light level" << setw(20) << left << "Taplo light level" << setw(20) << left << "Screen light level" << endl;

	Vehicle.xuat_thong_tin_display();
	system("pause");
}

void XuatTatCaThongTinCaiDat() {
	char c = 'c';

	string indx;
	bool flagys{ false }, coinsisive{ false };
	size_t i = 0;
	bool flag{ false };
	char choose('c');
	cout << endl << endl;
	while (flag != true) {
		system("cls");
		cout << "Sorting all data by :\n1. Personal Key\n2. Car Name\nYour choice: ";
		cin >> choose;
		if (choose == '1') {
			Vehicle.BST_by_ID();
			cin.clear();
			cin.ignore(100, '\n');
			flag = true;
		}
		else if (choose == '2') {
			Vehicle.BST_by_name();
			cin.clear();
			cin.ignore(100, '\n');
			flag = true;
		}
		else {
			cout << "Illegal choice, please try again.\n";
			cin.clear();
			cin.ignore(100, '\n');
			system("pause");


		}
	}

	writetofileSetting();
	cout << endl;

	Vehicle.xuat_thong_tin_tat_ca();

	while (flagys != true) {
		coinsisive = false;
		flagys = false;
		cout << "\nWould you like to update user data? [yes/no]" << endl;

		cin >> c;
		if (toupper(c) == 'Y') {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Which car (input Key Number): ";
			cin >> indx;
			if (Vehicle.searchNodebyID(indx)) {
				Vehicle.updateData(indx);



			}
			else {
				cout << "\nIllegal choice. Could you try again?";
				cin.clear();
				cin.ignore(100, '\n');
			}


		}
		if (toupper(c) == 'N') {

			cin.clear();
			cin.ignore(100, '\n');
			flagys = true;
		}
		else {
			cin.clear();
			cin.ignore(100, '\n');
		}


	}
	system("pause");
}


void downloadTimeZone() {
	ifstream f;													//Doi tuong cua ifstream de mo file	
	CommonInfo obj[32];											//Mang  doi tuong
	f.open("timezones.txt");									//Lenh mo file
	if (!f) {													//Neu mo khong thanh cong
		cerr << "Can't open timezones.txt file!" << endl;
		return;

	}
	else {
		try {													//Exception Handle neu khong doc thanh cong file
			for (int i = 0; i < 32; i++) {						//Neu doc duoc 
				cout << flush;									//Vi input la string nen xoa bo nho dem
				obj[i].doc(f);									//Ham Friend doc duoc dinh nghia trong Class CommonInfo
				timezoneList.push_back(obj[i]);					//Them vao vector

			}
			cout << "The TimeZoneList download process is successfull.\n";
		}
		catch (...) {
			cerr << "Can't read this file !" << endl;

			return;
		}
	}
	f.close();
}


void downloadLanguage() {
	ifstream f;													//Doi tuong cua ifstream de mo file	
	CommonInfo objl[30];										//Mang  doi tuong
	f.open("languages.txt");									//Lenh mo file
	if (f.fail()) {												//Neu mo khong thanh cong
		cerr << "Can't open the languages.txt file!";
		return;

	}
	else {
		try {													//Exception Handle neu khong doc thanh cong file
			for (int i = 0; i < 30; i++) {						//Neu doc duoc 
				cout << flush;									//Vi input la string nen xoa bo nho dem
				objl[i].doc(f);
				languageList.push_back(objl[i]);				//Them vao vector
			}
			cout << "The LanguageList download process is successfull.\n";
		}
		catch (...) {
			cerr << "Can't read the language.txt file!";
			return;
		}
	}
	f.close();
}

void readfromfileSetting() {
	ifstream f;
	string begin_word;
	string string_word, string_num;
	int num{};
	f.open("Setting.txt", ios::in);
	if (f.fail()) {
		cerr << "Can't open the Setting.txt file to read!";
		return;
	}
	else {
		try {

			f.seekg(0, ios::end);
			size_t size = f.tellg();
			if (size == 0) {
				cout << "Ready to write on file.";
				system("cls");

				cout << "Car number: " << 1  << endl;

				Setting data;

				data.nhapThongTin();

				Display DIS(data, 1, 1, 1);					//Tao doi tuong cua lop Display ke thua du lieu tu lop Setting
				Sound SND(data, 1, 1, 1, 1);				//Tao doi tuong cua lop Sound ke thua du lieu tu lop Setting
				General GEN(data, "(GMT-12:00)", "Mandarin (entire branch)");					//Tao doi tuong cua lop General ke thua du lieu tu lop Setting				



				Car newcar(data, SND, DIS, GEN);
				Vehicle.insertNode(newcar);//Them cac doi tuong vao binary tree them vao DATA_b de kiem tra

				

			}
			else {
				f.seekg(0);
				while (!f.eof()) {
					Setting data;

					f >> begin_word;
					f.seekg(3, 1);
					getline(f, string_word, '/');
					data.setCarName(string_word);

					getline(f, string_word, '/');
					data.setEmail(string_word);

					getline(f, string_word, '/');
					data.setPersonalKey(string_word);

					getline(f, string_num, '/');
					num = stoi(string_num);
					data.setODO(num);

					getline(f, string_num, 'S');
					num = stoi(string_num);

					data.setServiceRemind(num);


					getline(f, begin_word, ':');
					f.seekg(4, 1);

					Sound SND(data, 0, 0, 0, 0);

					getline(f, string_num, '/');
					num = stoi(string_num);
					SND.set_media_level(num);

					getline(f, string_num, '/');
					num = stoi(string_num);
					SND.set_call_level(num);

					getline(f, string_num, '/');
					num = stoi(string_num);
					SND.set_navi_level(num);

					getline(f, string_num, 'D');
					num = stoi(string_num);
					SND.set_notification_level(num);

					Display DIS(data, 0, 0, 0);

					getline(f, begin_word, ':');
					f.seekg(2, 1);

					getline(f, string_num, '/');
					num = stoi(string_num);
					DIS.set_light_level(num);

					getline(f, string_num, '/');
					num = stoi(string_num);
					DIS.set_screen_light_level(num);

					getline(f, string_num, 'G');
					num = stoi(string_num);
					DIS.set_taplo_light_level(num);


					General GEN(data, "", "");



					getline(f, begin_word, ':');
					f.seekg(2, 1);
					getline(f, string_word, '/');
					GEN.set_timeZone(string_word);

					getline(f, string_word);
					GEN.set_language(string_word);
					f.ignore(1);
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
	f.close();
}
void writetofileSetting() {
	Vehicle.writetofileSetting();

}
void sortTimezone() {
	char a('c');
	bool flag = false;
	cout << "\nSorting Timezone list by:";
	cout << "\n1. Index\n2. Alphabet\n0. Leave it alone.\n";

	while (flag != true) {
		flag = false;
		cout << "Your choice: ";
		cin >> a;
		switch (a) {
		case '0':
			cout << "\nNo change in your list.\n";
			flag = true;
			break;
		case '1':
			cout << "\nTimezone list was sorted by GMT Index.\n";
			sort_vector(timezoneList, 1);
			flag = true;
			break;
		case '2':
			cout << "Timezone list was sorted by Alphabet.\n";
			sort_vector(timezoneList, 2);

			flag = true;
			break;

		default:
			cout << "Illegal input, please try again." << endl;

			break;
		}
	}

}

void sortLanguage() {
	char a('c');
	bool flag = false;
	cout << "\nSorting Language list by:";
	cout << "\n1. Index\n2. Alphabet\n0. Leave it alone.\n";
	while (flag != true) {
		flag = false;
		cout << "Your choice: ";
		cin >> a;
		switch (a) {

		case '0':
			cout << "\nNo change in your list.\n";

			flag = true;
			break;
		case '2':
			cout << "Language list was sorted by Alphabet.\n";
			sort_vector(languageList, 2);

			flag = true;
			break;
		case '1':
			cout << "Language list was sorted by Index.\n";
			sort_vector(languageList, 1);
			flag = true;
			break;
		default:
			cout << "Illegal input, please try again." << endl;

			break;
		}
	}

}



void sort_vector(vector<CommonInfo>& v, int a) {
	// a=1: sortbyNumber
	// a=2: sortbyName




	switch (a) {

	case 1:
		sort(v.begin(), v.end(), cmpnum);
		break;

	case 2:
		sort(v.begin(), v.end(), cmpalpha);
		break;
	}
}

bool cmpalpha(CommonInfo obj1, CommonInfo obj2)
{
	return operator<(obj1, obj2);
}

bool cmpnum(CommonInfo obj1, CommonInfo obj2) {

	return obj1 < obj2;
}