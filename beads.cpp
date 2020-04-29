/*
ID: drayales
TASK: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    ofstream outfile("beads.out");
    ifstream infile("beads.in");
    int len;
    infile>>len;
    string necklace;
    infile>>necklace;
    int gbeads = 0;
    int count = 0;
    char ch = necklace[0];
    int chtracker = 0;
    for (int i = 0; i < len; i++)
    {
        if (necklace[i] == ch)
        {
            chtracker++;
        }
    }
    if (chtracker == len)
    {
        outfile<<len<<endl;
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            char x = necklace[i];
            if (x == 'w')
            {
                if (i == len - 1)
                {
                    x = necklace[0];
                }
                else
                {
                    x = necklace[i + 1];
                }
            }
            int r;
            if (i == 0)
            {
                r = len - (i + 1);
            }
            else
            {
            r = i - 1;
            }
            char y = necklace[r];
            if (y == 'w')
            {
                if (i == 0)
                {
                    y = necklace[len - 1];
                }
                else
                {
                    y = necklace[i - 1];
                }
            }
            int c = i;
            int tceone = 0;
            int tcetwo = 0;
            while (necklace[c] == x || necklace[c] == 'w')
            {
                tceone++;
                c++;
                if (c > len - 1)
                {
                    c = 0;
                }
            }
            while ((necklace[r] == y || necklace[r] == 'w') && r != c - 1)
            {
                tcetwo++;
                r--;
                if (r < 0)
                {
                    r = len + r;
                }
            }
            if (tceone+tcetwo > gbeads)
            {
                gbeads = tceone+tcetwo;
            }
        }
        outfile<<gbeads<<endl;
    }
}
