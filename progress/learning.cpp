#include <iostream>
#include <string>
using namespace std;
typedef pair<int, string> is;

int N;
is cows[50003];
bool comp(is a, is b) { return a.first<b.first; }

int main()
{
    int A, B;
    cin>>N>>A>>B;
    for (int i=1; i<=N; i++) cin>>cows[i].second>>cows[i].first;
    cows[0].second="NS"; cows[0].first=0;
    cows[N+1].second="NS"; cows[N+1].first=1000000001;
    sort(cows, cows+N+1, comp);
    //for (int i=0; i<N+2; i++) cout<<cows[i].first<<" ";

    int ans=0;

    for (int i=0; i<N+1; i++) {
        int mid=(cows[i].first+cows[i+1].first)/2;
        if (cows[i].second == "S") {
            int start=max(A, cows[i].first+1);
            int end=min(B, mid);
            if (end>=start) ans+= end-start+1;
            //cout<<"i = "<<cows[i].first<<" and 'S', ans = "<<ans<<'\n';
        }
        if (cows[i+1].second == "S") {
            int start=max(A, mid+1);
            int end=min(B, cows[i+1].first);
            if (end>=start) ans+= end-start+1;
            //cout<<"i+1 = "<<cows[i+1].first<<" and 'S', ans = "<<ans<<'\n';
        }
        if (cows[i].second=="NS" && cows[i+1].second=="S" && (cows[i+1].first-cows[i].first)%2==0 && i!=0 && i+1!=N+1) {
            ans++;
            //cout<<"i = "<<cows[i].first<<" and NS, i+1 = S, ans = "<<ans<<'\n';
        }
    }
    cout<<ans<<'\n';
}