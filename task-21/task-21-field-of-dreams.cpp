/**
 * 
 * FIELD OF DREAMS =)
 * 
 * */

#include <iostream>
#include <random>
#include <ctime>

#define COUNT_WORDS 5
#define COUNT_JOKES 5
#define WORD_LENGTH 16
#define PHRASE_LENGTH 128
#define SYMBOL_HIDDEN '*'

using namespace std;

void startGame();
void showMsgWrongInput(string additionalMessage ="");

void setTextToList(char list[], int listItemSize, const char word[], int position);
void getTextFromList(char stringRecepient[], char list[], int listItemSize, int position);
void delTextFromList(char list[], int listItemSize, int position);

bool agreeYesOrNo(string message);
bool agreePlayAgain();
bool isContainSymbol(char word[], char symbol);

int getRandNumber(int start, int end);
int getWordLengthFromList(char list[], int listItemSize, int position);



char words[COUNT_WORDS * WORD_LENGTH + 1] = {0};
char jokes[COUNT_JOKES * PHRASE_LENGTH + 1] = {0};



int main()
{
    setTextToList(words, WORD_LENGTH, "potato", 0);
    setTextToList(words, WORD_LENGTH, "banana", 1);
    setTextToList(words, WORD_LENGTH, "cucumber", 2);
    setTextToList(words, WORD_LENGTH, "monkey", 3);
    setTextToList(words, WORD_LENGTH, "crocodile", 4);

    setTextToList(jokes, PHRASE_LENGTH, "Barrel is spinning - money is earning!", 0);
    setTextToList(jokes, PHRASE_LENGTH, "(Yakubovich dressed arab kandura) Sector \"explode\" on barrel! You have 3 seconds to guess the word...", 1);
    setTextToList(jokes, PHRASE_LENGTH, "Yakubovich - Yasharovich - Yapiramidovich - Yatsilindrovich.", 2);
    setTextToList(jokes, PHRASE_LENGTH, "No need to grow up cucumbers, when peoples bring them on \"Fields of Dreams\"!", 3);
    setTextToList(jokes, PHRASE_LENGTH, "Don't upset Leonid Arkadievich!", 4);

    do
    {
        startGame();
    } while (agreePlayAgain());

    return 0;
}



void startGame()
{
    char currentWord[WORD_LENGTH] = {0},
         hiddenWord[WORD_LENGTH] = {0},
         joke[PHRASE_LENGTH] = {0},
         letter = '\0';
    int wordPosition = getRandNumber(0, COUNT_WORDS - 1),
        jokePosition = getRandNumber(0, COUNT_JOKES - 1),
        length = getWordLengthFromList(words, WORD_LENGTH, wordPosition);

    getTextFromList(currentWord, words, WORD_LENGTH, wordPosition);
    getTextFromList(joke, jokes, PHRASE_LENGTH, jokePosition);

    for (int i = 0; i < length; i++)
    {
        hiddenWord[i] = SYMBOL_HIDDEN;
    }
    
    do
    {
        letter = '\0';

        system("cls");
        cout << hiddenWord << endl;
        cout << "Please, enter a letter: ";
        cin >> letter;

        if (letter < 'a' || letter > 'z')
        {
            showMsgWrongInput("You should enter lowercase letters only.");
        }
        else if (isContainSymbol(currentWord, letter))
        {
            for (int i = 0; currentWord[i] != '\0'; i++)
            {
                if (currentWord[i] == letter)
                {
                    hiddenWord[i] = letter;
                }
            }
        }
    } while (isContainSymbol(hiddenWord, SYMBOL_HIDDEN));

    system("cls");
    cout << hiddenWord << endl;
    cout << "You are winner!" << endl;
    cout << joke << endl;
}

void showMsgWrongInput(string additionalMessage/* =""*/)
{
    cout << "Wrong input! Try again..." << endl;
    cout << additionalMessage << endl;
}

void setTextToList(char list[], int listItemSize, const char word[], int position)
{
    for (int i = 0, j = position * listItemSize; i < listItemSize && word[i] != '\0'; i++, j++)
    {
        list[j] = word[i];
    }
}

void getTextFromList(char stringRecepient[], char list[], int listItemSize, int position)
{
    for (int i = 0, j = position * listItemSize; i < listItemSize && list[j] != '\0'; i++, j++)
    {
        stringRecepient[i] = list[j];
    }
}

void delTextFromList(char list[], int listItemSize, int position)
{
    for (int i = 0, j = position * listItemSize; i < listItemSize; i++, j++)
    {
        list[j] = 0;
    }
}

bool agreeYesOrNo(string message)
{
    char userInput;

    while (true)
    {
        cout << message << endl;
        cout << "Enter Y / N: ";
        cin >> userInput;

        switch (userInput)
        {
        case 'y':
            return true;
        case 'n':
            return false;
        
        default:
            showMsgWrongInput();
            break;
        }
    }
}

bool agreePlayAgain()
{
    return agreeYesOrNo("Do you want to play again?");
}

bool isContainSymbol(char word[], char symbol)
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] == symbol)
        {
            return true;
        }
    }
    return false;
}

int getRandNumber(int start, int end)
{
    mt19937 randGen(static_cast<unsigned int>(time(0))); // random number generator
    uniform_int_distribution<> dist(start, end); // range of random values

    return dist(randGen);
}

int getWordLengthFromList(char list[], int listItemSize, int position)
{
    int counter = 0;

    for (int i = 0, j = position * listItemSize; i < listItemSize && list[j] != '\0'; i++, j++)
    {
        counter++;
    }
    return counter;
}