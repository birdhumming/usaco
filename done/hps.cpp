#include <iostream>
#include <string>
using namespace std;

int N;
int g[100002][3];

bool bessie_wins(char B, char FJ) {
    if (B=='H' && FJ=='S') return true;
    if (B=='P' && FJ=='H') return true;
    if (B=='S' && FJ=='P') return true;
    return true;
}

int main() {
    cin>>N;
    char c;
    for (int i=1; i<=N; i++) {
        cin>>c;
        if (c=='H') { g[i][0]++; }
        if (c=='P') { g[i][1]++; }
        if (c=='S') { g[i][2]++; }
        g[i][0]+=g[i-1][0];
        g[i][1]+=g[i-1][1];
        g[i][2]+=g[i-1][2];
    }
    int ans=-1;
    for (int i=0; i<3; i++) {
        ans=max(ans, g[N][i]);
    }
    for (int i=2; i<=N; i++) {
        int lefth=g[i-1][0];
        int leftp=g[i-1][1];
        int lefts=g[i-1][2];
        int righth=g[N][0]-g[i-1][0];
        int rightp=g[N][1]-g[i-1][1];
        int rights=g[N][2]-g[i-1][2];
        ans=max(ans, lefth+rightp);
        ans=max(ans, lefth+rights);
        ans=max(ans, leftp+righth);
        ans=max(ans, leftp+rights);
        ans=max(ans, lefts+righth);
        ans=max(ans, lefts+rightp);
    }
    cout<<ans<<'\n';
}
