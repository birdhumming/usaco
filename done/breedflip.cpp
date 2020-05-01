/*
problem: Farmer John ordered N cows of two different breeds.
    he ordered a specific string of Hs (Holsteins) and Gs (Guernseys), but got a different string than he ordered.
    his mad scientist cousin, Ben, has made John a cow-flipinator. it takes a subset of cows and flips their breed,
    turning H to G and G to H.
given:
    int N = the number of cows (3-1000)
    string A = what Farmer John ordered
    string B = what Farmer John got
do: find the minimum number of times the flipinator needs to be used to turn B into A.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int N;
string A;
string B;

int string_flip(string A, string B);
vector <int> runs; //one run is a subset in which every letter is flipped (can be length 1)

int main()
{
    ifstream fin ("breedflip.in");
    ofstream fout ("breedflip.out");

    fin >> N >> A >> B;
    
    fout << string_flip(A, B) << endl;
}

int string_flip(string A, string B)
{
    int started = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] != B[i])
        {
            started++;
        }
        else
        {
            if (started != 0)
            {
                runs.push_back(started);
            }
            started = 0;
        }
    }
    return runs.size(); //flipinator is applied to each of the runs
}