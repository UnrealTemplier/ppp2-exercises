#include "../../std_lib_facilities.h"
using namespace std;

void ex2()
{
    vector<double> sequence = {};
    cout << "Enter some numbers:\n";
    double number = 0;
    while (cin >> number)
        sequence.push_back(number);

    cout << "You numbers: ";
    for (double n : sequence)
        cout << n << " ";

    cout << endl;

    cout << "You numbers sorted: ";
    // sort(sequence);
    for (double n : sequence)
        cout << n << " ";

    cout << endl;

    if (sequence.size() % 2 == 0)
    {
        double medianNumber = (sequence[sequence.size() / 2] + sequence[sequence.size() / 2 - 1]) / 2.0;
        cout << "The median number of the sequence is: " << medianNumber << endl;
    }
    else
    {
        cout << "The median of the sequence is: " << sequence[sequence.size() / 2] << endl;
    }
}

void ex3()
{
    vector<double> distances = {};

    cout << "Enter distances between cities:\n";
    double distance = 0;
    while (cin >> distance)
        distances.push_back(distance);

    if (distances.size() == 0)
    {
        cout << "No distances entered!" << endl;
        return;
    }

    double sum = 0, smallest = distances[0], largest = distances[0], mean = 0;
    for (double d : distances)
    {
        sum += d;
        if (d < smallest) smallest = d;
        if (d > largest) largest = d;
    }

    mean = sum / distances.size();

    cout << endl;
    cout << "Total distance: " << sum << endl;
    cout << "Smallest distance: " << smallest << endl;
    cout << "Largest distance: " << largest << endl;
    cout << "Mean distance: " << mean << endl;
}

void ex4()
{
    int low = 1, high = 100, mid = (low + high) / 2;
    char ch;

    cout << "Think of a number between 1 to 100" << endl;
    while (low <= high)
    {
        mid = (low + high) / 2;

        cout << "Is the number you are thinking of less than " << mid << " ? (y/n)" << endl;
        cin >> ch;

        if (ch == 'y')
            high = mid - 1;
        else
            low = mid + 1;
    }

    cout << "The number you are thinking of is: " << high << endl;
}

void ex5()
{
    double op1 = 0, op2 = 0;
    char operation = ' ';

    cout << "Enter two operands and operation (+, -, *, /): ";
    cin >> op1 >> op2 >> operation;

    switch (operation)
    {
        case '+': cout << "The sum of " << op1 << " and " << op2 << " is " << op1 + op2 << endl; break;
        case '-': cout << "The difference of " << op1 << " and " << op2 << " is " << op1 - op2 << endl; break;
        case '*': cout << "The product of " << op1 << " and " << op2 << " is " << op1 * op2 << endl; break;
        case '/': cout << "The quotient of " << op1 << " and " << op2 << " is " << op1 / op2 << endl; break;
        default: cout << "Incorrect operation." << endl; break;
    }
}

string getSpelledNumber(int number)
{
    vector<string> spelledNumbers = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    };

    if (number < 0 || number >= spelledNumbers.size()) return "";

    return spelledNumbers[number];
}

int getDigitalNumber(string spelledNumber)
{
    vector<string> spelledNumbers = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
    };

    ptrdiff_t pos = std::distance(spelledNumbers.begin(), find(spelledNumbers, spelledNumber));
    if (pos >= spelledNumbers.size()) return -1;

    return pos;
}

void ex6()
{
    /*int number = 0;
    cout << "Enter a one-digit number: ";
    while (cin >> number)
    {
        if (number < 0 || number > 9)
            cout << "Incorrect number!" << endl;
        else
            cout << number << " : " << getSpelledNumber(number) << endl;

        cout << "Enter a one-digit number: ";
    }*/

    string spelledNumber = "";
    cout << "Enter a spelled out number (between zero and nine): ";
    while (cin >> spelledNumber)
    {
        int pos = getDigitalNumber(spelledNumber);

        if (pos == -1)
            cout << "Incorrect number!" << endl;
        else
            cout << spelledNumber << " : " << pos << endl;

        cout << "Enter a spelled out number (between zero and nine): ";
    }
}

