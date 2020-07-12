#include <iostream>
#include <cmath>
using namespace std;

int N; long long B;

long long shift(long long x)
{
    return x ^ ((x>>1) + ((x%2) << (N-1)));
}

int main()
{
    cin>>N>>B;
    long long start=0;
    for (int i=1; i<=N; i++) {
        int x; cin>>x;
        start+= x * pow(2, N-i);
    }
    long long cur=start;
    long long first_seen[65538];
    for (long long ml=B; ml>0; ml--) {
        first_seen[cur]=ml;
        cur=shift(cur);
        if (first_seen[cur] != 0) {
            ml %= (first_seen[cur]-ml+1);
        }
    }
    for (int i=N-1; i>=0; i--) {
        cout<<(cur>>i)%2<<'\n';
    }
}