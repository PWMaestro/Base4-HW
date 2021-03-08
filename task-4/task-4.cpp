#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a = 0, b = 0;

    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    if (a > 0 && b > 0) {
        int c, max = a, min = b;

        if (b > a) {
            max = b;
            min = a;
        }

        do {
            c = max % min;
            max = min;
            min = c;
        } while (c > 0);

        cout << "Least common deviser: " << a * b / max << endl;
        
    } else {
        cout << "Error! Wrong number!";
        return 1;
    }
    
    return 0;
}