#include <iostream>
using namespace std;

int N, K, B;
int road[100002];

int main()
{
    cin>>N>>K>>B;
    int temp;
    for (int i=0; i<N; i++) {
        cin>>temp;
        road[temp]=1;
    }
    for (int i=1; i<=N; i++) {
        road[i]+=road[i-1];
    }
    int ans=10000000;
    for (int i=1; i<=N; i++) {
        temp=road[i+K-1]-road[i];
        ans=min(ans, temp);
        if (i+K-1==N) break;
    }
    cout<<ans<<'\n';
}