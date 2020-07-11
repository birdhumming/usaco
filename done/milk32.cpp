#include <iostream>
using namespace std;

int A, B, C;
int track[21][21];

void solve(int c, int b)
{
    if (track[c][b]==1) return;
    track[c][b]=1;
    int a=C-(c+b);
    
    if (c > A-a) solve(c-(A-a), b); //c -> a
    else solve(0, b);

    if (c > B-b) solve(c-(B-b), B); //c -> b
    else solve(0, c+b);

    if (b > A-a) solve(c, b-(A-a)); //b -> a
    else solve(c, 0);

    if (b > C-c) solve(C, b-(C-c)); //b -> c
    else solve(b+c, 0);

    if (a > B-b) solve(c, B); //a -> b
    else solve(c, a+b);

    if (a > C-c) solve(C, b);
    else (solve(a+c, b));
}

int main()
{
    cin>>A>>B>>C;

    solve(C, 0);

    for (int i=0; i<=20; i++) {
        for (int j=0; j<=20; j++) {
            if (track[i][j]==1 && i+j==C) {
                cout<<i<<' ';
            }
        }
    }

}