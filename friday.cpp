/*
ID: drayales
TASK: friday
LANG: C++
*/


#include <iostream>
#include <fstream>
#include <tgmath.h>
#include <unordered_map>
#include <string>

int month_sum(int num);

using namespace std;

int main()
{
    ofstream outfile("friday.out");
    ifstream infile("friday.in");
    int yr;
    infile>>yr;
    string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    unordered_map<string, int> u;
    for (int i = 0; i < 7; i++)
    {
        string x = days[i];
        u[x] = 0;
    }


    int x;
    int days_left = 0;
    for (int i = 0; i < yr; i++)
    {
        if (i % 4 != 0 || i == 0)
        {
            for (int c = 0; c < 12; c++)
            {
                x = (days_left + month_sum(c) + 13) % 7;
                if (x == 0)
                {
                        u["Sunday"]++;
                }
                else
                {
                    string day = days[x - 1];
                    u[day]++;
                }
            }
            days_left = 365 % 7 + days_left;
        }
        else if (i % 4 == 0)
        {
            if ((i % 100 != 0) || ((i + 1900) % 400 == 0))
            {
                for (int c = 0; c < 12; c++)
                {
                    if (c < 2)
                    {
                        x = (days_left + month_sum(c) + 13) % 7;
                        if (x == 0)
                        {
                            u["Sunday"]++;
                        }
                        else
                        {
                            string day = days[x - 1];
                            u[day]++;
                        }
                    }
                    else
                    {
                        x = (days_left + month_sum(c) + 13 + 1) % 7;
                        if (x == 0)
                        {
                            u["Sunday"]++;
                        }
                        else
                        {
                            string day = days[x-1];
                            u[day]++;
                        }
                    }
                }
                days_left = 366 % 7 + days_left;
            }
            else if (i % 100 == 0 && (1900 + i) % 400 != 0)
            {
                for (int c = 0; c < 12; c++)
                {
                    x = (days_left + month_sum(c) + 13) % 7;
                    if (x == 0)
                    {
                        u["Sunday"]++;
                    }
                    else
                    {
                        string day = days[x - 1];
                        u[day]++;
                    }
                }
                days_left = 365 % 7 + days_left;
            }
        }
    }

    outfile<<u["Saturday"]<<" "<<u["Sunday"]<<" "<<u["Monday"]<<" "<<u["Tuesday"]<<" "<<u["Wednesday"]<<" "<<u["Thursday"]<<" "<<u["Friday"]<<endl;
}


int month_sum(int num)
{
    int count = 0;
    int month_year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < num; i++)
    {
        count = count + month_year[i];
    }
    return count;
}
