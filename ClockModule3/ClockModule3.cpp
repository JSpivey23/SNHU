#include <iostream>
#include <string>

using namespace std;

int hours;
int minutes;
int seconds;

void DisplayTime(int hours, int minutes, int seconds) {
    cout << "24-hour time: ";
    cout << (hours < 10 ? "0" : "") << hours << ":";
    cout << (minutes < 10 ? "0" : "") << minutes << ":";
    cout << (seconds < 10 ? "0" : "") << seconds << endl;

    cout << "12-hour time: ";
    if (hours >= 12) {
        cout << (hours - 12 < 10 ? "0" : "") << hours - 12;
    }
    else {
        cout << (hours < 10 ? "0" : "") << hours;
    }
    cout << ":" << (minutes < 10 ? "0" : "") << minutes << ":";
    cout << (seconds < 10 ? "0" : "") << seconds;
    cout << (hours >= 12 ? " PM" : " AM") << endl; 

}

void GetUserInput(int& hours, int& minutes, int& seconds) {
    bool exit = false;
    while (!exit) {
        cout << "Enter hours in 24 hour format: HH" << endl;
        cin >> hours;
        if (hours < 0 || hours > 24 ) {
            cout << "Error: Must be integer 24 or lower. Try again" << endl;
            continue;   
        }
        cout << "Minutes: MM" << endl;
        cin >> minutes;
        if (minutes < 0 || minutes > 59) {
            cout << "Error: Must be integer 59 or lower. Try again" << endl;
            continue;
        }
        cout << "Seconds: SS" << endl;
        cin >> seconds;
        if (seconds < 0 || seconds > 59) {
            cout << "Error: Must be integer 59 or lower. Try again" << endl;
            continue;
        }
        if ((seconds < 60) && (hours < 25) && (minutes < 60)) {
            exit = true;
        }
    }
}

void AddHour(int& hours) {
    hours = (hours + 1) % 24;
}

void AddMinute(int& minutes,int& hours) {
    if (minutes >= 59) {
        AddHour(hours);
    }
    minutes = (minutes + 1) % 60;
}

void AddSecond(int& seconds, int& minutes, int& hours) {
    if (seconds >= 59) {
       AddMinute(minutes, hours);
      if (minutes >= 59) {
           AddHour(hours);
       }
    }
    seconds = (seconds + 1) % 60;
}

int main() {
 
    bool exitProgram = false;

    GetUserInput(hours, minutes, seconds);
// Main Loop
    while (!exitProgram) {

        DisplayTime(hours, minutes, seconds);

        cout << "Menu Options:" << endl;
        cout << "1. Add an hour" << endl;
        cout << "2. Add a minute" << endl;
        cout << "3. Add a second" << endl;
        cout << "4. Exit" << endl;
 
        string choice;
        cout << "Enter your choice (1-4): ";
       
        cin >> choice;

        if (choice == "1") {
            AddHour(hours);
        }
        else if (choice == "2") {
            AddMinute(minutes, hours);
        }
        else if (choice == "3") {
            AddSecond(seconds, minutes, hours);
        }
        else if (choice == "4") {
            exitProgram = true;
        }
        else {
            cout << "Invalid Choice: Pick Another Option";
        }
        cin.ignore();
    }
    return 0;
}
