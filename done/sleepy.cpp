#include <iostream>
#include <fstream>
using namespace std;
int cows[101];

int main() {
    ifstream fin ("sleepy.in");
    ofstream fout ("sleepy.out");
    int N; fin>>N;
    for (int i=0; i<N; i++) fin>>cows[i];
    int ans=N-1;
    for (int i=N-2; i>=0; i--) {
        if (cows[i] < cows[i+1]) ans=i;
        else break;
    }
    fout<<ans;
}-