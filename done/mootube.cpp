#include <iostream>
#include <vector>
using namespace std;
typedef pair <int, int> ii;

int N, Q;
vector <ii> AL[5002];
bool visited[5002];

int solve(int v, int k)
{
    //cout<<v<<'\n';
    int ans=1;
    for (int i=0; i<AL[v].size(); i++) {
        int next=AL[v][i].first; int r=AL[v][i].second;
        if (r >= k && !visited[next]) {
            visited[next]=true;
            ans+=solve(next, k);
        }
    }
    return ans;
}

void clear()
{
    for (int i=0; i<5002; i++) visited[i]=false;
}

int main()
{
    cin>>N>>Q;
    for (int i=0; i<N-1; i++) {
        int p, q, r; cin>>p>>q>>r;
        AL[p].push_back(make_pair(q, r));
        AL[q].push_back(make_pair(p, r));
    }
    for (int i=0; i<Q; i++) {
        int v, k; cin>>k>>v;
        visited[v]=true;
        int ans=solve(v, k); cout<<ans-1<<'\n';
        clear();
    }
}