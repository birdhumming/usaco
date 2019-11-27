/*
ID: drayales
TASK: combo
LANG: C++
*/


#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <cstdlib>

int N;

using namespace std;

int is_close(int a, int b);
int is_close_key(int a1, int a2, int a3, int k1, int k2, int k3);


int main()
{
    int a1, a2, a3, b1, b2, b3;
    int count = 0;

    ifstream input1;
    input1.open("combo.in");
    input1>>N;
    input1>>a1>>a2>>a3>>b1>>b2>>b3;

    input1.close();

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            for (int k = 1; k < N + 1; k++)
            {
                if (is_close_key(a1, a2, a3, i , j, k) || is_close_key(b1, b2, b3, i, j, k))
                {
                    count++;
                }
            }
        }
    }
    ofstream outfile("combo.out");
    outfile<<count<<endl;
}


int is_close(int a, int b)
{
    if (abs(a - b) <= 2)
    {
        return 1;
    }
    if (abs(a - b) >= N - 2)
    {
        return 1;
    }
    return 0;
}

int is_close_key(int a1, int a2, int a3, int k1, int k2, int k3)
{
    if (is_close(a1, k1) && is_close(a2, k2) && is_close(a3, k3))
    {
        return 1;
    }
    return 0;
}
