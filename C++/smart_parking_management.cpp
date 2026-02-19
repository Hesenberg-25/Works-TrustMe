#include <iostream>
#include <ctime>
#include <random>

using namespace std;

class Wheeler
{
private:
    string parking_id;
    string vehicle_numplate;
    string owner_name;
    string phone_number;
    float timed;
    int time_unit;

    string generate_id()
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(1000, 9999);
        return "P" + to_string(dist(gen));
    }

public:
    Wheeler()
    {
        parking_id = generate_id(); // Generate once
    }

    void welcome()
    {
        cout << "\n======= :: WELCOME TO HESENBERG ONLINE PARKING :: =======\n";
    }

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
        tm *local = localtime(&now);

        strftime(timestamp, sizeof(timestamp),
                 "%d-%m-%Y %H:%M:%S", local);

        return string(timestamp);
    }

    void time_input()
    {
        cout << "ENTER PARKING DURATION: ";
        cin >> timed;
    }

    string booked_for()
    {
        cout << "\nSELECT TIME UNIT:\n";
        cout << "1. Minutes\n";
        cout << "2. Hours\n";
        cout << "3. Days\n";
        cout << "Enter choice: ";

        cin >> time_unit;

        if (time_unit == 1)
            return to_string(timed) + " Minutes";
        else if (time_unit == 2)
            return to_string(timed) + " Hours";
        else if (time_unit == 3)
            return to_string(timed) + " Days";
        else
            return "Invalid Time Selection";
    }

    void output(string duration)
    {
        cout << "\n\n======== :: PARKING DETAILS :: ========\n";
        cout << "Parking ID       : " << parking_id << endl;
        cout << "Vehicle Number   : " << vehicle_numplate << endl;
        cout << "Owner Name       : " << owner_name << endl;
        cout << "Phone Number     : " << phone_number << endl;
        cout << "Time of Booking  : " << time_now() << endl;
        cout << "Booked Duration  : " << duration << endl;
        cout << "========================================\n";
    }
};

int main()
{
    Wheeler C1;

    string vehicle_numplate;
    string owner_name;
    string phone_number;

    C1.welcome();

    cout << "ENTER YOUR NAME: ";
    cin >> owner_name;

    cout << "ENTER PHONE NUMBER: ";
    cin >> phone_number;

    cout << "ENTER VEHICLE NUMBERPLATE: ";
    cin >> vehicle_numplate;

    C1.input_details(vehicle_numplate, owner_name, phone_number);
    C1.time_input();

    string duration = C1.booked_for();
    C1.output(duration);

    return 0;
}
