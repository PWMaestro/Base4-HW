#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int InitialMutants, nextDayMutants, dailyKilledMutants, reproductionPercentage, counter = 1;

    cout << "Number of mutants: ";
    cin >> InitialMutants;
    cout << "Persentage of reproduction: ";
    cin >> reproductionPercentage;
    cout << "Number of mutants killed by HMS: ";
    cin >> dailyKilledMutants;

    nextDayMutants = trunc( InitialMutants * ( 1 + (reproductionPercentage / 100.0) ) ) - dailyKilledMutants;

    if (nextDayMutants > InitialMutants) {
        cout << "Mutants will conquer the entire planet!";
    } else if (nextDayMutants == InitialMutants) {
        cout << "The fight will last forever!";
    } else {
        while (nextDayMutants > 0) {
            nextDayMutants = trunc( nextDayMutants * ( 1 + (reproductionPercentage / 100.0) ) ) - dailyKilledMutants;
            counter++;
        }
        cout << "The fight will last " << counter << " days.";
    }

    return 0;
}