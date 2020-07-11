#include <iostream>
using namespace std;
typedef pair <int, int> ii;
typedef pair<ii, ii> pii;

int main()
{
    int n; cin>>n;
    int xmin=10001, xmax=-10001;
    pii r[10];
    for (int i=0; i<n; i++) {
        ii t, u;
        cin>>t.first>>t.second>>u.first>>u.second;
        pii[i]=make_pair(t, u);

        xmin=min(t.first, xmin);
        xmax=max(u.first, xmax);
    }
    
    int ans=0;

}