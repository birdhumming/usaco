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
#define f first
#define s second

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
vector<vc> g;
bool visited_size[1010][1010];
bool visited_perim[1010][1010];

int dfs_size(int x, int y) {
    if (!in_bounds(x, y, n, n) || g[x][y] == '.' || visited_size[x][y]) return 0;
    visited_size[x][y] = true;

    int size = 1;
    FOR(4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        size += dfs_size(nx, ny);
    }
    return size;
}

int dfs_perim(int x, int y) {
    //cout<<"x = "<<x<<", y = "<<y<<endl;
    if (!in_bounds(x, y, n, n) || g[x][y] == '.' || visited_perim[x][y]) return 0;
    visited_perim[x][y] = true;

    int perim = 0;
    FOR(4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!in_bounds(nx, ny, n, n) || g[nx][ny] == '.')
            perim++;
    }

    FOR(4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        perim += dfs_perim(nx, ny);
    }

    return perim;
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    scanf("%d", &n); g.rz(n, vc(n));
    FOR(n) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) g[i][j] = s[j];
    }

    vector<ii> res;
    int max_size = 0;
    FOR(n) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == '#' && !visited_size[i][j]) {
                int size = dfs_size(i, j);
                int perim = dfs_perim(i, j);
                res.pb(mp(size, perim));
                max_size = max(max_size, size);
            }
        }
    }

    int minp = INT_MAX;
    for (auto x : res) {
        if (x.f == max_size && x.s < minp) minp = x.s;
    }
    cout<<max_size<<' '<<minp<<endl;
    return 0;
}