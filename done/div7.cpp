#include <iostream>
using namespace std;

int N;
int cows[50002];
int track[7];

int main()
{
    cin>>N;
    int a;
    for (int i=1; i<=N; i++) {
        cin>>a; a=a%7; cows[i]=a;
        cows[i]+=cows[i-1];;
    }
    int ans=0;
    for (int i=1; i<=N; i++) {
        a=cows[i]%7;
        if (track[a]==0) { track[a] = i; }
        if (track[a] != 0) {
            ans=max(ans, i-track[a]);
        }
    }
    cout<<ans<<'\n';
}