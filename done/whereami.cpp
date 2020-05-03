/*
problem: Farmer John is lost. there are N farms along the road, each with a colorful mailbox.
    the colors are specified by letters in the range A-Z, and some of the mailboxes are the same color.
    FJ wants to know the smallest value K where he can look at K mailboxes and know exactly where he is.
    (essentially the smallest value of K for which all substrings of length K are unique).
given: 
    int N = the number of mailboxes
    string of length N with characters A-Z, each representing a color
do: find the minimum K so that any substring of length K is unique
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int N;
string mailboxes;

int comp_string(int b1, int b2, int len);
int check_length(int len);

int main()
{
    ifstream fin ("whereami.in");
    ofstream fout ("whereami.out");

    fin >> N >> mailboxes;

    for (int i = 0; i < N-1; i++) //check all possible lengths
    {
        if (check_length(i))
        {
            fout << i << endl;
            return 0;
        }
    }
}

int check_length(int len)
//compares all substrings of mailboxes of length len
//returns true if all substrings are different
{
    for (int i = 0; i < N-len; i++)
    //i is all possible starting positions of a substring of length len (except for the very last one)
    {
        for (int j = i+1; j <= N-len; j++)
        //j is all possible starting positions ahead of i, including the last one
        {
            if (comp_string(i, j, len)) //if the substrings are the same, len is not a viable K
            {
                return 0;
            }
        }
    }
    return 1;
}

int comp_string(int b1, int b2, int len)
//compares two substrings, one beginning at b1, one beginning at b2, both of length len
{
    for (int i = 0; i < len; i++)
    {
        if (mailboxes[b1 + i] != mailboxes[b2 + i])
        {
            return 0;
        }
    }
    return 1;
}


