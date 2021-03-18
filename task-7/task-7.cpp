#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main()
{
    int maxValue = 100;

    mt19937 mersenne(static_cast<unsigned int>(time(0))); // random number generator
    uniform_int_distribution<> dist(1, maxValue); // range of random values

    int secretNumber = dist(mersenne),
        inputNumber;

    do {
        cout << "Enter the nuber: ";
        cin >> inputNumber;

        if (inputNumber > secretNumber) {
            cout << "Bigger =)" << endl;
        } else {
            cout << "Smaller =)" << endl;
        }
    } while ( inputNumber != secretNumber );
    
    cout << "Hooray! You successfully guesed the number! It is " << secretNumber;
    return 0;
}