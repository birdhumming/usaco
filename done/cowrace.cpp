#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

int N, M;
vector<ii> b, e;

int main()
{
    cin>>N>>M;
    int max_time, b_time=0, e_time=0;
    for (int i=0; i<N; i++) {
        int s, t; cin>>s>>t;
        b_time+=t;
        b.push_back(make_pair(s, t));
    }
    for (int i=0; i<M; i++) {
        int s, t; cin>>s>>t;
        e_time+=t;
        e.push_back(make_pair(s, t));
    }
    b.push_back(make_pair(0, 1000000000)); e.push_back(make_pair(0, 1000000000));
    max_time=max(b_time, e_time);

    char first='c'; int ans=0;
    int b_dist=0, e_dist=0;
    b_time=0, e_time=0;
    int b_ind=0, e_ind=0;
    for (int i=0; i<max_time; i++) {
        if (b_time >= b[b_ind].second) {
            b_ind++;
            b_time=0;
        }
        if (e_time >= e[e_ind].second) {
            e_ind++;
            e_time=0;
        }
        b_time++;
        e_time++;
        b_dist+=b[b_ind].first; e_dist+=e[e_ind].first;
        //cout<<b_ind<<' '<<e_ind<<'\n';
        //cout<<b_dist<<' '<<e_dist<<'\n';

        if (first=='c') {
            if (b_dist>e_dist) first='b';
            else if (e_dist>b_dist) first='e';
        }
        else {
            if (b_dist > e_dist && first=='e') {
                ans++;
                first='b';
            }
            if (e_dist > b_dist && first=='b') {
                ans++;
                first='e';
            }
        }
    }
    cout<<ans<<'\n';
}