void ex7()
{
    double op1 = 0, op2 = 0;
    string op1str = "", op2str = "";
    char operation = ' ';

    char choice = ' ';
    cout << "Digital (d) or Spelled (s)?: ";
    cin >> choice;

    if (choice != 'd' && choice != 's')
    {
        cout << "Wrong choice!\n";
        return;
    }

    if (choice == 'd')
    {
        cout << "Enter two operands and operation (+, -, *, /): ";
        cin >> op1 >> op2 >> operation;

        switch (operation)
        {
            case '+': cout << "The sum of " << op1 << " and " << op2 << " is " << op1 + op2 << endl; break;
            case '-': cout << "The difference of " << op1 << " and " << op2 << " is " << op1 - op2 << endl; break;
            case '*': cout << "The product of " << op1 << " and " << op2 << " is " << op1 * op2 << endl; break;
            case '/': cout << "The quotient of " << op1 << " and " << op2 << " is " << op1 / op2 << endl; break;
            default: cout << "Incorrect operation." << endl; break;
        }
    }
    else
    {
        cout << "Enter two operands (one-digit only in spelled form) and operation (+, -, *, /): ";
        cin >> op1str >> op2str >> operation;

        double op1 = getDigitalNumber(op1str);
        double op2 = getDigitalNumber(op2str);

        if (op1 == -1 || op2 == -1)
        {
            cout << "Wrong numbers!\n";
            return;
        }

        switch (operation)
        {
            case '+': cout << "The sum of " << op1 << " and " << op2 << " is " << op1 + op2 << endl; break;
            case '-': cout << "The difference of " << op1 << " and " << op2 << " is " << op1 - op2 << endl; break;
            case '*': cout << "The product of " << op1 << " and " << op2 << " is " << op1 * op2 << endl; break;
            case '/': cout << "The quotient of " << op1 << " and " << op2 << " is " << op1 / op2 << endl; break;
            default: cout << "Incorrect operation." << endl; break;
        }
    }
}

void ex8()
{
    constexpr int leastGrainsAmount = 1000000000;

    cout << "Calculating how much squares we need to get at least " << leastGrainsAmount << " grains of rice...\n\n";

    int squares = 1;
    int grainsSum = 1;

    cout << "On the first square we get 1 grain\n\n";

    while (grainsSum < leastGrainsAmount)
    {
        cout << "Previous sum: " << grainsSum << endl;
        ++squares;
        int toAdd = grainsSum * 2;
        grainsSum += toAdd;

        cout << "Current square: " << squares << endl;
        cout << "Adding " << toAdd << " on this square\n";
        cout << "Current sum: " << grainsSum << endl;
        cout << endl;
    }

    cout << "We need at least " << squares << " squares to get " << leastGrainsAmount << " grains.\n";
}

void ex9()
{
    int intSum = 1;
    for (int i = 2; i <= 64; ++i)
    {
        intSum += intSum * 2;
        cout << "Square " << i << ". Sum is " << intSum << "\n";

        if (intSum < 0)
        {
            cout << "We can calculate with int up to " << i - 1 << " square inclusive.\n";
            break;
        }
    }

    double doubleSum = 1;
    for (int i = 2; i <= 64; ++i)
    {
        doubleSum += doubleSum * 2;
        cout << "Square " << i << ". Sum is " << doubleSum << "\n";

        /* if (doubleSum < 0)
        {
            cout << "We can calculate with int up to " << i - 1 << " square inclusive.\n";
            break;
        }*/
    }

    cout << "Final sum is " << doubleSum << "\n";
}

char getComputerTurn(int offset)
{
    vector<char> turnsCollection = {'r', 'p', 's', 'p', 'r', 's', 's', 'p', 'r', 'p', 'r', 'r'};

    int index = offset;
    if (index >= turnsCollection.size()) index = index % turnsCollection.size();
    return turnsCollection[index];
}

void ex10()
{
    cout << "Rock, paper, scissors!\n";

    constexpr int maxWins = 3;
    int aiWins = 0, playerWins = 0;

    int offset = 0;
    while (true)
    {
        cout << "Enter a number from 0 to 10: ";
        if (cin >> offset)
        {
            if (offset < 0) offset = 0;
            break;
        }
    }

    while (true)
    {
        char playerTurn = 0;
        cout << "Your turn (r, p or s): ";
        cin >> playerTurn;

        if (playerTurn == 'r' || playerTurn == 'p' || playerTurn == 's')
        {
            char aiTurn = getComputerTurn(offset++);
            cout << "Computer turn: " << aiTurn << "\n";

            switch (playerTurn)
            {
                case 'r':
                    if (aiTurn == 's')
                    {
                        ++playerWins;
                        cout << "You won this round.\n";
                    }
                    else if (aiTurn == 'p')
                    {
                        ++aiWins;
                        cout << "Computer won this round.\n";
                    }
                    else
                    {
                        cout << "Spare.\n";
                    }
                    break;
                case 'p':
                    if (aiTurn == 'r')
                    {
                        ++playerWins;
                        cout << "You won this round.\n";
                    }
                    else if (aiTurn == 's')
                    {
                        ++aiWins;
                        cout << "Computer won this round.\n";
                    }
                    else
                    {
                        cout << "Spare.\n";
                    }
                    break;
                case 's':
                    if (aiTurn == 'p')
                    {
                        ++playerWins;
                        cout << "You won this round.\n";
                    }
                    else if (aiTurn == 'r')
                    {
                        ++aiWins;
                        cout << "Computer won this round.\n";
                    }
                    else
                    {
                        cout << "Spare.\n";
                    }
                    break;
                default: break;
            }

            if (playerWins >= maxWins)
            {
                cout << "\nYou win this game!\n";
                return;
            }
            else if (aiWins >= maxWins)
            {
                cout << "\nComputer wins this game!\n";
                return;
            }
        }
        else
        {
            cout << "Wrong choice!\n";
        }
    }
}

