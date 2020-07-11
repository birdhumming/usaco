#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N; long long B;
vector <int> store;

long long shift(long long x)
{
    long long temp= (x>>1)  + ((x%2) << (N-1));
    return x ^ temp;
}

void print(long long x)
{
    vector <int> w;
    while (x != 0) {
        w.push_back(x%2);
        x /= 2;
    }
    if (w.size() < N) {
        for (int i=0; i<N-w.size(); i++) cout<<0<<' ';
    }
    for (int i=w.size()-1; i>=0; i--) cout<<w[i]<<' ';
    cout<<'\n';
}

int main()
{
    cin>>N>>B;
    long long s=0;
    for (int i=N-1; i>0; i--) {
        int x=0; cin>>x;
        s+=x *pow(2, i);
    }
    
    long long sp=s;
    for (int i=0; i<20; i++) {
        print(sp);
        sp=shift(sp);
    }
}