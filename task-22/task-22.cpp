/**
 * 
 * Shtirlitz & Muller encryption
 * 
 * */

#include <iostream>
#include <cmath>

#define STR_LENGTH 256
#define MIN_MATRIX_SIZE 2
#define EMPTY_SPACE_SYMBOL ' '

using namespace std;

void normalizeStringLength(char string[], int normalizedLength, char filling);
int getStringLength(char string[]);
int getMatrixDimensions(int wordLength);

int main()
{
    char string[STR_LENGTH] = {0};

    cout << "Please, enter a string: ";
    cin.getline(string, STR_LENGTH);

    int length = getStringLength(string),
        matrixSize = getMatrixDimensions(length),
        matrixArea = matrixSize * matrixSize;
    char encryption[matrixSize][matrixSize];

    // zero all array
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            encryption[i][j] = 0;
        }
    }

    int center = (matrixSize / 2) - 1,
        rawPointer = center,
        columnPointer = center,
        letterPointer = 0,
        stepLength = 0,
        steps = 0;

    normalizeStringLength(string, matrixArea, EMPTY_SPACE_SYMBOL);

    encryption[rawPointer][columnPointer] = string[letterPointer++];
    steps++;

    while(steps < matrixArea) // Start spiral writing
    {
        for (int i = 0; i < stepLength; i++) // move left
        {
            encryption[rawPointer][--columnPointer] = string[letterPointer++];
            steps++;
        }
        stepLength++;
        for (int i = 0; i < stepLength; i++) // move down
        {
            encryption[++rawPointer][columnPointer] = string[letterPointer++];
            steps++;
        }
        for (int i = 0; i < stepLength; i++) // move right
        {
            encryption[rawPointer][++columnPointer] = string[letterPointer++];
            steps++;
        }
        for (int i = 0; i < stepLength; i++) // move up
        {
            encryption[--rawPointer][columnPointer] = string[letterPointer++];
            steps++;
        }
        if (steps < matrixArea) // move up one more time
        {
            encryption[--rawPointer][columnPointer] = string[letterPointer++];
            stepLength++;
            steps++;
        }
        else
        {
            break;
        }
    }
    
    // show matrix
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            cout << encryption[i][j];
            // if (matrixSize - j > 1) // FOR TESTING
            //     cout << '.';
        }
        cout << endl;
    }
    return 0;
}

void normalizeStringLength(char string[], int normalizedLength, char filling)
{
    int length = getStringLength(string),
        delta = normalizedLength - 1 - length;

    if (delta > 0)
    {
        for (int i = 0; i < delta; i++)
        {
            string[length + i] = filling;
        }
    }
}

int getStringLength(char string[])
{
    int counter = 0;

    for (int i = 0; i < string[i] != '\0'; i++)
    {
        counter++;
    }
    return counter;
}

int getMatrixDimensions(int wordLength)
{
    int size = MIN_MATRIX_SIZE;

    while (wordLength > (size * size))
    {
        size += MIN_MATRIX_SIZE;
    }
    return size;
}