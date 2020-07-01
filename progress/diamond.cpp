#include <iostream>
#include <algorithm>
using namespace std;

long N, K, sizes[50001];
int sD[50001], bD[50001];

int main() 
{
    cin>>N>>K;
    for (int i=0; i<N; i++) {
        cin>>sizes[i];
    }
    sort(sizes, sizes+N);
    //cout<<"17\n";
    int lowb=0;
    for (int uppb=0; uppb<N; uppb++) {
        while (sizes[uppb] - sizes[lowb] > K) { lowb++; }
        sD[uppb] = max(sD[uppb-1], uppb-lowb+1);
    }
    //cout<<"24\n";
    int upp=N-1;
    for (int low=N-1; low>=0; low--) {
        while (sizes[upp] - sizes[low] > K)  { upp--; }
        bD[low] = max(bD[low+1], upp-low+1);
    }
    //cout<<"29\n";
    int ans=-1;
    for (int i=0; i<N-1; i++) {
        ans=max(ans, sD[i]+bD[i+1]);
    }
    cout<<ans<<'\n';
}