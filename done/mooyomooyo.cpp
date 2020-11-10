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

int n, k;
vector<vc> g;
bool visited[110][110];

//floodfill unit to find size
int floodsize(int x, int y, char id) {
    //cout<<"f;oodsize\n";
    if (!in_bounds(x, y, 10, n) || visited[x][y] || g[x][y] != id) return 0;
    visited[x][y] = true;

    int size = 1;
    FOR(4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        size += floodsize(nx, ny, id);
    }
    return size;
}

//floodfill unit to all '0's
void floodfill(int x, int y, char id) {
    //cout<<"x = "<<x<<", y = "<<y<<", id = "<<id<<endl;
    if (!in_bounds(x, y, 10, n) || g[x][y] != id) return;
    g[x][y] = '0';

    FOR(4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        floodfill(nx, ny, id);
    }
}

bool solve() {
    //cout<<"solving\n";
    memset(visited, false, sizeof visited);

    int max_size = 0;
    FOR(10) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] != '0' && !visited[i][j]) {
                int size = floodsize(i, j, g[i][j]);
                if (size >= k) floodfill(i, j, g[i][j]); //unit disappears when size >= k
                max_size = max(max_size, size);
            }
        }
    }
    return max_size < k;
}


//cells "fall down" when there's empty space below them
void update() {
    //cout<<"update\n";
    FOR(10) {
        vector<char> sub;
        for (int j = 0; j < n; j++) {
            if (g[i][j] != '0') sub.pb(g[i][j]);
        }
        for (int j = 0; j < n - sub.size(); j++) g[i][j] = '0';
        for (int j = n - sub.size(), k = 0; j < n; j++, k++) g[i][j] = sub[k];
    }
}

int main() {
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
    scanf("%d%d", &n, &k);
    g.rz(10);
    FOR(n) {
        string s; cin >> s;
        for (int j = 0; j < 10; j++) {
            g[j].pb(s[j]);
            //store sideways - 10 vectors representing verticals
            //makes update() easier
        }
    }

    while (!solve()) {
        update();
    }

    FOR(n) {
        for (int j = 0; j < 10; j++) cout<<g[j][i];
        cout<<endl;
    }

    return 0;
}