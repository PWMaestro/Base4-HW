#include <iostream>

using namespace std;

int main()
{
    int previousNumber = 0,
        currentNumber = 1,
        nextNumber,
        soughtForMember,
        pointer = 2;
    
    cout << "Enter an index of row member: ";
    cin >> soughtForMember;

    if ( soughtForMember <= 0 ) {
        cout << "Error! Row member index must be greater than zero.";
        return 1;
    } else if ( soughtForMember == 1 ) {
        cout << previousNumber;
    } else if ( soughtForMember == 2 ) {
        cout << currentNumber;
    } else {
        do {
            nextNumber = currentNumber + previousNumber;
            previousNumber = currentNumber;
            currentNumber = nextNumber;
            pointer++;
            cout << "The " << pointer << " member is " << currentNumber << endl;
        } while ( pointer < soughtForMember );
    }
    
    return 0;
}
