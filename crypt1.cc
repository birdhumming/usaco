/*
ID: drayales
TASK: crypt1
LANG: C++
*/


#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <cstdlib>

int nums[10] = {0};

using namespace std;

int is_valid(int X, int len);
int multiply_good(int X, int Y);

int main()
{
    int N;
    int count = 0;
    
    ifstream input1;
    input1.open("crypt1.in");

    input1>>N;

    for(int i = 0; i < N; i++)
    {
        int x;
        input1>>x;
        nums[x] = 1;
    }

    input1.close();
    for (int i = 0; i < 10; i++)
    {
        cout<<nums[i]<<endl;
    }

    for (int i = 100; i < 1000; i++)
    {
        for (int j = 10; j < 100; j++)
        {
            if (multiply_good(i, j) == 1) count++;
        }
    }
    ofstream outfile("crypt1.out");
    outfile<<count<<endl;
}

int is_valid(int X, int len)
{
    if (len != (to_string(X).length()))
    {
        return 0;
    }
    for (int i = 0; i < to_string(X).length(); i++)
    {
        char c = to_string(X)[i];
        int ic = c - '0';
        if (nums[ic] == 0)
        {
            return 0;
        }
    }
    return 1;
}

int multiply_good(int X, int Y)
{
    if (is_valid(X, 3) == 0)
    {
        return 0;
    }
    if (is_valid(Y, 2) == 0)
    {
        return 0;
    }
    if (is_valid(X*Y, 4) == 0)
    {
        return 0;
    }
    if (is_valid(X * (Y%10), 3) == 0)
    {
        return 0;
    }
    if (is_valid(X * (Y/10), 3) == 0)
    {
        return 0;
    }
    return 1;

}