bool isPrime(int n)
{
    if (n <= 1) return false;

    for (int i = 2; i <= n / 2; ++i)
        if (n % i == 0) return false;

    return true;
}

void SieveOfEratosthenes(int max)
{
    vector<char> numbers;
    for (int p = 0; p <= max; p++)
        numbers.push_back(1);

    for (int p = 2; p * p <= max; p++)
    {
        if (numbers[p] == 1)
        {
            for (int i = p * p; i <= max; i += p)
                numbers[i] = 0;
        }
    }

    for (int p = 2; p <= max; p++)
        if (numbers[p] == 1) cout << p << " ";
}

void ex11()
{
    int max = 100;

    cout << "All prime numbers from 1 to " << max << ":\n";

    vector<int> foundPrimes;

    for (int i = 0; i <= max; ++i)
        if (isPrime(i)) foundPrimes.push_back(i);

    for (int prime : foundPrimes)
        cout << prime << " ";

    cout << "\n";
}

void ex12()
{
    int max = 0;
    cout << "Enter max number: ";
    cin >> max;

    cout << "All prime numbers from 1 to " << max << ":\n";

    vector<int> foundPrimes;

    for (int i = 0; i <= max; ++i)
        if (isPrime(i)) foundPrimes.push_back(i);

    for (int prime : foundPrimes)
        cout << prime << " ";

    cout << "\n";
}

void ex13()
{
    int max = 100;

    cout << "Sieve of Eratosthenes\n";
    cout << "All prime numbers from 1 to " << max << ":\n";

    SieveOfEratosthenes(max);

    cout << "\n";
}

void ex14()
{
    int max = 0;
    cout << "Enter max number: ";
    cin >> max;

    cout << "Sieve of Eratosthenes\n";
    cout << "All prime numbers from 1 to " << max << ":\n";

    SieveOfEratosthenes(max);

    cout << "\n";
}

void ex15()
{
    cout << "How much first prime numbers do you want: ";
    int n = 0;
    cin >> n;

    cout << n << " first prime numbers:\n";

    vector<int> foundPrimes;
    int i = 0;
    int found = 0;
    while (found < n)
    {
        if (isPrime(i))
        {
            foundPrimes.push_back(i);
            found++;
        }

        i++;
    }

    for (int prime : foundPrimes)
        cout << prime << " ";

    cout << "\n";
}

void ex16()
{
    int n = 10;

    cout << "Enter " << n << " numbers: ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        int num = 0;
        cin >> num;
        nums[i] = num;
    }

    cout << "Your numbers: ";
    for (int num : nums)
        cout << num << " ";
    cout << "\n";

    int mode;
    int modeCount = 0;
    vector<int> alreadyCounted{};
    for (int i = 0; i < n; i++)
    {
        int current = nums[i];

        if (find(alreadyCounted, current) != alreadyCounted.end()) continue;

        int currentCount = 1;
        for (int j = i + 1; j < n; j++)
            if (nums[j] == current) currentCount++;

        if (currentCount > modeCount)
        {
            mode = current;
            modeCount = currentCount;
        }

        alreadyCounted.push_back(current);
    }

    cout << "Mode of the sequence: " << mode << "\n";

    cout << "\n";
}

void ex17()
{
    vector<string> strs = {"one", "tw", "a", "four", "tw", "large", "tw", "large+"};

    int minLength = strs[0].length();
    int maxLength = strs[0].length();
    int modeCount = 0;
    string minString = strs[0];
    string maxString = strs[0];
    string mode = strs[0];

    cout << "String sequence:\n";
    for (string s : strs)
    {
        cout << s << " ";
        if (s.length() < minLength)
        {
            minLength = s.length();
            minString = s;
        }
        if (s.length() > maxLength)
        {
            maxLength = s.length();
            maxString = s;
        }
    }

    int n = strs.size();
    vector<string> alreadyCounted{};
    for (int i = 0; i < n; i++)
    {
        string current = strs[i];

        if (find(alreadyCounted, current) != alreadyCounted.end()) continue;

        int currentCount = 1;
        for (int j = i + 1; j < n; j++)
            if (strs[j] == current) currentCount++;

        if (currentCount > modeCount)
        {
            mode = current;
            modeCount = currentCount;
        }

        alreadyCounted.push_back(current);
    }

    cout << "\n";

    cout << "Min-length string: " << minString << "\n";
    cout << "Max-length string: " << maxString << "\n";
    cout << "Mode string: " << mode << "\n";
}

