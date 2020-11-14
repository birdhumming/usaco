#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define vc vector<char>
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

int n, ans, sr, res = 1e8, rr, s;
ii a[100010];


int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    scanf("%d", &n); 
    FOR1(n) scanf("%d%d", &a[i].ff, &a[i].ss);
    sort(a + 1, a + n + 1);

    FOR1(n) {
        if (a[i].ss > sr) {
            rr = max(sr, a[i].ff);
            ans += a[i].ss - rr;
            sr = a[i].ss;
        }
    } 
    sr = 0, a[n + 1].ff = a[n].ss;
    FOR1(n) {
        if (a[i].ss <= sr) res = 0;
        else {
            s = min(a[i + 1].ff, a[i].ss) - max(a[i].ff, sr);
            res = min(res, s);
            sr = max(a[i].ss, sr);
        }
    }

    res = max(0, res);
    cout<<ans - res<<endl;
    return 0;
}


