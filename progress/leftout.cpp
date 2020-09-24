#include <iostream>
using namespace std;

int N;
int grid[1001][1001];

int count(int sx, int sy, int ex, int ey)
{
    for (int i=sx; i+sx<)
}

int main()
{
    cin>>N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            char c; cin>>c;
            if (c=='R') grid[i][j]=1;
            else grid[i][j]=0;
        }
    }

    for (int i=0; i<N; i++) {
        if (grid[i][0]) {
            for (int j=0; j<N; j++) {
                grid[i][j]=!grid[i][j];
            }
        }
        if (grid[0][i]) {
            for (int j=0; j<N; j++) {
                grid[j][i]=!grid[j][i];
            }
        }
    }
}