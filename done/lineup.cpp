/*
problem: Farmer John wants to milk his 8 cows Beatrice, Belinda, Bella, Bessie, Betsy, Blue, Buttercup, and Sue.
    the cows are somewhat picky, though, and have some stipulations on the milking order. 
    each stipulation is in the form "X must be milked beside Y", which means X must be milked directly before/after Y.
    find the alphabetically lowest order that is possible.
given:
    int N = the number of constraints
    N constraints
find: the alphabetically lowest possible order of cow milking

method: all eight cows correspond to a number 1-8 according to their alphabetical order
    we can then represent all possible orders of cows as permutations of {1, 2, 3, 4, 5, 6, 7, 8}.
    if we use the next_permutation function, we can ensure that the permutations generated, when converted back to the cow names,
    will be in alphabetical order. therefore we just need to iterate through all the permutations, returning the first one we find. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector < pair <int, int> > milkbuddies; //pairs of cows that must be next to each other

int orders [40320][8]; //8! permutations of length 8

int cow_to_number(string cow);
int cow_check(int a, int b, int arr[8]);
string number_to_cow(int number);

int main()
{
    ifstream fin ("lineup.in");
    //ofstream fout ("lineup.out");

    freopen("lineup.out", "w", stdout); //was debugging, fout works as well

    fin >> N;

    string cow1;
    string cow2;
    pair <int, int> temp;
    for (int i = 0; i < N; i++)
    {
        fin >> cow1;
        fin.ignore(23); //" must be milked besides " is 23 characters we can ignore. we just need names
        fin >> cow2;

        temp.first = cow_to_number(cow1); //converting cow names to numbers 
        temp.second = cow_to_number(cow2);
        milkbuddies.push_back(temp);
    }
    
    for (int i = 0; i < 8; i++)
    {
        orders[0][i] = i + 1; //setting orders[0] to be the original {1, 2, 3, 4, 5, 6, 7, 8}
        //essentially first in alphabetical order
    }

    //setting all permutations
    int count = 0;
    do 
    {
        for (int i = 0; i < 8; i++)
        {
            orders[count][i] = orders[0][i];
        }
        count++;
    } while ( next_permutation(orders[0], orders[0] + 8) );

    //iterate though all permutations and check if all pairs in milkbuddies are next to each other for each one
    int track = 0;

    for (int i = 0; i < 40320; i++)
    {
        for (int j = 0; j < milkbuddies.size(); j++)
        {
            if (cow_check(milkbuddies[j].first, milkbuddies[j].second, orders[i]))
            //if milkbuddies[j].first is next to milkbuddies[j].second
            {
                //cout << "j = " << j << endl;
                //cout << milkbuddies[j].first << " " << milkbuddies[j].second << endl;
                track++;
            }
        }
        if (track == milkbuddies.size()) //all pairs are next to each other
        {
            for (int k = 0; k < 8; k++)
            {
                cout << number_to_cow(orders[i][k]) << endl; //convert number to cow names
            }
            return 0; //cannot return 1! USACO machine will read as error and won't make an output file
        }
        track = 0; //reset track, run again
    }
}

int cow_check(int a, int b, int arr[8]) 
//checks if a and b are next to each other in given array arr
{
    int i = 0;
    while (arr[i] != a) {i++;}

    if (i == 0)
    {
        if (arr[1] == b) {return 1;}
        return 0;
    }

    if (i == 7)
    {
        if (arr[6] == b) {return 1;}
        return 0;
    }

    if (arr[i+1] == b || arr[i-1] == b) {return 1;}

    return 0;
}

int cow_to_number(string cow)
//converts cow names to numbers
{
    if (cow == "Beatrice") //first alphabetically
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
//converts cow numbers to names
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
