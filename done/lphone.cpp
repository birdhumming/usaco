#include <iostream>
#include <queue>
using namespace std;
typedef pair <int, int> ii;
typedef pair <ii, int> iii;

int w, h;
char grid[101][101];
bool visited[101][101];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

bool valid(int x, int y)
{
    if (x<0 || x>=h || y<0 || y>=w) return false;
    if (grid[x][y]=='*') return false;
    return true;
}

int main()
{
    cin>>w>>h;
    ii cow1, cow2; bool found=false;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin>>grid[i][j];
            if (grid[i][j]=='C' && found==false) {
                cow1.first=i; cow1.second=j;
                found=true;
            }
            if (grid[i][j]=='C' && found==true) {
                cow2.first=i; cow2.second=j;
            }
        }
    }

    queue <iii> q;
    q.push(make_pair(cow1, 0));
    while (!q.empty()) {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int ind=q.front().second;
        q.pop();
        for (int i=0; i<4; i++) {
            int dist=1;
            while (valid(x+ dist*dx[i], y+ dist*dy[i])) {
                int nx=x+ dist*dx[i];
                int ny=y+ dist*dy[i];
                if (nx==cow2.first && ny==cow2.second) {
                    cout<<ind<<'\n';
                    return 0;
                }
                if (!visited[nx][ny]) {
                    q.push(make_pair(make_pair(nx, ny), ind+1));
                    visited[nx][ny]=true;
                }
                dist++;
            }
        }
    }
}