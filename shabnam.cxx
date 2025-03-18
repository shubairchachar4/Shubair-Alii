#include <iostream>
#include <ctime>
#include <windows.h> 
#include <iomanip>
#include <conio.h>   

using namespace std;

class DigitalClock {
private:
    int hours, minutes, seconds;
    string timeFormat;

public:
    DigitalClock() {
        hours = minutes = seconds = 0;
        timeFormat = "AM";
    }

    void displayTime() {
        while (true) {
            system("cls");
            time_t now = time(0);
            tm* ltm = localtime(&now);
            
            cout << "=== Digital Clock ===" << endl;
            cout << setfill('0') << setw(2) << ltm->tm_hour << ":"
                 << setfill('0') << setw(2) << ltm->tm_min << ":"
                 << setfill('0') << setw(2) << ltm->tm_sec << endl;
            cout << "Press 'b' to go back" << endl;

            if (_kbhit()) {  
                char ch = _getch();
                if (ch == 'b' || ch == 'B') {
                    break;
                }
            }
            Sleep(1000);
        }
    }

    void setAlarm() {
        cout << "Set Alarm (24-hour format)" << endl;
        cout << "Enter hours (0-23): ";
        cin >> hours;
        cout << "Enter minutes (0-59): ";
        cin >> minutes;

        cout << "Alarm set for " << hours << ":" << minutes << endl;
        cout << "Press 'b' to go back" << endl;

        while (true) {
            time_t now = time(0);
            tm* ltm = localtime(&now);
            
            if (ltm->tm_hour == hours && ltm->tm_min == minutes) {
                cout << "\aALARM! ALARM! ALARM!" << endl;
                Sleep(5000);
                break;
            }
            if (_kbhit()) {
                char ch = _getch();
                if (ch == 'b' || ch == 'B') {
                    break;
                }
            }
            Sleep(1000);
        }
    }

    void stopwatch() {
        int sec = 0, min = 0, hr = 0;
        char start;
        
        cout << "Press 's' to start stopwatch: ";
        cin >> start;
        
        if (start == 's' || start == 'S') {
            while (true) {
                system("cls");
                cout << "Stopwatch: " << setfill('0') << setw(2) << hr << ":"
                     << setfill('0') << setw(2) << min << ":"
                     << setfill('0') << setw(2) << sec << endl;
                cout << "Press 'b' to go back" << endl;
                
                if (_kbhit()) {
                    char ch = _getch();
                    if (ch == 'b' || ch == 'B') {
                        break;
                    }
                }
                
                Sleep(1000);
                sec++;
                if (sec == 60) {
                    sec = 0;
                    min++;
                }
                if (min == 60) {
                    min = 0;
                    hr++;
                }
            }
        }
    }

    // Simple timer
    void timer() {
        int timeInSeconds;
        cout << "Enter time in seconds: ";
        cin >> timeInSeconds;

        while (timeInSeconds >= 0) {
            system("cls");
            cout << "Timer: " << timeInSeconds / 3600 << ":"
                 << (timeInSeconds % 3600) / 60 << ":"
                 << timeInSeconds % 60 << endl;
            cout << "Press 'b' to go back" << endl;
            
            if (_kbhit()) {
                char ch = _getch();
                if (ch == 'b' || ch == 'B') {
                    break;
                }
            }
            
            Sleep(1000);
            timeInSeconds--;
        }
        if (timeInSeconds < 0) {
            cout << "\aTIME'S UP!" << endl;
            Sleep(2000); 
        }
    }
};

int main() {
    DigitalClock clock;
    int choice;

    while (true) {
        system("cls");
        cout << "=== Digital Clocking System ===" << endl;
        cout << "1. Display Time" << endl;
        cout << "2. Set Alarm" << endl;
        cout << "3. Stopwatch" << endl;
        cout << "4. Timer" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                clock.displayTime();
                break;
            case 2:
                clock.setAlarm();
                break;
            case 3:
                clock.stopwatch();
                break;
            case 4:
                clock.timer();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
                Sleep(1000);
        }
    }
    return 0;
}