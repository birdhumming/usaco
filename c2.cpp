#include <iostream>
using namespace std;

void solve(int x)
{
    bool flag=true;
    int m=3;
    while (flag) {
        if (m > x/2 + 1) {
            cout<<1<<' '<<x-1<<'\n';
        }
        if (x%m == 0) {
            cout<<m<<' '<<x-m<<'\n';
            flag=false;
        }
        else m+=2;
    }
}

int main()
{
    int t; cin>>t;
    for (int i=0; i<t; i++) {
        long n; cin>>n;
        if (n%2==0) cout<<n/2<<' '<<n/2;
        else solve(n);
        if (i != t-1) cout<<'\n';
    }
}