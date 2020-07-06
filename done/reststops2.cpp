#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair <long, long> ii;

int main()
{
    int L, N, rF, rB;
    cin>>L>>N>>rF>>rB;
    vector <ii> stops;
    stops.resize(N+1);
    for (int i=1; i<=N; i++) cin>>stops[i].first>>stops[i].second;
    stops[0].first=0; stops[0].second=0;
    int r=rF-rB;

    long curbest=0;
    long long ans=0;
    for (int i=N; i>=1; i--) {
        curbest=max(curbest, stops[i].second);
        ans+=curbest * (stops[i].first - stops[i-1].first);
    }
    cout<<ans*r<<'\n';

}