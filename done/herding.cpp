#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> cows;

bool is_grouped() 
{
    if (cows[N-2]-cows[0] == N-2) return true;
    if (cows[N-1]-cows[1] == N-2) return true;
    return false;
}

int main()
{
    cin>>N;
    cows.resize(N); 
    for (int i=0; i<N; i++) cin>>cows[i];
    sort(cows.begin(), cows.end());

    int maxnum = max(cows[N-1]-cows[1], cows[N-2]-cows[0])-N+2;

    int endInd=0;
    int minnum=2000000000;
    for (int startInd=0; startInd<N; startInd++) {
        while (endInd+1<N && cows[endInd+1]-cows[startInd]+1 <= N) {
            endInd++;
        }
        minnum = min(minnum, N-(endInd-startInd+1));
    }
    if (is_grouped()) {
        if (cows[1]-cows[0]>2 || cows[N-1]-cows[N-2] > 2) {
            minnum=2;
        }
        else minnum=1;
    }
    if (cows[N-1]-cows[0]==N-1) minnum=0;
    cout<<minnum<<'\n'<<maxnum<<'\n';
}