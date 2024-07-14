#include "../../std_lib_facilities.h"

bool isAlmostEqual(double num1, double num2)
{
    double maxDelta = 1.0 / 100;
    double delta = abs(num1 - num2);
    return delta < maxDelta;
}

void printPrompt()
{
    cout << "Enter a float number followed by a unit (units accepted: cm, m, in, ft) (f.e. 34cm, 23ft): ";
}

void printSmallestMessage()
{
    cout << "This is the smallest so far" << endl;
}

void printLargestMessage()
{
    cout << "This is the largest so far" << endl;
}

void printIllegalUnitMessage()
{
    cout << "The unit is empty or incorrect" << endl;
}

void printFinalMessage(vector<double> allNumbers, double smallest, double largest, double sum, double numberOfValues)
{
    cout << endl;
    cout << "You entered " << numberOfValues << " numbers." << endl;
    cout << "It was these numbers:" << endl;
    sort(allNumbers);
    for (double number : allNumbers)
        cout << number << " ";
    cout << endl;
    cout << "Sum (in meters) of your numbers is " << sum << "." << endl;
    cout << "The smallest number is " << smallest << "." << endl;
    cout << "The largest number is " << largest << "." << endl;
    cout << endl;
}

bool isUnitLegal(string unit)
{
    bool isUnitEmpty = unit == "";
    bool isUnitAllowed = (unit == "cm") || (unit == "m") || (unit == "in") || (unit == "ft");
    return !isUnitEmpty && isUnitAllowed;
}

double addToSum(double currentSum, double value, string unit)
{
    double newSum = currentSum;

    if (unit == "m")
    {
        newSum += value;
    }
    else
    {
        constexpr double cmPerM = 100;
        constexpr double cmPerIn = 2.54;
        constexpr double inPerFt = 12;

        if (unit == "cm")
            newSum += (value / cmPerM);
        else if (unit == "in")
            newSum += (value * cmPerIn / cmPerM);
        else if (unit == "ft")
            newSum += (value * inPerFt * cmPerIn / cmPerM);
    }

    return newSum;
}

int main()
{
    /*cout << "Enter two numbers: ";
    double a = 0, b = 0;
    while (cin >> a >> b)
    {
        cout << a << " " << b << endl;

        if (a < b)
        {
            cout << "The smaller value is " << a << endl;
            if (isAlmostEqual(a, b))
                cout << "The numbers are almost equal" << endl;
        }
        else if (b < a)
        {
            cout << "The smaller value is " << b << endl;
            if (isAlmostEqual(a, b))
                cout << "The numbers are almost equal" << endl;
        }
        else
            cout << "The numbers are equal" << endl;

        cout << endl << "Enter two numbers: ";
    }*/

    double number = 0;
    string unit = "";

    double smallest = 0, largest = 0;
    double numberOfValues = 0, sum = 0;

    vector<double> allNumbers = {};

    printPrompt();
    cin >> number >> unit;
    if (isUnitLegal(unit))
    {
        smallest = largest = number;
        cout << "You entered: " << number << unit << endl;
        printSmallestMessage();
        printLargestMessage();

        ++numberOfValues;
        sum = addToSum(sum, number, unit);
        allNumbers.push_back(number);
    }
    else
    {
        printIllegalUnitMessage();
    }

    printPrompt();
    while (cin >> number >> unit)
    {
        if (isUnitLegal(unit))
        {
            cout << "You entered: " << number << unit << endl;
            if (number < smallest)
            {
                smallest = number;
                printSmallestMessage();
            }

            if (number > largest)
            {
                largest = number;
                printLargestMessage();
            }

            ++numberOfValues;
            sum = addToSum(sum, number, unit);
            allNumbers.push_back(number);
        }
        else
        {
            printIllegalUnitMessage();
        }

        printPrompt();
    }

    printFinalMessage(allNumbers, smallest, largest, sum, numberOfValues);

    return 0;
}
