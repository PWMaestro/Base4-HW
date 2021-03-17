#include <iostream>

using namespace std;

int getSummOfNumeralsFromNumber(int number);

int main()
{
    int birthDay,
        birthMonth,
        birthYear;
    
    cout << "Enter a birth day: ";
    cin >> birthDay;
    cout << "Enter a birth month: ";
    cin >> birthMonth;
    cout << "Enter a birth year: ";
    cin >> birthYear;

    cout << getSummOfNumeralsFromNumber(
        getSummOfNumeralsFromNumber(birthDay) +
        getSummOfNumeralsFromNumber(birthMonth) +
        getSummOfNumeralsFromNumber(birthYear)
    );

    return 0;
}

int getSummOfNumeralsFromNumber(int number)
{
    int result = 0;

    while (number > 0) {
        result += number % 10;
        number /= 10;
    }
    
    return result;
}