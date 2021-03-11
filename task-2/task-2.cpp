#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    int playgroundDimensionX = 8,
        playgroundDimensionY = 8,
        knigthCoordinatesX[2],
        knigthCoordinatesY[2];

    cout << "Enter the coordinates:" << endl;
    cout << "Coordinate X of first knight: ";
    cin >> knigthCoordinatesX[0];
    cout << "Coordinate Y of first knight: ";
    cin >> knigthCoordinatesY[0];
    cout << "Coordinate X of second knight: ";
    cin >> knigthCoordinatesX[1];
    cout << "Coordinate Y of second knight: ";
    cin >> knigthCoordinatesY[1];

    for (int i = 0; i < 2; i++) {
        if ( knigthCoordinatesX[i] < 1 || knigthCoordinatesX[i] > 8 || knigthCoordinatesY[i] < 1 || knigthCoordinatesY[i] > 8 ) {
            cout << "Error! Wrong coordinates!";
            return 1;
        }
    } 

    if (( abs(knigthCoordinatesX[0] - knigthCoordinatesX[1]) == 2 && abs(knigthCoordinatesY[0] - knigthCoordinatesY[1]) == 1 ) ||
        ( abs(knigthCoordinatesX[0] - knigthCoordinatesX[1]) == 1 && abs(knigthCoordinatesY[0] - knigthCoordinatesY[1]) == 2 )) {
        cout << "Knights beat each other." << endl;
    } else {
        cout << "Knights don't beat each other." << endl;
    }
    
    return 0;
}