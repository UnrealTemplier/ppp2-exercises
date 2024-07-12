#include "../../std_lib_facilities.h"

void ex2()
{
    double kmPerMile = 1.609;
    cout << "Enter amount of miles: ";
    double miles = 0;
    cin >> miles;
    cout << "In " << miles << " miles are " << miles * kmPerMile << " kilometers." << endl;
}

void ex3()
{
    int string1 = 0;
    //int string = 0;
    double _name = 0;
    //double int = 1;
    string STR = "";
    //string n_a%me = "";
    string na$me = "";
    //float 8name = 3.2;
}

void ex4()
{
    int val1 = 0, val2 = 0;
    cout << "Enter two integers: ";
    cin >> val1 >> val2;

    int smaller = val1;
    int larger = val2;
    if (val2 < smaller)
    {
        smaller = val2;
        larger = val1;
    }
    int sum = val1 + val2;
    int diff = larger - smaller;
    int product = val1 * val2;
    double ratio = 1.0 * larger / smaller;

    cout << "Smaller: " << smaller << endl;
    cout << "Larger: " << larger << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << product << endl;
    cout << "Ratio: " << ratio << endl;
}

void ex5()
{
    double val1 = 0, val2 = 0;
    cout << "Enter two floats: ";
    cin >> val1 >> val2;

    double smaller = val1;
    double larger = val2;
    if (val2 < smaller)
    {
        smaller = val2;
        larger = val1;
    }
    double sum = val1 + val2;
    double diff = larger - smaller;
    double product = val1 * val2;
    double ratio = larger / smaller;

    cout << "Smaller: " << smaller << endl;
    cout << "Larger: " << larger << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << product << endl;
    cout << "Ratio: " << ratio << endl;
}

void ex6()
{
    int val1 = 0, val2 = 0, val3 = 0;
    cout << "Enter three integers: ";
    cin >> val1 >> val2 >> val3;
    int smaller = val1;
    if (val2 < smaller)
        smaller = val2;
    if (val3 < smaller)
        smaller = val3;

    int larger = val1;
    if (val2 > larger)
        larger = val2;
    if (val3 > larger)
        larger = val3;

    int middle = val2;
    if (val1 != smaller && val1 != larger)
        middle = val1;
    if (val3 != smaller && val3 != larger)
        middle = val3;

    cout << smaller << ", " << middle << ", " << larger << endl;
}

void ex7()
{
    string val1 = " ", val2 = " ", val3 = " ";
    cout << "Enter three surnames: ";
    cin >> val1 >> val2 >> val3;
    string smaller = val1;
    if (val2 < smaller)
        smaller = val2;
    if (val3 < smaller)
        smaller = val3;

    string larger = val1;
    if (val2 > larger)
        larger = val2;
    if (val3 > larger)
        larger = val3;

    string middle = val2;
    if (val1 != smaller && val1 != larger)
        middle = val1;
    if (val3 != smaller && val3 != larger)
        middle = val3;

    cout << smaller << ", " << middle << ", " << larger << endl;
}

void ex8()
{
    int number = 0;
    cout << "enter a number: ";
    cin >> number;

    if (number % 2 == 0)
        cout << "number " << number << " is an even number." << endl;
    else
        cout << "number " << number << " is an odd number." << endl;
}

void ex9()
{
    string spelledNumber = "";
    cout << "Enter spelled number: ";
    cin >> spelledNumber;

    if (spelledNumber == "0" || spelledNumber == "zero")
        cout << 0 << endl;
    if (spelledNumber == "1" || spelledNumber == "one")
        cout << 1 << endl;
    if (spelledNumber == "2" || spelledNumber == "two")
        cout << 2 << endl;
    if (spelledNumber == "3" || spelledNumber == "three")
        cout << 3 << endl;
    if (spelledNumber == "4" || spelledNumber == "four")
        cout << 4 << endl;

    if (spelledNumber != "0" && spelledNumber != "1"
        && spelledNumber != "2" && spelledNumber != "3"
        && spelledNumber != "4" && spelledNumber != "zero"
        && spelledNumber != "one" && spelledNumber != "two"
        && spelledNumber != "three" && spelledNumber != "four")
        cout << "Not a number I know!" << endl;
}

void ex10()
{
    cout << "Enter query for calculation in a form of \'operation operand1 operand2\': ";
    string operation = "";
    double op1 = 0, op2 = 0;
    cin >> operation >> op1 >> op2;

    double result = 0;

    if (operation == "+" || operation == "plus")
        result = op1 + op2;
    if (operation == "-" || operation == "minus")
        result = op1 - op2;
    if (operation == "*" || operation == "mul")
        result = op1 * op2;
    if (operation == "/" || operation == "div")
        result = op1 / op2;

    cout << op1 << " " << operation << " " << op2 << " = " << result << endl;
}

void ex11()
{
    int pennies = 0;
    int nickels = 0;
    int dimes = 0;
    int quarters = 0;
    int half_dollars = 0;
    int dollars = 0;

    cout << "How many pennies do you have? ";
    cin >> pennies;
    cout << "How many nickels do you have? ";
    cin >> nickels;
    cout << "How many dimes do you have? ";
    cin >> dimes;
    cout << "How many quarters do you have? ";
    cin >> quarters;
    cout << "How many half dollars do you have? ";
    cin >> half_dollars;
    cout << "How many dollars do you have? ";
    cin >> dollars;

    cout << endl;

    string currencyName = "pennies";
    if (pennies == 1)
        currencyName = "penny";
    cout << "You have " << pennies << " " << currencyName << endl;

    currencyName = "nickels";
    if (nickels == 1)
        currencyName = "nickel";
    cout << "You have " << nickels << " " << currencyName << endl;

    currencyName = "dimes";
    if (dimes == 1)
        currencyName = "dime";
    cout << "You have " << dimes << " " << currencyName << endl;

    currencyName = "quarters";
    if (quarters == 1)
        currencyName = "quarter";
    cout << "You have " << quarters << " " << currencyName << endl;

    currencyName = "half dollars";
    if (half_dollars == 1)
        currencyName = "half dollar";
    cout << "You have " << half_dollars << " " << currencyName << endl;

    currencyName = "dollars";
    if (dollars == 1)
        currencyName = "dollar";
    cout << "You have " << dollars << " " << currencyName << endl;

    int sum = pennies + nickels * 5 + dimes * 10 + quarters * 25 + half_dollars * 50 + dollars * 100;
    cout << "The value of all of your coins is " << sum << " cents or $" << sum / 100.0 << endl;
}

int main()
{
    //ex2();
    //ex3();
    //ex4();
    //ex5();
    //ex6();
    //ex7();
    //ex8();
    //ex9();
    //ex10();
    ex11();
    return 0;
}
