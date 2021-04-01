#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>
#include <random>
#include <ctime>

#define RECRUITS_LINE_LENGTH 30
#define LOOKING_RIGHT '>'
#define LOOKING_LEFT '<'

using namespace std;



void turnAroundFaceToFaceRecruits(int position);
void turnLeftOneOfTheRecruits();
void showRecruitsLine();

int getLookingLeftRecruitPosition();



char recruitsLine[RECRUITS_LINE_LENGTH];



int main()
{
    for (int i = 0; i < RECRUITS_LINE_LENGTH; i++)
    {
        recruitsLine[i] = LOOKING_RIGHT;
    }
    
    system("cls"); // clean the screen
    turnLeftOneOfTheRecruits();
    showRecruitsLine();

    while ( int position = getLookingLeftRecruitPosition() )
    {
        this_thread::sleep_for(1s); // waiting 1 second

        turnAroundFaceToFaceRecruits(position);
        showRecruitsLine();
    }

    Beep( 750, 1000 );

    return 0;
}



void turnAroundFaceToFaceRecruits(int position)
{
    recruitsLine[position] = LOOKING_RIGHT;
    recruitsLine[position - 1] = LOOKING_LEFT;
}

void turnLeftOneOfTheRecruits()
{
    mt19937 mersenne(static_cast<unsigned int>(time(0))); // random number generator
    uniform_int_distribution<> dist(0, RECRUITS_LINE_LENGTH - 1); // range of random values

    recruitsLine[dist(mersenne)] = LOOKING_LEFT;
}

void showRecruitsLine()
{
    system("cls"); // clean the screen
    for (int i = 0; i < RECRUITS_LINE_LENGTH; i++)
    {
        cout << recruitsLine[i];
    }
    cout << endl;
}

int getLookingLeftRecruitPosition()
{
    for (int i = 1; i < RECRUITS_LINE_LENGTH; i++)
    {
        if (recruitsLine[i] == LOOKING_LEFT)
        {
            return i;
        }
    }
    return 0;
}
