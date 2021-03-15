#include <iostream>
#include <cmath>

using namespace std;

double positiveExponentiation(double number, int degree);
double negativeExponentiation(double number, int degree);

int main()
{
    double number, result;
    int power;

    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter a power: ";
    cin >> power;

    if (power == 0) {
        cout << 1;
    } else if (power > 0) {
        cout << positiveExponentiation(number, power);
    } else {
        cout << negativeExponentiation(number, power);
    }

    return 0;
}

double positiveExponentiation(double number, int power)
{
    double result = number;
    power = abs(power);

    while (power > 1) {
        result *= number;
        power--;
    }
    
    return result;
}

double negativeExponentiation(double number, int power)
{
    return 1 / positiveExponentiation(number, power);
}
