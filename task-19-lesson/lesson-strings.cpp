#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool isNumber(char string[]);
bool isLatter(char character);
bool isWord(char character[]);

int strLen(char string[]);
int strCmp(char stringFirst[], char stringSecond[]);
int strToInt(char string[]);

void strCpy(char stringRecepient[], char stringDonor[]);



int main()
{
    char userString[128];

    cout << "Please, enter something: ";
    cin >> userString;

    cout << strToInt(userString);

    return 0;
}



int digitToNumber(char character)
{
    return character - '0';
}

int strLen(char string[])
{
    int counter = 0;

    for (int i = 0; i < string[i] != '\0'; i++)
    {
        counter++;
    }
    return counter;
}

void strCpy(char stringRecepient[], char stringDonor[])
{
    for (int i = 0; i < stringRecepient[i] != '\0'; i++)
    {
        stringRecepient[i] = 0;
    }

    for (int i = 0; i < stringDonor[i] != '\0'; i++)
    {
        stringRecepient[i] = stringDonor[i];
    }
}

int strCmp(char stringFirst[], char stringSecond[])
{
    int lengthFirst = strLen(stringFirst);
    int lengthSecond = strLen(stringSecond);
    int maxLength = lengthSecond;

    if ( lengthFirst > lengthSecond )
    {
        maxLength  = lengthFirst;
    }

    for (int i = 0; i < maxLength; i++)
    {
        if ( stringFirst[i] > stringSecond[i] )
        {
            return 1;
        }
        else if ( stringFirst[i] < stringSecond[i] )
        {
            return -1;
        }
    }
    return 0;
}

bool isLatter(char character)
{
    if (character >= 'A' && character <= 'Z' || character >= 'a' && character <= 'z' )
    {
        return true;
    }
    return false;
}

bool isWord(char character[])
{
    for (int i = 0; i < character[i] != '\0'; i++)
    {
        if ( !isLatter(character[i]) )
        {
            return false;
        }
    }
    return true;
}

bool isDigit(char character)
{
    if (character >= '0' and character <= '9')
    {
        return true;
    }
    return false;
}

bool isNumber(char string[])
{
    for (int i = 0; i < string[i] != '\0'; i++)
    {
        if (string[i] <= '0' or string[i] >= '9')
        {
            return false;
        }
    }
    return true;
}

int strToInt(char string[])
{
    int length = strLen(string);
    int numeral;
    double result = 0;

    for (int i = 0; i < length; i++)
    {
        numeral  = string[i] - '0';
        result += numeral * pow(10, length - i - 1);
    }
    return result;
}
