#include <iostream>
#include <algorithm>
using namespace std;
typedef pair <int, int> ii;

int N;
ii cows[100001];
int track[300000];

int main()
{
    cows[0].second=0;
    cin>>N;
    char c;
    for (int i=1; i<=N; i++) {
        cin>>cows[i].first>>c;
        if (c=='G') { cows[i].second=1; }
        if (c=='H') { cows[i].second=-1; }
    }
    sort(cows+1, cows+N+1);
    int s=0, ans=0;
    for (int i=1; i<=N; i++) {
        if (cows[i].second==1 && s==0) {
            s=i;
        }
        if (cows[i].second==1 && cows[i+1].second==-1){
            ans = max(ans, cows[i].first-cows[s].first);
            s=0;
        }
    }
    for (int i=1; i<=N; i++) {
        if (cows[i].second==-1 && s==0) {
            s=i;
        }
        if (cows[i].second==-1 && cows[i+1].second==1){
            ans = max(ans, cows[i].first-cows[s].first);
            s=0;
        }
    }
    for (int i=1; i<=N; i++) { 
        cows[i].second+=cows[i-1].second;
    }
    int gs=0, hs=0; //first G cow (1), first H cow (-1)
    for (int i=1; i<=N; i++) {
        int pos=cows[i].first;
        int psum=cows[i].second;
        int tsum; //temp sum
        if (psum<0) { tsum=psum+200000; }
        else tsum=psum;
        if (track[tsum] == 0) { track[tsum] = i; }
        else if (track[tsum] != 0) {
            int c=track[tsum]+1;
            ans=max(ans, pos-cows[c].first);
            //cout<<ans<<'\n';
        }
    }
    cout<<ans<<'\n';
}

