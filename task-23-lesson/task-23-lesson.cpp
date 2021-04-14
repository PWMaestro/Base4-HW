/**
 * 
 * Find words in a text app
 * 
 * */

#include <iostream>

#define N 512

using namespace std;

bool isSeparator(char character);
void showWords(char wordsArr[N][N]);
int getSeparatorsCount(char text[], int pointer);

const char separators[] = "., !:/*-";

int main()
{
    char text[N] = {0},
         words[N][N] = {0};
    int columnPointer = 0,
        rawPointer = 0;

    cout << "Input text: ";
    cin.getline(text, N);

    for (int i = 0; i < text[i] != '\0'; i++)
    {
        if (!isSeparator(text[i]))
        {
            words[rawPointer][columnPointer] = text[i];
            columnPointer++;
        }
        if (isSeparator(text[i + 1]))
        {
            i += getSeparatorsCount(text, i + 1);
            rawPointer++;
            columnPointer = 0;
        }
    }
    showWords(words);
    
    return 0;
}

int getSeparatorsCount(char text[], int pointer)
{
    int count = 1;

    for (int i = pointer + 1; text[i] != '\0'; i++)
    {
        if (isSeparator(text[i]))
        {
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
}

void showWords(char wordsArr[N][N])
{
    for (int i = 0; wordsArr[i][0] != '\0'; i++)
    {
        for (int j = 0; wordsArr[i][j] != '\0'; j++)
        {
            cout << wordsArr[i][j];
        }
        cout << endl;
    }
}

bool isSeparator(char character)
{
    for (int i = 0; i < separators[i] != '\0'; i++)
    {
        if (separators[i] == character)
        {
            return true;
        }
    }
    return false;
}