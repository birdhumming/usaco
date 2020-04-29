/*
ID: drayales
TASK: gift1
LANG: C++
*/

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <tgmath.h>

using namespace std;

int main()
{
    ofstream outfile ("gift1.out");
    ifstream infile("gift1.in");
    int s;
    string v;
    infile>>s;
    string names[s];
    unordered_map<string, int> u = {};
    for (int i = 0; i < s; i++)
    {
        infile>>v;
        u[v] = 0;
        names[i] = v;
    }
    for (int i = 0; i < s; i++)
    {
        infile>>v;
        int a, b;
        infile>>a>>b;
        if (b == 0)
        {
            u[v] = u[v] + a;
        }
        else
        {
            u[v] = u[v] - ((floor(a/b))*b);
            for (int i = 0; i < b; i++)
            {
                infile>>v;
                u[v] = u[v] + floor(a/b);
            }
        }
    }
    for (int i = 0; i < s; i++)
    {
        string x = names[i];
        outfile<<x<<" "<<u[x]<<endl;
    }
}

