#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int sideA, sideB, sideC;

    cout << "Enter the first side of triangle: ";
    cin >> sideA;
    cout << "Enter the second side of triangle: ";
    cin >> sideB;
    cout << "Enter the third side of triangle: ";
    cin >> sideC;

    if (sideA <= 0 || sideB <= 0 || sideC <= 0) {
        cout << "Error! Wrong input!";
        return 1;
    }

    int sideMax = sideA;

    if (sideMax < sideB) {
        sideMax = sideB;
    }
    if (sideMax < sideC) {
        sideMax = sideC;
    }

    if (sideA == sideB && sideB == sideC) {
        cout << "Equilateral triangle" << endl;
    } else if (sideA == sideB || sideB == sideC || sideA == sideC) {
        cout << "Isosceles triangle." << endl;
    } else if ( ( sideA == sideMax && ( pow(sideA, 2) == (pow(sideB, 2) + pow(sideC, 2)) )) or
                ( sideB == sideMax && ( pow(sideB, 2) == (pow(sideA, 2) + pow(sideC, 2)) )) or
                ( sideC == sideMax && ( pow(sideC, 2) == (pow(sideB, 2) + pow(sideA, 2)) )) ) {
        cout << "Right triangle." << endl;
    } else {
        cout << "General triangle." << endl;
    }
    
    return 0;
}