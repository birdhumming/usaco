/*
ID: drayales
TASK: barn1
LANG: C++
*/


#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int * stables;
    int * gaps;
    int M, S, C;
    int sum = 0;

    ifstream input1;
    input1.open("barn1.in");

    input1>>M>>S>>C;

    stables = new int [C];
    for (int i = 0; i < C; i++)
    {
        input1>>stables[i];
    }

    input1.close();

    sort(stables, stables+C);

    gaps = new int [C-1];
    for (int i = 0; i < C-1; i++)
    {
        gaps[i] = stables[i+1] - stables[i] - 1;
    }
    
    sort(gaps, gaps+C-1);
    
    for (int i =0; i<C-1; i++)
    {
        //cout<<stables[i]<<'\n';
        //cout<<gaps[i]<<'\n';
    }
    //cout<<stables[C-1]<<'\n';

    if (M < C)
    {    
        for (int i = 0; i < M-1; i++)
        {
            cout<<gaps[C-1-i-1]<<'\n';
            sum += gaps[C-1-i-1];
        }

        int final = stables[C-1] - stables[0] + 1;
        final -= sum;

        ofstream outfile("barn1.out");
        outfile<<final<<endl;   
    }
    else if (M >= C)
    {
        ofstream outfile("barn1.out");
        outfile<<C<<endl;
    }

    //cout<<gaps[16]<<'\n';
    //cout<<sum<<'\n';


    delete[] stables;
    delete[] gaps;
}


