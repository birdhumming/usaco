#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int bales[1000001];

int main() 
{
    cin>>N>>K;
    int a, b;
    for (int i=0; i<K; i++) {
        cin>>a>>b;
        bales[a]++;
        bales[b+1]--;
    }
    for (int i=1; i<=N; i++) {
        bales[i]+=bales[i-1];
    }
    sort(bales+1, bales+N+1);
    cout<<bales[N/2+1]<<'\n';
}