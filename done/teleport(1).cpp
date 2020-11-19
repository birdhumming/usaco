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

int n;
ll ans = 0, tmp = 0, tot, la;
ii e[100010];

bool comp(ii a, ii b) {
    return a.ss < b.ss;
}

map<ll, int> vis;

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    scanf("%d", &n);
    FOR1(n) {
        int a, b; scanf("%d%d", &a, &b);
        ans += abs(a - b);
        if (abs(a) >= abs(a - b)) continue;

        vis[b] += 2;

        if (a < 0) {
            if (b <= a) vis[2 * a]--, vis[2 * (b - a)]--;
            else vis[0]--, vis[2 * b]--;
        }
        else {
            if (a <= b) vis[2 * a]--, vis[2 * (b - a)]--;
            else vis[0]--, vis[2 * b]--;
        }
    }

    tmp = ans;
    for (auto x : vis) {
        tmp += tot * (x.ff - la);
        la = x.ff;
        tot += x.ss;
        ans = min(ans, tmp);
    }
    cout<<ans<<endl;
    return 0;
}