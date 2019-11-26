/*
ID: drayales
TASK: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

int is_pal(string strn);
char reval(int num);
string base_convert(int x, int base);
void strev(char *str);

int main()
{

    int b;
    ifstream input1;
    input1.open("palsquare.in");
    input1>>b;
    input1.close();

    ofstream outfile("palsquare.out");


    for (int i = 1; i < 301; i++)
    {
        string x = base_convert(pow(i, 2), b);
        if (is_pal(x) == 0)
        {
            outfile<<base_convert(i, b)<<" "<<x<<endl;
        }
    }




}


int is_pal(string strn)
{
    int len = strn.length();

    int x = 0;
    while (strn[x] == strn[len - x - 1] && x < len/2)
    {
        x++;
    }
    if (x == len/2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

char reval(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}


string base_convert(int x, int base)
{
    int index = 0;
    char res[1000000];
    while (x > 0)
    {
        res[index++] = reval(x % base);
        x /= base;
    }
    res[index] = '\0';

    // Reverse the result
    strev(res);
    return res;
}



void strev(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

