#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef pair<int, int> ii;

int N, M;
int barn[102][102];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

vector <ii> g[102][102];
bool visited[102][102];
bool light[102][102];

bool neighbors_visited(int x, int y)
{
    for (int i=0; i<4; i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (nx>0 && nx<=N && ny>0 && ny<=N) {
            if (visited[nx][ny]==true) return true;
        }
    }
    return false;
}

void solve(int x, int y)
{
    visited[x][y]=true;
    vector <ii> v=g[x][y];
    for (int i=0; i<v.size(); i++) {
        int nx=v[i].first; int ny=v[i].second;
        light[nx][ny]=true;
        if (!visited[nx][ny] && neighbors_visited(nx, ny)) {
            solve(nx, ny);
        }
    }
    for (int i=0; i<4; i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (nx>0 && nx<=N && ny>0 && ny<=N) {
            if (!visited[nx][ny] && light[nx][ny]) {
                solve(nx, ny);
            }
        }
    }
}

int main()
{
    cin>>N>>M;
    for (int i=0; i<M; i++) {
        int x, y; cin>>x>>y;
        ii u; cin>>u.first>>u.second;
        g[x][y].push_back(u);
    }
    light[1][1]=true;
    solve(1, 1);

    int ans=0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (light[i][j]) {
                //cout<<i<<" "<<j<<'\n';
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}