#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair <LL, LL> pll;

vector <pair< int, pll> > cows;
set <pll> w;

int main()
{
    int N; cin>>N;
    int a, t;
    for (int i=0; i<N; i++) {
        cin>>a>>t;
        cows.push_back(make_pair(a, make_pair(i,t)));
    }

    LL ans=0, end;
    int nextcow=1;
    sort(cows.begin(), cows.end());
    end=cows[0].first+cows[0].second.second;
    while (nextcow < N || w.size() > 0) {
        while (nextcow < N && cows[nextcow].first < end) {
            w.insert(make_pair(cows[nextcow].second.first, nextcow));
            nextcow++;
        }
        if (w.size() == 0 && nextcow < N) {
            end = cows[nextcow].first + cows[nextcow].second.second;
            nextcow++;
        }
        else if (w.size() > 0) {
            set <pll>::iterator it=w.begin();
            ans=max(ans, end-cows[it->second].first);
            end=end+cows[it->second].second.second;
            w.erase(it);
        }
    }
    cout<<ans<<'\n';
}