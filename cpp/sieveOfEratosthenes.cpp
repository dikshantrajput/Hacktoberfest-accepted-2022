#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;   // We will find all prime no till n

    vector<bool> primes(n + 1, true);

    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
        {
            for (int j = i * 2; j <= n; j += i)           // Here we are just checking the multiples of a number and marking them as false.
            {
                primes[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
        {
            cout << i << " ";                            // Here we are just printing all the numbers that are true i.e. Prime numbers
        }
    }

    return 0;
}
