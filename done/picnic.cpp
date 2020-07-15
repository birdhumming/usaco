#include <iostream>
#include <vector>
using namespace std;

int K, N, M;
vector <int> AL[1002];
vector <int> pastures_with_cows;
bool visited[1002];
int visitable[1002];

void dfs(int pos)
{
    visited[pos]=true;
    visitable[pos]++;
    for (int i=0; i<AL[pos].size(); i++) {
        int next=AL[pos][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void clear()
{
    for (int i=0; i<1002; i++) visited[i]=false;
}

int main()
{
    cin>>K>>N>>M;
    for (int i=0; i<K; i++) {
        int x; cin>>x;
        pastures_with_cows.push_back(x);
    }
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        AL[a].push_back(b);
    }
    int ans=0;
    for (int i=0; i<pastures_with_cows.size(); i++) {
        int cow=pastures_with_cows[i];
        dfs(cow);
        clear();
    }
    for (int i=0; i<=N; i++) {
        //cout<<visitable[i]<<'\n';
        if (visitable[i]==K) ans++;
    }
    cout<<ans<<'\n';
}