#include <iostream>
#include <queue>
using namespace std;

void solve() 
{
    typedef pair<int, int> ii;
    int dx[4]={1, 0, -1, 0};
    int dy[4]={0, 1, 0, -1};

    int n; cin>>n;
    char field[1001][1001];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>field[i][j];
        }
    }

    int ans=0;
    queue <ii> q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (field[i][j]=='*') {
                ans++;
                q.push(make_pair(i, j));
                field[i][j]='.';
                while (!q.empty()) {
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for (int ind=0; ind<4; ind++) {
                        int nx=x+dx[ind];
                        int ny=y+dy[ind];
                        if (nx>=0 && nx<n && ny>=0 && ny<n) {
                            if (field[nx][ny]=='*') {
                                q.push(make_pair(nx, ny));
                                field[nx][ny]='.';
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<'\n';
}

int main() 
{
    solve();
}