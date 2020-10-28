#include <iostream>
#include "console.h"
using namespace std;

bool IsPerfect(int number)
{
    int sum = 0;
    for (int i = 1; i <= number/2; i++)
        if (number % i == 0)
            sum += i;
    return number == sum;
}

int main() {
    for (int i = 1; i <= 10000; i++)
        if (IsPerfect(i))
            cout << i << endl;
    return 0;
}
