#include <iostream>
#include <cmath>

using namespace std;

double positiveExponentiation(double, int);
double negativeExponentiation(double, int);

int main()
{
    double number, result;
    int degree;

    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter a degree: ";
    cin >> degree;

    if (degree == 0) {
        cout << 1;
    } else if (degree > 0) {
        cout << positiveExponentiation(number, degree);
    } else {
        cout << negativeExponentiation(number, degree);
    }

    return 0;
}

double positiveExponentiation(double number, int degree)
{
    double result = number;
    degree = abs(degree);

    while (degree > 1)
    {
        result *= number;
        degree--;
    }
    
    return result;
}

double negativeExponentiation(double number, int degree)
{
    return 1 / positiveExponentiation(number, degree);
}
