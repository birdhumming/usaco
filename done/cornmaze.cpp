#include <iostream>
#include <queue>
#include <cctype>
using namespace std;
typedef pair <int, int> ii;
typedef pair<ii, int> iii;

int R, C;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

char maze[301][301];
bool visited[301][301];

ii find_portal(char p, int cx, int cy) {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (maze[i][j]==p && !(i==cx && j==cy)) {
                ii temp = make_pair(i, j);
                return temp;
            }
        }
    }
}

int main()
{
    cin>>R>>C;
    ii start;
    ii end;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin>>maze[i][j];
            if (maze[i][j]=='@') {
                start.first=i;
                start.second=j;
                visited[i][j]=true;
            }
            if (maze[i][j]=='=') {
                end.first=i;
                end.second=j;
            }
        }
    }
    queue <iii> q;
    q.push(make_pair(start, 0));
    visited[start.first][start.second]=true;
    while (!q.empty()) {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int moves=q.front().second;
        //cout<<x<<" "<<y<<'\n';
        if (maze[x][y]=='=') {
            cout<<moves<<'\n';
            return 0;
        }
        q.pop();
        for (int i=0; i<4; i++) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if (nx>=0 && nx<R && ny>=0 && ny<C) {
                if (maze[nx][ny]!='#' && !visited[nx][ny]) {
                    if (isalpha(maze[nx][ny])) {
                        char p=maze[nx][ny];
                        //cout<<p<<'\n';
                        ii op=find_portal(p, nx, ny);
                        //cout<<"OP "<<op.first<<" "<<op.second<<'\n';
                        q.push(make_pair(op, moves+1));
                        visited[nx][ny]=true;
                    }
                    else if (maze[nx][ny]=='.' || maze[nx][ny]=='=') {
                        q.push(make_pair(make_pair(nx, ny), moves+1));
                        visited[nx][ny]=true;
                    }
                }
            }
        }
    }
    //cout<<"END\n";
}