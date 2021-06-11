#include "General.h"
#include "CommonInfo.h"


//external vector
extern vector<CommonInfo> timezoneList;
extern vector<CommonInfo> languageList;

General::General() :Setting()                    //Default constructor
{
    timeZone = language = "";
}
General::General(Setting h, string time, string ngonngu) : Setting(h)
{ //Parameter constructor
    timeZone = time;
    language = ngonngu;
}
General::~General() {                                //Destructor

}
General::General(const General& h) :Setting(h) {                      //Copy method
    this->language = h.language;
    this->timeZone = h.timeZone;

}

General& General::operator = (General& m) {            //Assign operator
    if (this == &m) return *this;

    Setting(*this) = Setting::operator=(m);
    this->language = m.language;
    this->timeZone = m.timeZone;
};

void General::nhapThongTin() {
    char ca[5], cb[5];
    bool flag{ false };

    int a{}, b{};
    cout << "\n--- SELECT TIMEZONE DATA ---\n";
    printData(timezoneList);
    try {
        while (flag != true) {

            cout << "\nYOUR SELECTION: ";
            cin >> ca;
            if (isdigit(ca[0])) {
                a = atoi(ca);
            }
            else continue;
            a = a - 1;
            if (a > 31) {
                cout << "Illegal choice, there are 32 timezones in data, please choose again." << endl;									//Xuat thong bao va bat dau lai vong lap neu nhap so lon hon du lieu
                continue;
            }
            cout << timezoneList.at(a).getNumber() << ":" << timezoneList.at(a).getName();

            set_timeZone(timezoneList.at(a).getNumber());


            flag = true;
        }
    }
    catch (...) {
        cerr << "Illegal input" << endl;
        return;
    }

    flag = false;
    cout << "\n\n--- SELECT LANGUAGE DATA ---\n ";

    printData(languageList);
    try {
        while (flag != true) {

            cout << "\nYOUR SELECTION: ";
            cin >> cb;
            if (isdigit(cb[0])) {
                b = atoi(cb);
            }
            else continue;
            b = b - 1;
            if (b > 29) {
                cout << "Illegal choice, there are 30 languages in data." << endl;									//Xuat thong bao va bat dau lai vong lap neu nhap so lon hon du lieu
                continue;
            }
            cout << languageList.at(b).getNumber() << ":" << languageList.at(b).getName();
            set_language(languageList.at(b).getName());
            cout << endl;
            flag = true;
            system("pause");
        }
    }
    catch (...) {
        cerr << "Illegal input." << endl;
        system("pause");
        return;
    }
}

void General::xuatThongTin() {

    cout << "\nTimezone: " << get_timeZone() << endl;
    cout << "Language: " << get_language() << endl;
}

string General::get_language() {
    return language;
}

string General::get_timeZone() {
    return timeZone;
}

void General::set_timeZone(string data) {
    timeZone = data;
}

void General::set_language(string data1) {
    language = data1;
}
bool General::operator > (const General& right)
{
    bool status;

    if (personal_key > right.personal_key)
        status = true;
    else
        status = false;

    return status;
}

bool General::operator < (const General& right)
{
    bool status;

    if (personal_key < right.personal_key)
        status = true;
    else
        status = false;

    return status;
}

bool General::operator == (const General& right)
{
    bool status;

    if (personal_key == right.personal_key)
        status = true;
    else
        status = false;

    return status;
}

bool operator==(const General& lhs, const General& rhs) {
    bool status;
    if (lhs.car_name == rhs.car_name) {
        status = true;
    }
    else
        status = false;
    return status;
}
bool operator<(const General& lhs, const General& rhs) {
    bool status;
    if (lhs.car_name < rhs.car_name) {
        status = true;
    }
    else
        status = false;
    return status;
}
bool operator>(const General& lhs, const General& rhs) {
    bool status;
    if (lhs.car_name > rhs.car_name) {
        status = true;
    }
    else
        status = false;
    return status;
}