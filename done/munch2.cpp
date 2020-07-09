#include <iostream>
#include <queue>
using namespace std;
typedef pair <int, int> ii;
typedef pair <ii, int> iii;

int R, C;
char grid[101][101];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

int main()
{
    cin>>R>>C;
    ii cow;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin>>grid[i][j];
            if (grid[i][j]=='C') {
                cow.first=i; cow.second=j;
                grid[i][j]='*';
            }
        }
    }

    queue <iii> q;
    q.push(make_pair(cow, 0));
    while (!q.empty()) {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int moves=q.front().second;
        if (x==0 && y==0) {
            cout<<moves<<'\n';
            return 0;
        }
        q.pop();
        for (int i=0; i<4; i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if (nx>=0 && nx<R && ny>=0 && ny<C) {
                if (grid[nx][ny]=='.' || grid[nx][ny]=='B') {
                    q.push(make_pair(make_pair(nx, ny), moves+1));
                    grid[nx][ny]='*';
                }
            }
        }
    }
}