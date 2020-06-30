#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N, K;
typedef pair< pair<long, long>, long > lll;
lll AB[50001];

bool comp(lll a, lll b)
{
    return a.first.first>b.first.first;
}

int main()
{
    cin>>N>>K;
    for (int i=0; i<N; i++) {
        cin>>AB[i].first.first>>AB[i].first.second;
        AB[i].second=i+1;
    }
    sort(AB, AB+N, comp);
    int m=0, ans;
    for (int i=0; i<K; i++) {
        if (AB[i].first.second > m) {
            m=AB[i].first.second;
            ans=AB[i].second;
        }
    }
    cout<<ans<<'\n';
}