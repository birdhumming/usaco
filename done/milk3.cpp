/*
ID: drayales
TASK: milk3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>

/*
    in: 3 integers A, B, and C (1-20)
    out: sorted list of all possible values of C for which the amount in A
    = 0

    description: 3 buckets, capacities of which are given. A and B start out empty, while C
    starts out full, so total amount of milk is known. pouring is done until pour-er is empty
    or pour-ee is full. unlimited amount of pouring can be done, no milk is wasted. output 
    the amounts in C that will allow A to be 0. 
*/

void helper(int c, int b); //checks if positions c and b are actually possible

using namespace std;

int CB[21][21] = {0}; // 2D array. i is the amount in C, j is the amount in B.
int A, B, C; //bucket sizes

int main()
{
    int fin[1000];
    int c = 0;
    
    ifstream input1;
    input1.open("milk3.in");
    input1>>A>>B>>C;
    input1.close();

    ofstream outfile("milk3.out");

    //CB[C][0] = 1;
    helper(C, 0); //calls recursive function 'helper'

    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (CB[i][j] == 1 && i+j == C) 
            {
                fin[c] = i;
                c++;
            }

        }
    }

    for (int i = 0; i < c - 1; i++)
    {
        outfile<<fin[i]<<' ';
    } 
    outfile<<fin[c-1]<<endl;



}

void helper(int c, int b) //c and b are the AMOUNTS of milk in buckets with 
//capacities of C and B
{
    if (CB[c][b] == 1) //if it has already been set
    {
        return;
    }
    CB[c][b] = 1;
    int a = C - (c + b); //a is the total amount minus the b and c amounts
    if (c > B - b) //c into b
    {
        helper(c - (B-b), B); //have poured from c, B is now full
    }
    else
    {
        helper(0, c + b); //c is empty, all in B
    }
    if (c > A - a) //c into a
    {
        helper(c - (A - a), b); 
    }
    else
    {
        helper(0, b);
    }
    if (b > A - a) //b into a
    {
        helper(c, b - (A - a));
    }
    else
    {
        helper(c, 0); 
    }
    if (b > C - c) //b into c
    {
        helper(C, b - (C - c));
    }
    else
    {
        helper(c + b, 0);
    }
    if (a > B - b) //a into b
    {
        helper(c, B);
    }
    else
    {
        helper(c, b + a);
    }
    if (a > C - c) //a into c
    {
        helper(C, b);
    }
    else
    {
        helper(c + a, b);
    }
}
