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
    cin>>n;
    int check = 0;
    while (!cin.eof()) {
        string y;
        cin>>y;
        int x = y.length();
        if (n == namenum(y, x))
        {
            cout<<y<<'\n';
            check++;
        }
    }
    if (check == 0)
    {
        cout<<"NONE\n";
    }

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
