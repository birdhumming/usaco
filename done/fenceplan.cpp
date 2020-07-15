#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

int N, M;
ii cows[100002];
vector<int> AL[100002];
bool visited[100002];
int sx, bx, sy, by;

void solve(int cow)
{
    visited[cow]=true;
    int x=cows[cow].first; int y=cows[cow].second;
    sx=min(sx, x); sy=min(sy, y);
    bx=max(bx, x); by=max(by, y);
    for (int i=0; i<AL[cow].size(); i++) {
        int nc=AL[cow][i];
        if (!visited[nc]) {
            solve(nc);
        }
    }
}

int main()
{
    cin>>N>>M;
    for (int i=1; i<=N; i++) cin>>cows[i].first>>cows[i].second;
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    long ans=1000000000000;
    for (int i=1; i<=N; i++) {
        if (!visited[i]) {
            sx=100000001;
            bx=0;
            sy=100000001;
            by=0;
            solve(i);
            if (ans>2*(bx-sx+by-sy)) ans=2*(bx-sx+by-sy);
        }
    }
    cout<<ans<<'\n';
}