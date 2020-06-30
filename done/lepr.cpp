#include <iostream>
#include <fstream>
using namespace std;

int N, torus[201][201];
int dx[8]={1, 0, -1, 1};
int dy[8]={0, 1, -1, -1};

int main()
{
    ifstream fin ("lepr.in");
    fin>>N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            fin>>torus[i][j];
        }
    }
    int ans= -1000001;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int s=torus[i][j];
            int m=s;
            ans=max(ans, m);
            for (int k=0; k<4; k++) {
                for (int l=1; l<=N-1; l++) {
                    int x=i+(l*dx[k]);
                    int y=j+(l*dy[k]);
                    if (x>=N) x=x%N;
                    if (y>=N) y=y%N;
                    if (x<0) x+=N;
                    if (y<0) y+=N;
                    //cout<<"s = "<<s<<", adding "<<torus[x][y]<<'\n';
                    m+=torus[x][y];
                    //cout<<m<<'\n';
                    ans=max(ans, m);
                }
                m=s;
            }
        }
    }
    cout<<ans<<'\n';
}