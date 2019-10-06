/*
ID: drayales
TASK: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <new>
#include <array>

using namespace std;

int main()
{
    ifstream infile ("transform.in");
    ofstream outfile ("transform.out");
    int n;
    int c;
    char x;
    infile>>n;
    c = n-1;
    char array0[n][n];
    char array1[n][n];
    int count = 0;
    //setting arrays array0 and temp
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            infile>>x;
            array0[j][i] = x;
        }
    }
    //setting array1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            infile>>x;
            array1[j][i] = x;
        }
    }
    //checking case 1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array0[i][c-j] == array1[j][i])
            {
                count++;
            }
        }
    }
    if (count == n*n)
    {
        outfile<<"1"<<endl;
        return 0;
    }
    else
    {
        count = 0;
    }
    //checking case 2
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array0[c-j][c-i] == array1[j][i])
            {
                count++;
            }
        }
    }
    if (count == n*n)
    {
        outfile<<"2"<<endl;
        return 0;
    }
    else
    {
        count = 0;
    }
    //checking case 3
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array0[c-i][j] == array1[j][i])
            {
                count++;
            }
        }
    }
    if (count == n*n)
    {
        outfile<<"3"<<endl;
        return 0;
    }
    else
    {
        count = 0;
    }
    //checking case 4
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array0[c-j][i] == array1[j][i])
            {
                count++;
            }
        }
    }
    if (count == n*n)
    {
        outfile<<"4"<<endl;
        return 0;
    }
    else
    {
        count = 0;
    }
    //checking case 5 (3 parts)
    //part a
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array0[c-i][c-j] == array1[j][i])
            {
                count++;
            }
        }
    }
    if (count == n*n)
    {
        outfile<<"5"<<endl;
        return 0;
    }
    else
    {
        count = 0;
    }
    //part b
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array0[j][c-i] == array1[j][i])
            {
                count++;
            }
        }
    }
    if (count == n*n)
    {
        outfile<<"5"<<endl;
        return 0;
    }
    else
    {
        count = 0;
    }
    //part c
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array0[i][j] == array1[j][i])
            {
                count++;
            }
        }
    }
    if (count == n*n)
    {
        outfile<<"5"<<endl;
        return 0;
    }
    else
    {
        count = 0;
    }
    //checking case 6
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array0[j][i] == array1[j][i])
            {
                count++;
            }
        }
    }
    if (count == n*n)
    {
        outfile<<"6"<<endl;
        return 0;
    }
    else
    {
        count = 0;
    }
    outfile<<"7"<<endl;

}
