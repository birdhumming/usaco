/*
problem: Farmer John wants to milk his 8 cows Beatrice, Belinda, Bella, Bessie, Betsy, Blue, Buttercup, and Sue.
    the cows are somewhat picky, though, and have some stipulations on the milking order. 
    each stipulation is in the form "X must be milked beside Y", which means X must be milked directly before/after Y.
    find the alphabetically lowest order that is possible.
given:
    int N = the number of constraints
    N constraints
find: the alphabetically lowest possible order of cow milking
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
vector < pair <int, int> > milkbuddies;

int orders [40320][8];

int cow_to_number(string cow);
int cow_check(int a, int b, int arr[8]);
string number_to_cow(int number);

int main()
{
    ifstream fin ("lineup.in");
    //ofstream fout ("lineup.out");

    freopen("lineup.out", "w", stdout);

    fin >> N;

    string cow1;
    string cow2;
    pair <int, int> temp;
    for (int i = 0; i < N; i++)
    {
        fin >> cow1;
        fin.ignore(23);
        fin >> cow2;

        temp.first = cow_to_number(cow1);
        temp.second = cow_to_number(cow2);
        milkbuddies.push_back(temp);
    }
    
    for (int i = 0; i < 8; i++)
    {
        orders[0][i] = i + 1;
    }

    int count = 0;
    do 
    {
        for (int i = 0; i < 8; i++)
        {
            orders[count][i] = orders[0][i];
        }
        count++;
    } while ( next_permutation(orders[0], orders[0] + 8) );

    int track = 0;

    for (int i = 0; i < 40320; i++)
    {
        for (int j = 0; j < milkbuddies.size(); j++)
        {
            if (cow_check(milkbuddies[j].first, milkbuddies[j].second, orders[i]))
            {
                //cout << "j = " << j << endl;
                //cout << milkbuddies[j].first << " " << milkbuddies[j].second << endl;
                track++;
            }
        }
        if (track == milkbuddies.size())
        {
            for (int k = 0; k < 8; k++)
            {
                if (k == 7)
                {
                    cout << number_to_cow(orders[i][k]);
                    return 1;
                }
                cout << number_to_cow(orders[i][k]) << endl;
            }
        }
        track = 0;
    }
}

int cow_check(int a, int b, int arr[8])
{
    int i = 0;
    while (arr[i] != a)
    {
        i++;
    }
    //cout << "a = " << a <<", b = " << b << ", i = " << i << endl;

    if (i == 0)
    {
        if (arr[1] == b)
        {
            //cout << "i = 0, arr[i] = " << a << " arr[i+1] = " << b << endl;
            return 1;
        }
        return 0;
    }

    if (i == 7)
    {
        if (arr[6] == b)
        {
            //cout << "i = 7, arr[i] = " << a << " arr[i-1] = " << b << endl;
            return 1;
        }
        return 0;
    }
    if (arr[i+1] == b || arr[i-1] == b)
    {
        //cout << "i = " << i << " , arr[i] = " << a << " arr[i+1] or arr[i-1] = " << b << endl;
        return 1;
    }
    return 0;
}



int cow_to_number(string cow)
{
    if (cow == "Beatrice")
    {
        return 1;
    }
    if (cow == "Belinda")
    {
        return 2;
    }
    if (cow == "Bella")
    {
        return 3;
    }
    if (cow == "Bessie")
    {
        return 4;
    }
    if (cow == "Betsy")
    {
        return 5;
    }
    if (cow == "Blue")
    {
        return 6;
    }
    if (cow == "Buttercup")
    {
        return 7;
    }
    if (cow == "Sue")
    {
        return 8;
    }
}

string number_to_cow(int number)
{
    if (number == 1)
    {
        return "Beatrice";
    }
    if (number == 2)
    {
        return "Belinda";
    }
    if (number == 3)
    {
        return "Bella";
    }
    if (number == 4)
    {
        return "Bessie";
    }
    if (number == 5)
    {
        return "Betsy";
    }
    if (number == 6)
    {
        return "Blue";
    }
    if (number == 7)
    {
        return "Buttercup";
    }
    if (number == 8)
    {
        return "Sue";
    }
}
