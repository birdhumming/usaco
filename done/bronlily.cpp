#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int m, n, m1, m2;
int pond[31][31];

int main()
{
    cin>>m>>n>>m1>>m2;
    ii start, end;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            int x; cin>>x;
            if (x==0 || x==2) {
                pond[i][j]=0;
            }
            else {
                pond[i][j]=1;
            }
            if (x==3) {
                start.first=i; start.second=j;
                pond[i][j]=0;
            }
            if (x==4) {
                end.first=i; end.second=j;
            }
        }
    }
    int dx[8]={m1, m1, m2, -1*m2, -1*m1, -1*m1, m2, -1*m2};
    int dy[8]={m2, -1*m2, m1, m1, m2, -1*m2, -1*m1, -1*m1};

    queue <iii> q;
    q.push(make_pair(start, 0));
    while (!q.empty()) {
        int cx=q.front().first.first;
        int cy=q.front().first.second;
        int ind=q.front().second;
        if (cx==end.first && cy==end.second) {
            cout<<ind<<'\n';
            return 0;
        } 
        for (int i=0; i<8; i++) {
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            if (nx >= 0 && nx < m && ny >=0 && ny < n) {
                if (pond[nx][ny]==1) {
                    q.push(make_pair(make_pair(nx, ny), ind+1));
                    pond[nx][ny]=0;
                    //cout<<nx<<" "<<ny<<'\n';
                }
            }
        }
        q.pop();
    }
    cout<<"here\n";
}