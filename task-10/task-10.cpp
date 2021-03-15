#include <iostream>

using namespace std;

double calculateFibonacciSomeRawMember(int lastRawMember);

int main()
{
    int soughtForMember = 0;
    
    cout << "Enter an index of last row member: ";
    cin >> soughtForMember;

    if ( soughtForMember <= 0 ) {
        cout << "Error! Row member index must be greater than zero.";
        return 1;
    } else {
        cout << "Sought for raw member value is: " << calculateFibonacciSomeRawMember(soughtForMember) << endl;
    }

    return 0;
}

double calculateFibonacciSomeRawMember(int lastRawMember)
{
    double prevRawMember = 0, currRawMember = 1, nextRawMember;

    if (lastRawMember == 1) {
        return prevRawMember;
    } else if (lastRawMember == 2) {
        return currRawMember;
    } else {
        for (int i = 3; i <= lastRawMember; i++) {
            nextRawMember = currRawMember + prevRawMember;
            prevRawMember = currRawMember;
            currRawMember = nextRawMember;
        }
    }

    return currRawMember;
}