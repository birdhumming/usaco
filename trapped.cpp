#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vii vector<ii>
#define pb push_back
#define rz resize
#define mp make_pair
#define ff first
#define ss second

#define FOR(n) for (int i = 0; i < n; i++)
#define FOR1(n) for (int i = 1; i <= n; i++)
#define RFOR(n) for (int i = n - 1; i >= 0; i--)
#define DFOR(n, m) FOR(n) for (int j = 0; j < m; j++)

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int ddy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

bool in_bounds(int x, int y, int n, int m) {
    if (x >= 0 && x < n && y >= 0 && y < m) return true;
    return false;
}

int n, b;
set<ii> haybales;

bool comp(ii a, ii b) {
    return a.ff > b.ff;
}

int main() {
    //freopen("trapped.in", "r", stdin);
    //freopen("trapped.out", "w", stdout);
    scanf("%d%d", &n, &b);
    FOR(n) {
        int s, p; scanf("%d%d", &s, &p);
        haybales.insert(mp(p, s));
    }

    for (auto x : haybales) cout<<x.ff << ' '<<x.ss<<endl;

    int ans = -1;
    while (haybales.size() > 1) {
        cout<<"SSTRATING\n";
        for (auto x : haybales) cout<<x.ff << ' '<<x.ss<<endl;
        ii x = mp(b, 0);
        auto l = upper_bound(haybales.begin(), haybales.end(), x);
        l--;
        cout<<"l first "<<l->first<<", l second "<<l->second<<endl;
        auto r = upper_bound(haybales.begin(), haybales.end(), x);
        cout<<"r first "<<r->first<<", r second "<<r->second<<endl;
        if (l == haybales.end() || r == haybales.end()) break;

        int dist = r->first - l->first;
        cout<<"dist = "<<dist<<endl;
        int s1 = l->second, s2 = r->second;
        if (dist > s1 && dist > s2) {
            haybales.erase(l), haybales.erase(r);
            int a1 = dist - s1 + 1, a2 = dist - s2 + 1;
            if (ans == -1 || (ans != -1 && ans > a1)) ans = a1;
            if (ans == -1 || (ans != -1 && ans > a2)) ans = a2;
        }
        else if (dist > s1) {
            haybales.erase(l);
            int a1 = dist - s1 + 1;
            if (ans == -1 || (ans != -1 && ans > a1)) ans = a1;
        }
        else if (dist > s2) {
            haybales.erase(r);
            int a2 = dist - s2 + 1;
            if (ans == -1 || (ans != -1 && ans > a2)) ans = a2;
        }
        else {
            break;
        }
    }

    cout<<ans<<endl;
    return 0;
}