void ex18()
{
    double a = 0, b = 0, c = 0;
    cout << "Enter a, b and c: ";
    cin >> a >> b >> c;

    if (a == 0)
    {
        cout << "Error! a is zero!\n";
        return;
    }

    double lowPart = 2 * a;
    double underRoot = b * b - 4 * a * c;
    if (underRoot < 0)
    {
        cout << "Equation is unsolvable. Under the square root is negative number.\n";
        return;
    }
    double squareRoot = sqrt(underRoot);

    double x1 = (-b - squareRoot) / lowPart;
    double x2 = (-b + squareRoot) / lowPart;

    cout << "x1 = " << x1 << "\n";
    cout << "x2 = " << x2 << "\n";
}

void ex19()
{
    vector<string> names;
    vector<int> scores;

    while (true)
    {
        string name = " ";
        int score = 0;
        cout << "Enter a pair Name Score (NoName 0 to finish): ";
        cin >> name >> score;

        if (cin)
        {
            if (name == "NoName" && score == 0) break;

            bool twice = false;
            for (string n : names)
                if (n == name)
                {
                    cout << "You entered this name twice!\n";
                    twice = true;
                    break;
                }

            if (twice) continue;

            names.push_back(name);
            scores.push_back(score);
        }
        else
        {
            cin.clear();
        }
    }

    if (names.size() != scores.size())
    {
        error("Arrays sizes mismatch!");
        return;
    }

    cout << "\n";
    cout << "You entered:\n";
    for (int i = 0; i < names.size(); i++)
        cout << names[i] << " " << scores[i] << "\n";
}

void ex20()
{
    vector<string> names;
    vector<int> scores;

    while (true)
    {
        string name = " ";
        int score = 0;
        cout << "Enter a pair Name Score (NoName 0 to finish): ";
        cin >> name >> score;

        if (cin)
        {
            if (name == "NoName" && score == 0) break;

            bool twice = false;
            for (string n : names)
                if (n == name)
                {
                    cout << "You entered this name twice!\n";
                    twice = true;
                    break;
                }

            if (twice) continue;

            names.push_back(name);
            scores.push_back(score);
        }
        else
        {
            cin.clear();
        }
    }

    if (names.size() != scores.size())
    {
        error("Arrays sizes mismatch!");
        return;
    }

    cout << "\n";
    cout << "You entered:\n";
    for (int i = 0; i < names.size(); i++)
        cout << names[i] << " " << scores[i] << "\n";

    while (true)
    {
        cout << "\n";
        cout << "Enter a name (0 to finish): ";
        string name = " ";
        cin >> name;

        if (name.empty()) continue;

        if (name == "0") break;

        bool nameFound = false;
        for (int i = 0; i < names.size(); i++)
            if (names[i] == name)
            {
                nameFound = true;
                cout << scores[i] << "\n";
                break;
            }

        if (!nameFound) cout << "Name not found.\n";
    }
}

void ex21()
{
    vector<string> names;
    vector<int> scores;

    while (true)
    {
        string name = " ";
        int score = 0;
        cout << "Enter a pair Name Score (NoName 0 to finish): ";
        cin >> name >> score;

        if (cin)
        {
            if (name == "NoName" && score == 0) break;

            bool twice = false;
            for (string n : names)
                if (n == name)
                {
                    cout << "You entered this name twice!\n";
                    twice = true;
                    break;
                }

            if (twice) continue;

            names.push_back(name);
            scores.push_back(score);
        }
        else
        {
            cin.clear();
        }
    }

    if (names.size() != scores.size())
    {
        error("Arrays sizes mismatch!");
        return;
    }

    cout << "\n";
    cout << "You entered:\n";
    for (int i = 0; i < names.size(); i++)
        cout << names[i] << " " << scores[i] << "\n";

    while (true)
    {
        cout << "\n";
        cout << "Enter a score (-1 to finish): ";
        int score = -1;
        cin >> score;

        if (score == -1) break;

        bool scoreFound = false;
        for (int i = 0; i < scores.size(); i++)
            if (scores[i] == score)
            {
                scoreFound = true;
                cout << names[i] << "\n";
            }

        if (!scoreFound) cout << "Score not found.\n";
    }
}

int main()
{
    // ex2();
    // ex3();
    // ex4();
    // ex5();
    // ex6();
    // ex7();
    // ex8();
    // ex9();
    // ex10();
    // ex11();
    // ex12();
    // ex13();
    // ex14();
    // ex15();
    // ex16();
    // ex17();
    // ex18();
    // ex19();
    // ex20();
    ex21();

    return 0;
}
