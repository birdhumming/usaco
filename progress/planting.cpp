#include <iostream>
#include <vector>
using namespace std;
typedef pair <int, int> ii;
typedef pair<ii, ii> pii;

int n;
pii r[10];
vector <ii> coords;

long solve(int x)
{
    long ans=0;
    for (int i=0; i<n; i++) {
        int lx=r[i].first.first; int rx=r[i].second.first;
        int ly=r[i].first.second; int ry=r[i].second.second;
        if (lx <= x && rx >= x) {
            ans+=ly-ry;
        }
    }
    return ans;
}

int main()
{
    cin>>n;
    for (int i=0; i<n; i++) {
        ii t, u;
        cin>>t.first>>t.second>>u.first>>u.second;
        pii[i]=make_pair(t, u);

        coords.push_back(t); coords.push_back(u);
    }
    sort(coords.begin(), coords.end());

    long ans=0;
    for (int i=0; i<coords.size(); i++) {
        int x=coords[i].first;
        int ylen=solve(x);
    }


}