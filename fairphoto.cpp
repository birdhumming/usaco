#include <iostream>
#include <algorithm>
using namespace std;
typedef pair <int, int> ii;

int N;
ii cows[100001];
int track[2]={0, 0}; //position of first 1, first -1

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
    for (int i=1; i<=N; i++) { 
        cows[i].second+=cows[i-1].second;
    }
    int ans=0;
    for (int i=1; i<=N; i++) {
        int pos=cows[i].first;
        int type=cows[i].second;
        //cout<<pos<<" "<<type<<'\n';
        if (type==1 && track[0]==0) {
            track[0]=i;
        }
        if (type==-1 && track[1]==0) {
            track[1]=i;
        }
        if (type==1 && track[0]!=0) {
            int co=track[0]+1;
            ans=max(ans, pos-cows[co].first);
            //cout<<"current pos = "<<pos<<", track[0] = "<<track[0]<<'\n';
        }
        if (type==-1 && track[1]!=0) {
            int co=track[1]+1;
            ans=max(ans, pos-cows[co].first);
            //cout<<"current pos = "<<pos<<", track[1] = "<<track[1]<<'\n';
        }   
    }
    int s=0, count=0;
    for (int i=1; i<=N; i++) {
        if (cows[i].second==1 && s==0) {
            s=i;
        }
        if (cows[i].second==-1 && cows[i-1].second==1) {
            ans=max(ans, cows[i-1].first-cows[s].first);
            s=0;
        }
    }
    for (int i=1; i<=N; i++) {
        if (cows[i].second==-1 && s==0) {
            s=i;
        }
        if (cows[i].second==1 && cows[i-1].second==-1) {
            ans=max(ans, cows[i-1].first-cows[s].first);
            s=0;
        }
    }
    cout<<ans<<'\n';
}

