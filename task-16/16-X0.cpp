/**
 * TIC-TAC-TOE GAME
 * 
 * */

#include <iostream>
#include <windows.h>
#include <thread>
#include <random>
#include <ctime>

#define BOARD_DIMENSIONS 3
#define CELL_EMPTY ' '
#define USER_SYMBOL_X 'X'
#define USER_SYMBOL_O 'O'

using namespace std;



void showMsgWin();
void showMsgLose();

void renderBoard();
void clearBoard();

void showMsgWrongInput(string additionalMessage = "");

void startGame();
void makeMove(int raw, int column);
void toggleActivePlayer(int &activePlayerNumber);

bool isWinner();
bool isAvaliableCell(int raw, int column);
bool doesRawWin(int columnNumber);
bool doesColumnWin(int rawNumber);

bool agreePlayAgain();
bool agreeMoveFirst();
bool agreeYesOrNo(string message);

int generateRandomNumberFormRange(int rangeStart, int rangeEnd);



HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // creating console object to manipulate with output text

char board[3][3];
char userChar;
const char playerSymbols[] = { USER_SYMBOL_X, USER_SYMBOL_O };

int activePlayerNumber = 0;



int main()
{
    do
    {
        agreeMoveFirst();
        startGame();
    } while (agreePlayAgain());

    return 0;
}

void clearBoard()
{
    for (int i = 0; i < BOARD_DIMENSIONS; i++)
    {
        for (int j = 0; j < BOARD_DIMENSIONS; j++)
        {
            board[i][j] = CELL_EMPTY;
        }
    }
}

void renderBoard()
{
    for (int i = 0; i < BOARD_DIMENSIONS; i++)
    {
        for (int j = 0; j < BOARD_DIMENSIONS; j++)
        {
            cout << "[ " << board[i][j] << " ] ";
        }
        cout << endl;
    }
    cout << endl;
}

void startGame()
{
    clearBoard();

    while (true)
    {
        system("cls");
        renderBoard();

        if (userChar == playerSymbols[activePlayerNumber]) // users turn to make a move
        {
            int raw, column;

            cout << "Your sumbol is " << playerSymbols[activePlayerNumber] << '.' << endl;
            cout << "Please, enter the raw you want to move: ";
            cin >> raw;
            cout << "Please, enter the column you want to move: ";
            cin >> column;

            if ( isAvaliableCell(raw, column) )
            {
                makeMove(raw, column);
            }
            else
            {
                system("cls");
                showMsgWrongInput("This cell is busy yet!");

                this_thread::sleep_for(1s); // waiting 1 second

                continue;
            }
        }
        else // PCs turn to make a move
        {
            cout << "I'm thinking... Be patient!" << endl;

            while (true)
            {
                int raw = generateRandomNumberFormRange(1, BOARD_DIMENSIONS);
                int column = generateRandomNumberFormRange(1, BOARD_DIMENSIONS);

                if (isAvaliableCell(raw, column))
                {
                    makeMove(raw, column);
                    break;
                }
            }
        }

        if ( isWinner() )
        {
            system("cls");
            renderBoard();

            playerSymbols[activePlayerNumber] == userChar
            ? showMsgWin()
            : showMsgLose();

            break;
        }
        else
        {
            toggleActivePlayer(activePlayerNumber);
        }
    }
}

void makeMove(int raw, int column)
{
    board[--raw][--column] = playerSymbols[activePlayerNumber];
}

void toggleActivePlayer(int &activePlayerNumber)
{
    switch (activePlayerNumber)
    {
    case 0:
        activePlayerNumber = 1;
        break;
    case 1:
        activePlayerNumber = 0;
        break;
    }
}



bool isWinner()
{
    for (int i = 0; i < BOARD_DIMENSIONS; i++) // checking of all rows and columns
    {
        if ( board[i][i] != CELL_EMPTY )
        {
            if ( doesRawWin(i) || doesColumnWin(i) )
            {
                return true;
            }
        }
    }

    if // check diagonal from upper left to bottom right corner
    (
        board[0][0] == board[1][1] &&
        board[0][0] == board[2][2] &&
        board[0][0] != CELL_EMPTY
    )
    {
        return true;
    }
    else if // check diagonal from upper right to bottom left corner
    (
        board[2][0] == board[1][1] &&
        board[2][0] == board[0][2] &&
        board[2][0] != CELL_EMPTY
    )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isAvaliableCell(int raw, int column)
{
    return board[--raw][--column] == CELL_EMPTY ? true : false;
}

bool doesColumnWin(int columnNumber)
{
    for (int j = 1; j < BOARD_DIMENSIONS; j++)
    {
        if (board[j][columnNumber] != board[j-1][columnNumber])
        {
            return false;
        }
    }

    return true;
}

bool doesRawWin(int rawNumber)
{
    for (int j = 1; j < BOARD_DIMENSIONS; j++)
    {
        if (board[rawNumber][j] != board[rawNumber][j-1])
        {
            return false;
        }
    }

    return true;
}



void showMsgWin()
{
    SetConsoleTextAttribute(console, (WORD) ((0 << 4) | 2)); // set green color to output text
    cout << "Congratulations! You're winner!" << endl;
    SetConsoleTextAttribute(console, (WORD) ((0 << 4) | 7)); // set default color to output text
}

void showMsgLose()
{
    SetConsoleTextAttribute(console, (WORD) ((0 << 4) | 4)); // set red color to output text
    cout << " Good game, well played... " << endl;
    cout << "Unfortunately, you've lost!" << endl;
    SetConsoleTextAttribute(console, (WORD) ((0 << 4) | 7)); // set default color to output text
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

bool agreeMoveFirst()
{
    bool isTrue = agreeYesOrNo("Do you want to own the first move?");

    userChar = isTrue ? USER_SYMBOL_X : USER_SYMBOL_O;

    return isTrue;
}



int generateRandomNumberFormRange(int rangeStart, int rangeEnd)
{
    mt19937 mersenne(static_cast<unsigned int>(time(0))); // random number generator
    uniform_int_distribution<> dist(rangeStart, rangeEnd); // range of random values

    return dist(mersenne);
}