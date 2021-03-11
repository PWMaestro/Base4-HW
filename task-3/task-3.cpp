#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
    int sum = 0, decimalNumber = 0, binaryLength;
    char binary[255];

    cout << "Enter binary number: ";
    cin >> binary;

    binaryLength = strlen(binary);
    int arr[binaryLength];

    for (int i = 0; i < binaryLength; i++) {
        arr[i] = static_cast<int>( binary[i] ) - static_cast<int>( '0' );
        if (arr[i] != 0 && arr[i] != 1) {
            cout << "Error! Wrong number system!" << endl;
            return 1;
        }
        decimalNumber += arr[i] * pow( 2, binaryLength - i - 1 );
    }

    cout << "Equivalent decimal is: " << decimalNumber;
    return 0;
}