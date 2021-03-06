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

const int N = 1e5 + 10;
int n;
int minY[N], maxY[N];
ii coords[N];

int main() {
    freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);
    scanf("%d", &n);
    FOR(n) scanf("%d%d", &coords[i].ff, &coords[i].ss);
    sort(coords, coords + n);

    minY[0] = coords[0].second;
    maxY[n - 1] = coords[n - 1].second;

    for (int i = 1; i < n; i++) {
        minY[i] = min(minY[i - 1], coords[i].ss);
    }
    for (int i = n - 2; i >= 0; i--) {
        maxY[i] = max(maxY[i + 1], coords[i].ss);
    }

    FOR(n) cout<<minY[i]<<' ';
    cout<<endl;
    FOR(n) cout<<maxY[i]<<' ';
    cout<<endl;

    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        if (minY[i] > maxY[i + 1]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
