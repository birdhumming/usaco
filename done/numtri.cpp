/*
ID: drayales
TASK: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

int max(int i, int j);
int solve(int i, int j, int r);



int a[1002][1002];
int b[1002][1002];


int main()
{
    int r;
    memset (b, -1, sizeof(b));

    ifstream input1;
    input1.open("numtri.in");

    input1>>r;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 0; j < i; j++)
        {
            input1>>a[i][j];
        }
    }
    input1.close();

    ofstream outfile("numtri.out");
    int ans = solve (1, 0, r);
    outfile<<ans<<endl;
    
}

int max(int i, int j)
{
    if (i > j)
    {
        return i;
    }
    else
    {
        return j;
    }
}


int solve(int i, int j, int r)
{

    if(b[i][j] != -1)
    {
        return b[i][j];
    }
    else if(i <= r)
    {
        return b[i][j] = a[i][j] + max(solve(i + 1, j, r), solve(i + 1, j + 1, r));
    }
    else
    {
        return 0;
    }
}
    
