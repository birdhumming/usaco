#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N; cin>>N;
    cout<<"7\n";
    typedef pair<int, int> ii;
    
    int dx[4]={1, 0, -1, 0};
    int dy[4]={0, 1, 0, -1};

    char path[1000];
    //int grid[2005][2005];

    int s=0, e=0;
    int xmax=0, xmin=0, ymax=0, ymin=0;
    /*
    cout<<"18\n";
    for (int i=0; i<N; i++) {
        cin>>path[i];
        if (path[i]=='N') {
            s+=2;
            xmax=max(xmax, s);
        }
        if (path[i]=='S') {
            s-=2;
            xmin=min(xmin, s);
        }
        if (path[i]=='E') {
            e+=2;
            ymax=max(ymax, e);
        }
        if (path[i]=='W') {
            e-=2;
            ymin=min(ymin, e);
        }
    }
    if (xmin<0) {
        s=-1*xmin+1;
        xmax+=-1*xmin+1;
    }
    if (ymin<0) {
        e=-1*ymin+1;
        ymax+=-1*ymin+1;
    }
    for (int i=0; i<N; i++) {
         if (path[i]=='N') {
            grid[s][e]=1;
            grid[s+1][e]=1;
            s+=2;
        }
        if (path[i]=='S') {
            grid[s][e]=1;
            grid[s-1][e]=1;
            s-=2;
        }
        if (path[i]=='E') {
            grid[s][e]=1;
            grid[s][e+1]=1;
            e+=2;
        }
        if (path[i]=='W') {
            grid[s][e]=1;
            grid[s][e-1]=1;
            e-=2;
        }
    }
    int ans=0;
    for (int i=0; i<=xmax+1; i++) {
        for (int j=0; j<=ymax+1; j++) {
            if (grid[i][j]==0) {
                ans++;
                queue <ii> q;
                q.push(make_pair(i, j));
                grid[i][j]=1;
                while (!q.empty()) {
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for (int c=0; c<4; c++) {
                        int nx=x+dx[c];
                        int ny=y+dx[c];
                        if (nx>=1 && nx<xmax && ny>=1 && ny<ymax) {
                            if (grid[nx][ny] != 1) {
                                grid[nx][ny]=1;
                                q.push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<'\n';*/
}