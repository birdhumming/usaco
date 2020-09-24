#include <iostream>
#include <unordered_map>
using namespace std;

int N, K;
unordered_map <int, int> u;

int main()
{
    cin>>N>>K;
    int g, x, max_dist=-1;
    for (int i=0; i<N; i++) {
        cin>>g>>x;
        u[x]=g;
        max_dist=max(max_dist, x);
    }
    long sum=0;
    int upp=min((2*K)+1, max_dist);
    for (int i=1; i<=upp; i++) {
        if (u.count(i)==1) {
            sum+=u[i];
        }
    }
    if (upp==max_dist) {
        cout<<sum<<'\n';
        return 0;
    }
    long ans=sum;
    for (int i=2; i<=max_dist; i++) {
        if (u.count(i-1)==1) {
            sum-=u[i-1];
        }
        if ((2*K)+i <= max_dist) {
            if (u.count((2*K)+i)==1) {
                sum+=u[(2*K)+i];
            }
        }
        //cout<<sum<<'\n';
        if (sum>ans) ans=sum;
    }
    cout<<ans<<'\n';
}