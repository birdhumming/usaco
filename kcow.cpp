#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int X, Y;
int grid[151][151];
int dx[8]={2, 2, 1, -1, -2, -2, -1, 1};
int dy[8]={-1, 1, 2, 2, 1, -1, -2, -2};

int main()
{
    cin>>X>>Y;
    ii start, end;
    for (int i=0; i<Y; i++) {
        for (int j=0; j<X; j++) {
            char c; cin>>c;
            if (c=='.') grid[i][j]=0;
            if (c=='*') grid[i][j]=1;
            if (c=='K') {
                grid[i][j]=1;
                start.first=i; start.second=j;
            }
            if (c=='H') {
                grid[i][j]=0;
                end.first=i; end.second=j;
            }
        }
    }

    queue<iii> q;
    q.push(make_pair(start, 0));
    while (!q.empty()) {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int d=q.front().second;
        //cout<<x<<' '<<y<<'\n';
        q.pop();
        if (x==end.first && y==end.second) {
            cout<<d<<'\n';
            return 0;
        }
        for (int i=0; i<8; i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if (nx >= 0 && nx < Y && ny >= 0 && ny < X) {
                if (grid[nx][ny] == 0) {
                    grid[nx][ny]=1;
                    q.push(make_pair(make_pair(nx, ny), d+1));
                }
            }
        }
    }
}