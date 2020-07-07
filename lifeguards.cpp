#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair <int, int> ii;

int n;
vector <ii> lg;
vector <ii> first, second;
vector <ii> all;

bool within()
{
    for (int i=0; i<n; i++) {
        if (first[i].second != second[i].second) return false;
    }
    return true;
}

int main()
{
    cin>>n;
    for (int i=0; i<n; i++) {
        int x, y;
        cin>>x>>y;
        lg.push_back(make_pair(x, y));
        first.push_back(make_pair(x, i));
        second.push_back(make_pair(y, i));
        all.push_back(make_pair(x, i));
        all.push_back(make_pair(y, i));

    }
    sort(lg.begin(), lg.end());
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    sort(all.begin(), all.end());

    int covered=0, cur_start=lg[0].first;
    for (int i=1; i<n; i++) {
        if (lg[i].first > lg[i-1].second) {
            covered += lg[i-1].second-cur_start;
            cur_start=lg[i].first;
        }
        if (i==n-1) {
            covered+=lg[i].second-cur_start;
        }
    }
    if (within) {
        cout<<covered<<'\n';
        return 0;
    }

    queue <int> on_duty;
    for (int i=0; i<n; i++) {
        
    }
    

}