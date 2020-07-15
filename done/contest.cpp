#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector <int> beats[101];
vector <int> beaten_by[101];
bool visited[101];

int dfs_up(int pos)
{
    //cout<<pos<<'\n';
    int ans=1;
    for (int i=0; i<beaten_by[pos].size(); i++) {
        int next=beaten_by[pos][i];
        //cout<<next<<'\n';
        if (!visited[next]) {
            visited[next]=true;
            ans+=dfs_up(next);
        }
    }
    return ans;
}

int dfs_down(int pos)
{
    //cout<<pos<<'\n';
    int ans=1;
    for (int i=0; i<beats[pos].size(); i++) {
        int next=beats[pos][i];
        //cout<<next<<'\n';
        if (!visited[next]) {
            visited[next]=true;
            ans+=dfs_down(next);
        }
    }
    return ans;
}

void clear()
{
    for (int i=0; i<101; i++) visited[i]=false;
}

int main()
{
    cin>>N>>M;
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        beats[a].push_back(b);
        beaten_by[b].push_back(a);
    }
    int ans=0;
    for (int i=1; i<=N; i++) {
        clear();
        int above=dfs_up(i)-1;
        clear();
        int below=dfs_down(i)-1;
        if (above+below == N-1) {
            ans++;
        }
    }
    cout<<ans<<'\n';
}