#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef int grid[101][101];
typedef pair<int, pair<int, int> > iii;

int N;
grid slices[101];

int dx[6]={1, -1, 0, 0, 0, 0};
int dy[6]={0, 0, 1, -1, 0, 0};
int dz[6]={0, 0, 0, 0, 1, -1};

void extend(int i, int j, int k)
{
    queue <iii> q;
    q.push(make_pair(i, make_pair(j, k)));
    while (!q.empty()) {
        int ci=q.front().first;
        int cj=q.front().second.first;
        int ck=q.front().second.second;
        //slices[ci][cj][ck]=0;
        //cout<<ci<<' '<<cj<<' '<<ck<<'\n';
        q.pop();
        for (int c=0; c<6; c++) {
            int ni=ci+dx[c];
            int nj=cj+dy[c];
            int nk=ck+dz[c];
            //cout<<ni<<' '<<nj<<' '<<nk<<'\n';
            if (ni>=0 && ni<N && nj>=0 && nj<N && nk>=0 && nk<N) {
                if (slices[ni][nj][nk]==1) {
                    slices[ni][nj][nk]=0;
                    q.push(make_pair(ni, make_pair(nj, nk)));
                }
            }
        }  
    } 
}

int main()
{
    cin>>N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                char c; cin>>c;
                if (c=='*') slices[i][j][k]=1;
                else slices[i][j][k]=0;
            }
        }
    }

    int ans=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                if (slices[i][j][k]==1) {
                    cout<<i<<' '<<j<<' '<<k<<'\n';
                    ans++;
                    extend(i, j, k);
                }
            }
        }
    }
    cout<<ans<<'\n';
}