#include <iostream>
#include <string.h>
#include <ctime>
#include <random>
using namespace std;

class Main
{
public:
    void welcome(void)
    {
        cout << "======= :: WELCOME TO HESENBERG ONLINE PARKING :: =======" << endl;
    }
};

class Wheeler : protected Main
{
protected:
    string generate_id()
    {
        random_device rnd;
        mt19937 gen(rnd());
        uniform_int_distribution<> dist(1000, 9999);
        return "P" + to_string(dist(gen));
    }
    string vehicle_numplate;
    string owner_name;
    string phone_number;
    string timed;

private:
public:
    void input_details(string, string, string, float);
    void input_details(string num, string name, string phone)
    {
        vehicle_numplate = num;
        owner_name = name;
        phone_number = phone;
    }
    string time_now()
    {
        char timestamp[50];
        time_t now = time(NULL);
        struct tm *local = localtime(&now);
        strftime(timestamp, sizeof(timestamp), "%d-%m-%Y %H:%M:%S", local);
        return string(timestamp);
    }
    void times(string);
    void times(string time_booked)
    {
        timed = time_booked;
        cout << "5. BOOKED AT     : " << time_now();
        cout << "6. BOOKED FOR    : " << timed << endl;
    }
    void output(void)
    {
        cout << "======== :: PARKING DETAILS :: ======== " << endl;
        cout << "1. PARKING ID     : " << generate_id << endl;
        cout << "2. VEHICLE NUMBER : " << vehicle_numplate << endl;
        cout << "3. OWNER NAME     : " << owner_name << endl;
        cout << "4. PHONE NUMBER   : " << phone_number << endl;
        void times();
    }
};

int main()
{
    string time, timed;
    float times;
    cout << "ENTER FOR HOW MUCH TIME YOU WANT TO PARK : ";
    cin >> times;
    time = times;
    int choice;
    cout << "ENTER THE NUMBER FOR TIME UNIT : " << endl
         << "1. MINUTES" << endl
         << "2. HOURS" << endl
         << "3. DAYS" << endl;
    switch (choice)
    {
    case 1:
        timed = time + " " + "MINUTES";
        break;
    case 2:
        timed = time + " " + "HOURS";
        break;
    case 3:
        timed = time + " " + "DAYS";
        break;
    default:
        break;
    }
    return 0;
}