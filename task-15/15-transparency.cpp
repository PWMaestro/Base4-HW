#include <iostream>
#include <windows.h>

#define FIG_WIDTH 3
#define FIG_LENGTH 3
#define FIG_HEIGHT 3

using namespace std;

bool isTransparencyByLengthExist();
bool isTransparencyByHeightExist();
bool isTransparencyByWidthExist();

void showTransparencyFoundMessage(string axisDirection);
void showNoTransparencyMessage();

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // creating console object to manipulate with output text

int parallelepiped[FIG_WIDTH][FIG_LENGTH][FIG_HEIGHT] = {
    {
    // height ----------> 
        { 1, 0, 1 }, // | length
        { 1, 0, 1 }, // |
        { 1, 0, 1 }  // v
    },
    {
        { 1, 1, 1 }, // |
        { 1, 1, 1 }, // |---> This hole block is a profile of width
        { 1, 1, 1 }  // |
    },
    {
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 }
    }
};

int main()
{
    if ( isTransparencyByLengthExist() )
    {
        showTransparencyFoundMessage("by length");
    }
    else if ( isTransparencyByHeightExist() )
    {
        showTransparencyFoundMessage("by height");
    }
    else if ( isTransparencyByWidthExist() )
    {
        showTransparencyFoundMessage("by width");
    }
    else
    {
        showNoTransparencyMessage();
    }
    
    return 0;
}

bool isTransparencyByHeightExist()
{
    for (int i = 0; i < FIG_WIDTH; i++)
    {
        for (int j = 0; j < FIG_LENGTH; j++)
        {
            int opacityByHeight = 0;

            for (int k = 0; k < FIG_HEIGHT; k++)
            {
                opacityByHeight += parallelepiped[i][j][k];
            }

            if (opacityByHeight == 0)
            {
                return true;
            }
        }
    }
    
    return false;
}

bool isTransparencyByLengthExist()
{
    for (int i = 0; i < FIG_HEIGHT; i++)
    {
        for (int j = 0; j < FIG_WIDTH; j++)
        {
            int opacityByLength = 0;

            for (int k = 0; k < FIG_LENGTH; k++)
            {
                opacityByLength += parallelepiped[j][k][i];
            }

            if (opacityByLength == 0)
            {
                return true;
            }
        }
    }
    
    return false;
}

bool isTransparencyByWidthExist()
{
    for (int i = 0; i < FIG_LENGTH; i++)
    {
        for (int j = 0; j < FIG_HEIGHT; j++)
        {
            int opacityByWidth = 0;

            for (int k = 0; k < FIG_WIDTH; k++)
            {
                opacityByWidth += parallelepiped[k][i][j];
            }

            if (opacityByWidth == 0)
            {
                return true;
            }
        }
    }
    
    return false;
}

void showTransparencyFoundMessage(string axisDirection)
{
    SetConsoleTextAttribute(console, (WORD) ((0 << 4) | 2)); // set green color to output text
    cout << "Hooray! Transparent hole exists " << axisDirection << "!" << endl;
    SetConsoleTextAttribute(console, (WORD) ((0 << 4) | 7)); // set default color to output text
}

void showNoTransparencyMessage()
{
    SetConsoleTextAttribute(console, (WORD) ((0 << 4) | 4)); // set red color to output text
    cout << "Whoa! There is no transparent hole in that figure!" << endl;
    SetConsoleTextAttribute(console, (WORD) ((0 << 4) | 7)); // set default color to output text
}