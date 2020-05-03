/*
problem: Farmer John is shooting his cows (numbered 1-N), one by one. 
    to take good photos, he has a specific order that he wants the cows to be in.
    cow 1 goes to a_1, cow 2 goes to a_2, cow N goes to a_N etc. however, he has forgotten the order. 
    thankfully, we have another series b where b_i = a_i + a_i+1, up to b_N-1. 
given: 
    int N = number of cows (2-1000)
    sequence b of length N-1
do: find the lexicographically minimum possible sequence a. lexiocgraphical order is basically alphabetical order, but 1 = a, 2, = b, etc.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector <int> b;

int tracker[1001] = {0}; 
//because the cows are numbered 1-N, in sequence a, each number should only appear once

void clear_tracker();

int main()
{
    ifstream fin ("photo.in");
    ofstream fout ("photo.out");

    fin >> N;
    int temp;
    for (int i = 0; i < N-1; i++)
    {
        fin >> temp;
        b.push_back(temp);
    }

    vector <int> a;

    int start, next;

    for (int i = 1; i < N+1; i++)
    //once we have a_1 (the seed), the rest of the sequence is determined
    //start with 1 and go up for lexicographical minimum
    {
        start = i;
        tracker[i] = 1; //i can't be used anymore
        a.push_back(start);

        for (int j = 0; j < N-1; j++)
        {
            next = b[j] - start; //b[i] = a[i] + a[i+1]

            if (next <= 0 || next > N || tracker[next] == 1)
            {
                a.clear();
                clear_tracker();
                //cout << "breaking" << endl;
                break;
            }

            start = next;
            tracker[next] = 1;
            a.push_back(next);
        }

        if (a.size() == N) //a is full and we have a complete sequence
        {
            break;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i == N-1)
        {
            fout << a[i];
            return 0;
        }
        fout << a[i] << " ";
    }

}

void clear_tracker()
{
    for (int i = 0; i < 1001; i++)
    {
        tracker[i] = 0;
    }
}

