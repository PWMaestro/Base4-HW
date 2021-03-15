#include <iostream>

using namespace std;

int main()
{
    double max, currentValue = 1.0;

    cout << "Enter a maximum number: ";
    cin >> max;

    if (max <= 0) {
        cout << "Error! Incorrect input. The number must be greater than zero.";
        return 1;
    } else {
        cout << "Calculated numbers:" << endl;
        do {
            cout << currentValue << endl;
            currentValue = 2 * currentValue + 1;
        } while (currentValue <= max);   
    }

    return 0;
}
