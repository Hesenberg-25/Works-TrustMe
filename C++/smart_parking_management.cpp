#include <iostream>
#include <string.h>
#include <ctime>
#include <random>
using namespace std;

class Wheeler
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
    void welcome(void)
    {
        cout << "======= :: WELCOME TO HESENBERG ONLINE PARKING :: =======" << endl;
    }
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
    string time_then()
    {
        string time;
        int choice;
        cout << "ENTER THE NUMBER FOR TIME UNIT : " << endl
             << "1. MINUTES" << endl
             << "2. HOURS" << endl
             << "3. DAYS" << endl;
        switch (choice)
        {
        case 1:
            time = time + " " + "MINUTES";
            break;
        case 2:
            time = time + " " + "HOURS";
            break;
        case 3:
            time = time + " " + "DAYS";
            break;
        default:
            break;
        }
    }
    void times(float, float);
    void times(float booked_for, float exit_time)
    {
        string time;
        int choice;
        cout << "ENTER THE NUMBER FOR TIME UNIT : " << endl
             << "1. MINUTES" << endl
             << "2. HOURS" << endl
             << "3. DAYS" << endl;
        switch (choice)
        {
        case 1:
            time = time + " " + "MINUTES";
            
            break;
        case 2:
            time = time + " " + "HOURS";
            break;
        case 3:
            time = time + " " + "DAYS";
            break;
        default:
            break;
        }
        cout << "5. BOOKED AT     : " << time_now();
        cout << "6. BOOKED FOR    : " << time << endl;
        cout << "7. EXIT TIME     : ";
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
    string vehicle_numplate;
    string owner_name;
    string phone_number;
    Wheeler C1;
    C1.welcome();
    cout << "ENTER YOUR NAME : ";
    cin >> owner_name;
    cout << "ENTER PHONE NUMBER : ";
    cin >> phone_number;
    cout << "ENTER THE VEHICLE NUMBERPLATE : ";
    cin >> vehicle_numplate;
    string time, timed;
    float time;
    cout << "ENTER FOR HOW MUCH TIME YOU WANT TO PARK : ";
    cin >> time;
    C1.input_details(vehicle_numplate, owner_name, phone_number);
    C1.times(time,time);
    C1.output();
    return 0;
}
