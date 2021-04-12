#include <iostream>

using namespace std;

void startGame();
void showMsgWrongInput(string additionalMessage ="");

bool agreeYesOrNo(string message);
bool agreePlayAgain();

int main()
{
    do
    {
        startGame();
    } while (agreePlayAgain());

    return 0;
}



void startGame()
{
    cout << "Game is running..." << endl;
}

void showMsgWrongInput(string additionalMessage/* =""*/)
{
    cout << "Wrong input! Try again..." << endl;
    cout << additionalMessage << endl;
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
