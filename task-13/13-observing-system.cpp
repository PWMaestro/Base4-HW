#include <iostream>
#include <windows.h>

#define MAX_NUM_OF_POINTS 5

using namespace std;

void setOriginOfCoordinateSystemToTheFirstPoint(double coordinatesOfGeoProfileArr[]);
void setGeoProfileHeightsValues(double coordinatesOfGeoProfileArr[]);

void showMessageAboutVisiblePoint(int pointNumber, string additionalMessage = "");
void showMessageAboutInvisiblePoint(int pointNumber, string additionalMessage = "");


// creating console object to manipulate with output text
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);


int main()
{
    double geodeticProfilePointsHeights[MAX_NUM_OF_POINTS];

    setGeoProfileHeightsValues(geodeticProfilePointsHeights);
    setOriginOfCoordinateSystemToTheFirstPoint(geodeticProfilePointsHeights);

    showMessageAboutVisiblePoint(1, "We're stay there.");
    showMessageAboutVisiblePoint(2, "We can see it anyway.");

    // slopeRatio is about angle between horizontal X axis and a line
    // connecting point we stay with point we are looking
    double currentSlopeRatio = geodeticProfilePointsHeights[1] / 1;
    double maximumSlopeRatio = currentSlopeRatio;
    
    for (int i = 2; i < MAX_NUM_OF_POINTS; i++)
    {
        currentSlopeRatio = geodeticProfilePointsHeights[i] / i;

        if (currentSlopeRatio > maximumSlopeRatio)
        {
            maximumSlopeRatio = currentSlopeRatio;

            showMessageAboutVisiblePoint(i + 1);
        }
        else
        {
            showMessageAboutInvisiblePoint(i + 1);
        }
    }

    return 0;
}

void setGeoProfileHeightsValues(double coordinatesOfGeoProfileArr[])
{
    cout << "Please, enter heights of geodetic profile points:" << endl;

    for (int i = 0; i < MAX_NUM_OF_POINTS; i++)
    {
        cout << "Point " << i + 1 << ": ";
        cin >> coordinatesOfGeoProfileArr[i];
    }
}

void setOriginOfCoordinateSystemToTheFirstPoint(double coordinatesOfGeoProfileArr[])
{
    double firstMemberVal = coordinatesOfGeoProfileArr[0];

    for (int i = 0; i < MAX_NUM_OF_POINTS; i++)
    {
        coordinatesOfGeoProfileArr[i] -= firstMemberVal;
    }
}

void showMessageAboutVisiblePoint(int pointNumber, string additionalMessage /*= ""*/)
{
    SetConsoleTextAttribute(console, (WORD) ((0 << 4) | 2));
    cout << "Point " << pointNumber << " is visible. ";
    SetConsoleTextAttribute(console, (WORD) ((0 << 4) | 7));
    cout << additionalMessage << endl;
}

void showMessageAboutInvisiblePoint(int pointNumber, string additionalMessage /*= ""*/)
{
    SetConsoleTextAttribute(console, (WORD) ((0 << 4) | 4));
    cout << "Point " << pointNumber << " is invisible. ";
    SetConsoleTextAttribute(console, (WORD) ((0 << 4) | 7));
    cout << additionalMessage << endl;
}
