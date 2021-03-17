#include <iostream>
#include <cmath>

using namespace std;

int calculateIntegerLength(int integer);
int fromArrayToInt(int array[], int arrLength);
void fromIntToArray(int integer, int array[], int arrLength);
void reverseArray(int array[], int arrLength);

int main()
{
    int integer;
    
    cout << "Enter some integer: ";
    cin >> integer;

    int integerLength = calculateIntegerLength(integer);
    int integerNumerals[integerLength];

    fromIntToArray(integer, integerNumerals, integerLength);
    reverseArray(integerNumerals, integerLength);

    cout << fromArrayToInt(integerNumerals, integerLength);
    
    return 0;
}

int calculateIntegerLength(int integer)
{
    int length = 0;

    while (integer > 0) {
        length++;
        integer /= 10;
    }
    
    return length;
}

int fromArrayToInt(int array[], int arrLength)
{
    double result = 0.0;

    for (int i = 0; i < arrLength; i++) {
        result += array[i] * pow(10, arrLength - 1 - i);
    }
    
    return (int)result;
}

void fromIntToArray(int integer, int array[], int arrLength)
{
    for (int i = arrLength - 1; i >= 0; i--) {
        array[i] = integer % 10;
        integer /= 10;
    }
    
}

void reverseArray(int array[], int arrLength)
{
    int arrayCopy[arrLength];

    for (int i = 0; i < arrLength; i++) {
        arrayCopy[i] = array[i];
    }
    for (int i = 0; i < arrLength; i++) {
        array[i] = arrayCopy[arrLength - 1 - i];
    }
    
}
