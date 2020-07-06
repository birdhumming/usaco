#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N; cin>>N;
    string s;
    int nc=0, ec=0, sc=0, wc=0;
    for (int i=0; i<N; i++) {
        if (s[i]=='N') nc++;
        if (s[i]=='E') ec++;
        if (s[i]=='S') sc++;
        if (s[i]=='W') wc++;
    }
    int curx=1, cury=1;
    for (int i=0; i<N; i++) {
        char c=s[i];
        if (c=='N') {
            farm[curx][cury]=1;
            farm[curx+1][cury]=1;
            curx+=2;
        }
        if (c=='E') {
            farm[curx][cury]=1;
            farm[curx][cury+1]=1;
            cury+=2;
        }
        if (c=='S') {
            farm[curx][cury]=1;
            farm[curx-1][cury]=1;
            curx-=2;
        }
        if (c=='W') {
            farm[curx][cury]=1;
            farm[curx][cury-1]=1;
            cury-=2;
        }
    }
    for (int i=0; i<50; i++) {
        for (int j=0; j<50; j++) {
            cout<<farm[i][j]<<" ";
        }
        cout<<'\n';
    }
    int ans=0;
    for (int i=0; i<50; i++) {
        for (int j=0; j<50; j++) {
            if (farm[i][j] != 1) {
                //cout<<i<<" "<<j<<'\n';
                floodfill(i, j);
                ans++;
            }
        }
    }
    //cout<<ans<<'\n';
}