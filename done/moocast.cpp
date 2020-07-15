#include <iostream>
#include <vector>
using namespace std;
typedef pair <int, int> ii;
typedef pair <ii, ii> pii;

int N; 
vector <pii> cows;
vector <int> AL[202];
bool visited[202];

void check(int x, int y, int r, int ind) 
{
    for (int i=0; i<cows.size(); i++) {
        int cx=cows[i].first.first; int cy=cows[i].first.second;
        int cr=cows[i].second.first; int cind=cows[i].second.second;

        int nx=abs(x-cx); int ny=abs(y-cy);

        if (nx*nx + ny*ny <= r*r) AL[ind].push_back(cind);
        if (nx*nx + ny*ny <= cr*cr) AL[cind].push_back(ind);
    }
}

int dfs(int c)
{
    int ans=1;
    visited[c]=true;
    for (int i=0; i<AL[c].size(); i++) {
        int next=AL[c][i];
        if (!visited[next]) {
            ans+=dfs(next);
        }
    }
    return ans;
}

void clear()
{
    for (int i=0; i<202; i++) visited[i]=false;
}

int main()
{
    cin>>N; 
    for (int i=1; i<=N; i++) {
        int x, y, r; cin>>x>>y>>r;
        check(x, y, r, i);
        cows.push_back(make_pair(make_pair(x, y), make_pair(r, i)));
    }
    int ans=-1;
    for (int i=1; i<=N; i++) {
        ans=max(ans, dfs(i));
        clear();
    }
    cout<<ans<<'\n';
}
