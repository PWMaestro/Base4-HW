#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;

    cout << "Enter the first side of triangle: ";
    cin >> a;
    cout << "Enter the second side of triangle: ";
    cin >> b;
    cout << "Enter the third side of triangle: ";
    cin >> c;

    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "Error! Wrong input!";
        return 1;
    }

    int max = a;

    if (max < b) {
        max = b;
    }
    if (max < c) {
        max = c;
    }

    if (a == b && b == c) {
        cout << "Equilateral triangle" << endl;
    } else if (a == b || b == c || a == c) {
        cout << "Isosceles triangle." << endl;
    } else if ( ( a == max && ( pow(a, 2) == (pow(b, 2) + pow(c, 2)) )) or
                ( b == max && ( pow(b, 2) == (pow(a, 2) + pow(c, 2)) )) or
                ( c == max && ( pow(c, 2) == (pow(b, 2) + pow(a, 2)) )) ) {
        cout << "Right triangle." << endl;
    } else {
        cout << "General triangle." << endl;
    }
    
    return 0;
}