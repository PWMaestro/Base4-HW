#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int numberA = 0, numberB = 0;

    cout << "Enter first number: ";
    cin >> numberA;
    cout << "Enter second number: ";
    cin >> numberB;

    if (numberA > 0 && numberB > 0) {
        int remainder, max = numberA, min = numberB;

        if (numberB > numberA) {
            max = numberB;
            min = numberA;
        }

        do {
            remainder = max % min;
            max = min;
            min = remainder;
        } while (remainder > 0);

        cout << "Least common deviser: " << numberA * numberB / max << endl;
        
    } else {
        cout << "Error! Wrong number!";
        return 1;
    }
    
    return 0;
}