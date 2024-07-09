#include "../../std_lib_facilities.h"

int main()
{
    // program 1
    /*cout << "Hello programming!\n";
    cout << "Here we go!\n";*/

    // program 2
    /*cout << "Enter your name and age (and hit Enter):\n";
    string name = "???";
    double age = 0;
    cin >> name >> age;
    cout << "Hello " << name << " (" << age * 12 << " months old)\n";*/

    // program 3
    double d = 0;
    while (cin >> d)
    {
        int i1 = d;
        char c = i1;
        int i2 = c;

        cout << "d = " << d
            << " i1 = " << i1
            << " i2 = " << i2
            << " c = " << c << "\n";
    }

    return 0;
}
