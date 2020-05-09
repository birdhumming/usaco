#include <iostream>
#include <fstream>

using namespace std;

int N;

int moobuzz(int N)
{
    int num = 1, count = 0;
    while (count!=N){
        if (num%3 && num%5){
            count++;
        }
        num++;
    }
    return num-1;
}

int main()
{
    ifstream fin ("moobuzz.in");
    ofstream fout ("moobuzz.out");
    fin>>N;
    fout<<moobuzz(N)<<'\n';
}