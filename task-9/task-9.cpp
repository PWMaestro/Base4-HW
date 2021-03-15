#include <iostream>

using namespace std;

double calculateNextRawMember(double currentRawMember);

int main()
{
    double maxValue, currentValue = 1.0;

    cout << "Enter a maximum member: ";
    cin >> maxValue;

    if (maxValue <= 0) {
        cout << "Error! Incorrect input. The number must be greater than zero.";
        return 1;
    } else {
        cout << "Calculated numbers:" << endl;
        do {
            cout << currentValue << endl;
            currentValue = calculateNextRawMember(currentValue);
        } while (currentValue <= maxValue);   
    }

    return 0;
}

double calculateNextRawMember(double currentRawMember)
{
    return currentRawMember * 2 + 1;
}