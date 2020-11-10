#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define FOR(n) for (int i = 0; i < n; i++)
#define FOR1(n) for (int i = 1; i <= n; i++)

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int ddy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

int c, n;
multiset<int> t;
vector<ii> ab;

int main() {
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    scanf("%d%d", &c, &n);
    FOR(c) {
        int x; scanf("%d", &x); t.insert(x);
    }
    FOR(n) {
        int a, b; scanf("%d%d", &a, &b);
        ab.pb(mp(b, a));
    }
    //cout << "hi\n";

    sort(ab.begin(), ab.end());
    int ans = 0;

    for (auto cow : ab) {
        //cout << cow.first << ' '<< cow.second<<endl;
    }

    for (auto cow : ab) {
        int a = cow.second, b = cow.first;
        auto chicken = t.lower_bound(a);
        if (chicken != t.end() && *chicken <= b) {
            //cout<<"chicken = "<<*chicken<<endl;
            ans++;
            t.erase(chicken);
        }
    }
    
    cout << ans << endl;
    return 0;
}
