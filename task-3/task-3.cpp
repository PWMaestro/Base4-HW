#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
    int sum = 0, r = 0, n;
    char binary[255];

    cout << "Enter binary number: ";
    cin >> binary;

    n = strlen(binary);
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = static_cast<int>( binary[i] ) - static_cast<int>( '0' );
        if (arr[i] != 0 && arr[i] != 1) {
            cout << "Error! Wrong number system!" << endl;
            return 1;
        }
        r += arr[i] * pow( 2, n - i - 1 );
    }

    cout << "Decimal binary is equal: " << r;
    return 0;
}