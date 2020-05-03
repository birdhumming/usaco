#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstring>


using namespace std;

int test[100] = {0};

int main()
{
    test[9] = 1;
    test[53] = 1;
    test[58] = 1;
    test[99] = 1;

    memset(test, 0, 100);
    for (int i = 0; i < 100; i++)
    {
        cout << test[i] << " ";
    }
}