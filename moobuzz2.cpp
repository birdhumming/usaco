#include <iostream>
#include <fstream>

using namespace std;

int N;

int moobuzz(int N)
{
    int fifteens = N/15;
    int threes = N/3;
    int fives = N/5;
    int divisors = threes+fives-fifteens;
    if (divisors)
    {
        for (int i = 0; i < divisors; i++)
        {
            N+=1;
            if (N%5 == 0 || N%3 == 0) { divisors+=1; }
        }
    }
    return N;
}

int main()
{
    ifstream fin ("moobuzz.in");
    ofstream fout ("moobuzz.out");
    fin>>N;
    fout<<moobuzz(N)<<'\n';
}