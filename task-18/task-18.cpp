#include <iostream>
#include <cmath>

#define MAX_NUMBER_OF_ELEMENTS 1000000000

using namespace std;

double linearSearchComplexity(int n);
double binarySearchComplexity(int n);
double quickSortComplexity(int n);

int main()
{
    for (int i = 2; i < 10; i++)
    {
        int counter = 1;
        double deltaComplexity = 0.0;

        while (true)
        {
            deltaComplexity = (linearSearchComplexity(i) - binarySearchComplexity(i)) * counter - quickSortComplexity(i);

            if (deltaComplexity < 0)
            {
                cout << "Linear search is better for " << counter << " searches among " << i << " elements." << endl;
            }
            else
            {
                cout << "Quick sort + binary search are better for " << counter << " searches among " << i << " elements." << endl << endl;
                break;
            }

            counter++;
        }
    }
    
    cout << "Linear search worst then quick sort + binary search begining form:" << endl;

    for (int i = 10; i <= MAX_NUMBER_OF_ELEMENTS; i *= 10)
    {
        int counter = 0;
        double deltaComplexity = 0.0;
        
        do
        {
            counter++;
            deltaComplexity = (linearSearchComplexity(i) - binarySearchComplexity(i)) * counter - quickSortComplexity(i);
        } while (deltaComplexity < 0);
        
        cout << counter << " searches among " << i << " elements" << endl;
    }

    return 0;
}

double linearSearchComplexity(int n)
{
    return n;
}

double binarySearchComplexity(int n)
{
    return log2(n);
}

double quickSortComplexity(int n)
{
    return n * log2(n);
}
