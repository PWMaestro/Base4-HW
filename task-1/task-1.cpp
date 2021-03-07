#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int m, m1, n, p, counter = 1;

    cout << "Number of mutants: ";
    cin >> m;
    cout << "Persentage of reproduction: ";
    cin >> p;
    cout << "Number of mutants killed by HMS: ";
    cin >> n;

    m1 = trunc( m * ( 1 + (p / 100.0) ) ) - n;

    if (m1 > m) {
        cout << "Mutants will conquer the entire planet!";
    } else if (m1 == m) {
        cout << "The fight will last forever!";
    } else {
        while (m1 > 0) {
            m1 = trunc( m1 * ( 1 + ( p / 100 ) ) ) - n;
            counter++;
        }
        cout << "The fight will last " << counter << " days.";
    }

    return 0;
}