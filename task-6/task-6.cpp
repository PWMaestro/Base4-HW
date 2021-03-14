#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[128];

    cout << "Enter the number: ";
    cin >> str;
    
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '.') {
            cout << "The first numeral of fractional part of number is: " << str[i+1] << endl;
            return 0;
        }
    }

    cout << "The number has no fractional part." << endl;
    return 0;
}