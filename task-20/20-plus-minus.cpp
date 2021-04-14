/**
 * 
 * PLUS-MINUS
 * 
 **/

#include <iostream>

#define CASE_SYMBOL_EVEN '+'
#define CASE_SYMBOL_ODD '-'
#define STR_LENGTH 1024

using namespace std;

void replaceNumeralsWithPlusOrMinus(char string[], int pointer, int numeralValue);
void insertSymbol(char string[], char symbol, int startPosition, int insertionsCount = 1);
void copyString(char stringRecepient[], char stringDonor[], int startPosition);
void copySubstring(char stringRecepient[], char stringDonor[], int startPosition, int length = 0);
void deleteSubstring(char string[], int position, int length);

bool isNumeral(char character);
bool isOdd(int numeral);

int charToInt(char character);



int main()
{
    char string[STR_LENGTH] = {0};

    cout << "Please, enter some symbols:" << endl;
    cin.getline(string, STR_LENGTH, '\n');

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (isNumeral(string[i]))
        {
            int value = charToInt(string[i]);
            replaceNumeralsWithPlusOrMinus(string, i, value);
            i +=value - 1;
        }
    }
    cout << string;
    return 0;
}

int charToInt(char character)
{
    return character - '0';
}

bool isNumeral(char character)
{
    return character >= '0' && character <= '9';
}

bool isOdd(int numeral)
{
    return numeral % 2;
}

void replaceNumeralsWithPlusOrMinus(char string[], int pointer, int numeralValue)
{
    if (numeralValue == 0)
    {
        deleteSubstring(string, pointer, 1);
    }
    else
    {
        isOdd(numeralValue)
        ? insertSymbol(string, CASE_SYMBOL_ODD, pointer, numeralValue)
        : insertSymbol(string, CASE_SYMBOL_EVEN, pointer, numeralValue);
    }
}

void insertSymbol(char string[], char symbol, int startPosition, int insertionsCount/* = 1 */)
{
    char tempString[STR_LENGTH - startPosition] = {0};
    int shift = startPosition + insertionsCount;

    copySubstring(tempString, string, startPosition + 1);
    for (int i = 0, j = startPosition; i < insertionsCount; i++, j++)
    {
        string[j] = symbol;
    }
    copyString(string, tempString, shift);
}

void deleteSubstring(char string[], int position, int length)
{
    int shift = position + length;
    char tempString[STR_LENGTH - shift] = {0};

    copySubstring(tempString, string, shift);
    for (int i = position; string[i] != '\0'; i++)
    {
        string[i] = 0;
    }
    copyString(string, tempString, position);
}

void copyString(char stringRecepient[], char stringDonor[], int startPosition)
{
    for (int i = 0, j = startPosition; stringDonor[i] != '\0'; i++, j++)
    {
        stringRecepient[j] = stringDonor[i];
    }
}

void copySubstring(char stringRecepient[], char stringDonor[], int startPosition, int length/* = 0*/)
{
    if (length == 0)
    {
        for (int i = 0, j = startPosition; stringDonor[j] != '\0'; i++, j++)
        {
            stringRecepient[i] = stringDonor[j];
        }
    }
    else
    {
        for (int i = 0, j = startPosition; i < length; i++, j++)
        {
            stringRecepient[i] = stringDonor[j];
        }
    }
}
