#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;

int n, s;
int ocean[101][101];
vector <bool> visited;
vector <int> ans[101];

int main()
{
    cin>>n>>s;
    visited.resize(n+1);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>>ocean[i][j];
        }
    }

    queue <ii> q;
    q.push(make_pair(s, 0));
    visited[s]=true;
    ans[0].push_back(s);
    while (!q.empty()) {
        int pos=q.front().first;
        int ind=q.front().second;
        for (int i=1; i<=n; i++) {
            if (ocean[pos][i]==1 && visited[i]==false) {
                q.push(make_pair(i, ind+1));
                visited[i]=true;
                ans[ind+1].push_back(i);
            }
        }
        q.pop();
    }

    for (int i=0; i<101; i++) {
        if (ans[i].size() > 0) {
            sort(ans[i].begin(), ans[i].end());
            for (int j=0; j<ans[i].size(); j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
}