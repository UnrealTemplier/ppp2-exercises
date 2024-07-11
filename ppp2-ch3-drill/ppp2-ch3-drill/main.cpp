#include "../../std_lib_facilities.h"

int main()
{
    string first_name;
    cout << "Enter first name of the person to write to: ";
    cin >> first_name;

    string friend_name;
    cout << "Enter friend name: ";
    cin >> friend_name;

    char friend_sex = 0;
    while (friend_sex != 'm' && friend_sex != 'f')
    {
        cout << "Enter friend's sex (m or f): ";
        cin >> friend_sex;
    }

    int age = 0;
    cout << "Enter your age: ";
    cin >> age;
    if (age <= 0 || age > 110)
        simple_error("You're kidding!");

    cout << endl;

    cout << "    Dear " << first_name << "," << endl;
    cout << "How are you? I'm fine. I miss you. " << endl;
    cout << "Have you seen " << friend_name << " lately?" << endl;

    string him_or_her = "him";
    if (friend_sex == 'f')
        him_or_her = "her";
    cout << "If you see " << friend_name << " please ask " << him_or_her << " to call me." << endl;

    cout << "I hear you just had a birthday and you are " << age << " years old." << endl;

    if (age < 12)
        cout << "Next year you will be " << age + 1 << "." << endl;
    if (age == 17)
        cout << "Next year you will be able to vote." << endl;
    if (age >= 70)
        cout << "I hope you are enjoying retirement." << endl;

    cout << "Sincerely yours, Sergey" << endl << endl << endl;

    return 0;
}
