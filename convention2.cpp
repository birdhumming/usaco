#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;
typedef pair <int, pair<int, int> > iii;

bool comp (iii a, iii b)
{
    return a.second.first < b.second.first;
}

int main()
{
    int N; cin>>N;
    iii cows[100001];
    for (int i=0; i<N; i++) {
        iii temp;
        temp.first=i;
        cin>>temp.second.first>>temp.second.second;
        cows[i]=temp;
    }
    sort(cows, cows+N, comp);

    set <iii> waiting;
    int ans=0;
    int endtime=cows[0].second.first+cows[0].second.second;
    for (int i=1; i<N; i++) {
        waiting.insert(cows[i]);
        if (cows[i].second.first >= endtime) {
            set <iii>::iterator seti = waiting.begin();
            ans+=endtime-*seti.second.first;
            erase(0);
            endtime=*seti.second.first+*seti.second.second;
        }
    }
    cout<<ans<<'\n';
}