#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    cout << "Enter the coordinates:" << endl;
    cout << "Coordinate X of first knight: ";
    cin >> x1;
    cout << "Coordinate Y of first knight: ";
    cin >> y1;
    cout << "Coordinate X of second knight: ";
    cin >> x2;
    cout << "Coordinate Y of second knight: ";
    cin >> y2;

    if ( x1 > 8 || x2 > 8 || y1 > 8 || y2 > 8 || x1 < 1 || x2 < 1 || y1 < 1 || y2 < 1) {
        cout << "Error! Wrong coordinates!";
        return 1;
    } else if (( abs(x1 - x2) == 2 && abs(y1 - y2) == 1 ) || ( abs(x1 - x2) == 1 && abs(y1 - y2) == 2 )) {
        cout << "Knights beat each other." << endl;
    } else {
        cout << "Knights don't beat each other." << endl;
    }
    
    return 0;
}