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

const int N = 1e5 + 10;
int n, m;
int p[N];
struct cow {
    int x, y;
} cows[N];
unordered_map<int, vector<int> > track;

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int perimeter(vector<int> v) {
    int xmin = INT_MAX, ymin = INT_MAX, xmax = INT_MIN, ymax = INT_MIN;
    for (int i : v) {
        xmin = min(cows[i].x, xmin);
        ymin = min(cows[i].y, ymin);
        xmax = max(cows[i].x, xmax);
        ymax = max(cows[i].y, ymax);
    }
    int perim = 2 * (xmax - xmin) + 2 * (ymax - ymin);
    return perim;
}

int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR1(n) {
        int x, y; scanf("%d%d", &x, &y);
        cows[i].x = x, cows[i].y = y;
    }

    FOR(n + 1) p[i] = i;
    FOR(m) {
        int a, b; scanf("%d%d", &a, &b);
        p[find(a)] = find(b);
    }

    FOR1(n) track[find(i)].pb(i);
    
    int ans = INT_MAX;
    for (auto x : track) {
        int tmp = perimeter(x.second);
        ans = min(ans, tmp);
    }
    cout<<ans<<endl;
    return 0;
}