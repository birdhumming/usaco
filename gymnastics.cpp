/*
problem: the cows are doing gymnastics. in each of K practice sessions, they are ranked.
    a pair of cows is consistent if cow a did better than cow b in every session.
given:
    int K = the number of practice sessions (1-10)
    int N = the number of cows (1-20)
    K lines of N cows, ranked
    cow a does better than cow b if a comes before b in a line
do:
    find the total number of consistent pairs
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int K, N;
int situations[11][21] = {0}; //max 10 situations, max 20 cows

vector < pair <int, int> > consistent; //better, worse

void pair_check(int pos, int situation[21]);

int main()
{
    ifstream fin ("gymnastics.in");
    ofstream fout ("gymnastics.out");

    fin >> K >> N;

    int temp;
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fin >> temp;
            situations[i][j] = temp;
        }
    }

    //creating pairs of cows (better, worse) based on first situation
    pair <int, int> temp1;
    for (int i = 0; i < N-1; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            temp1.first = situations[0][i];
            temp1.second = situations[0][j];
            consistent.push_back(temp1);
        }
    }

    if (K == 1) 
    {
        fout << consistent.size() << endl;
        return 0;
    }

    for (int i = 0; i < K; i++) //situations
    {
        for (int j = 0; j < consistent.size(); j++) //pairs
        {
            if (consistent[j].first != -1) //if the pair hasn't already been marked inconsistent
            {
                pair_check(j, situations[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < consistent.size(); i++)
    {
        if (consistent[i].first > 0)
        {
            //cout << consistent[i].first << " " << consistent[i].second << endl;
            ans++;
        }
    }

    fout << ans << endl;
}

void pair_check(int pos, int situation[21])
//given a so-far consistent pair and a situation, check if the pair is consistent
{
    int better = consistent[pos].first;
    int worse = consistent[pos].second;

    //cout << "better = " << better << endl;
    //cout << "worse = " << worse << endl;
    
    int found_better = 0; 

    for (int i = 0; i < N; i++)
    {
        if (situation[i] == better)
        {
            found_better = 1;
            //cout << i << " " << situation[i] << endl;
        }
        if (situation[i] == worse && found_better == 0)
        //worse comes before better
        {
            //cout << "erasing (" << better << "," << worse << ")" << endl;
            consistent[pos].first = -1; //mark pair as inconsistent
        }
    }
}
