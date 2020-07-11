#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin>>n;
    vector <int> cows; cows.resize(n);
    vector <int> ans;
    int x;
    for (int i=0; i<n; i++) cin>>x>>cows[i];
    ans.push_back(cows[n-1]);
    for (int i=n-2; i>=0; i--) {
        int s=cows[i];
        if (s <= ans[ans.size()-1]) ans.push_back(s);
    }
    cout<<ans.size()<<'\n';
}