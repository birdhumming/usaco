#include <iostream>
#include <string>
using namespace std;

int N;
char grid[8][8];
int ans[8][8];

int convert(char c) {
    if ('0'<c && c<='9') {
        return c-'0';
    }
    if (c=='A') return 1;
    if (c=='T') return 10;
    if (c=='J') return 11;
    if (c=='Q') return 12;
    if (c=='K') return 13;
}

int main()
{
    cin>>N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            char c, d; cin>>c>>d;
            grid[i][j]=c;
        }
    }
    for (int i=N-1; i>=0; i--) {
        for (int j=0; j<N; j++) {
            ans[i][j]=max(ans[i+1][j], ans[i][j-1]) + convert(grid[i][j]);
        }
    }
    cout<<ans[0][N-1]<<'\n';
}