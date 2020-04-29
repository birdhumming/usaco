/*
ID: drayales
TASK: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <tgmath.h>
#include <vector>


using namespace std;
string namenum(string s, int n);

int main()
{
    string n;
    ifstream input1;
    input1.open("namenum.in");
    input1>>n;
    input1.close();
    ofstream outfile("namenum.out");
    string n_string = n;

    ifstream input2;
    input2.open("dict.txt");

    int check = 0;
    for (int i = 0; i < 4617; i++)
    {
        string y;
        input2>>y;
        int x = y.length();
        if (n_string == namenum(y, x))
        {
            cout<<y<<endl;
            outfile<<y<<endl;
            check++;
        }
    }
    if (check == 0)
    {
        outfile<<"NONE"<<endl;
    }
    input2.close();

    return 0;
}

string namenum(string s, int n)
{
    string final(n, '0');
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A' || s[i] == 'B' || s[i] == 'C')
        {
            final[i] = '2';
        }
        else if (s[i] == 'D' || s[i] == 'E' || s[i] =='F')
        {
            final[i] = '3';
        }
        else if (s[i] == 'G' || s[i] == 'H' || s[i] == 'I')
        {
            final[i] = '4';
        }
        else if (s[i] == 'J' || s[i] == 'K' || s[i] == 'L')
        {
            final[i] = '5';
        }
        else if (s[i] == 'M' || s[i] == 'N' || s[i] == 'O')
        {
            final[i] = '6';
        }
        else if (s[i] == 'P' || s[i] == 'R' || s[i] == 'S')
        {
            final[i] = '7';
        }
        else if (s[i] == 'T' || s[i] == 'U' || s[i] == 'V')
        {
            final[i] = '8';
        }
        else if (s[i] == 'W' || s[i] == 'X' || s[i] == 'Y')
        {
            final[i] = '9';
        }
        else if (s[i] == 'Q' || s[i] == 'Z')
        {
            final[i] = '0';
        }
    }
    return final;
}
