#include <iostream>
using namespace std;

const int N = 1010;
int n, m, g[N][N], tmp;
bool visited[N][N], mark = false;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int change[2][4] = {
    {2, 3, 0, 1},
    {3, 2, 1, 0}
};

void solve(int x, int y, int d, int dist) {
    //cout << "x = " << x << ", y = " << y << endl;
    //cout << "dist = " << dist << endl;
    if (x == -1 || x == n || y == -1 || y == n) {
        tmp = dist;
        return;
    }
    if (visited[x][y]) {
        //cout << "VISITED\n";
        mark = true;
    }

    visited[x][y] = true;
    int nd = change[g[x][y]][d];
    int nx = x + dx[nd];
    int ny = y + dy[nd];
    solve(nx, ny, nd, dist + 1);
}

int main() {
    freopen("mirror.in", "r", stdin);
    freopen("mirror.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == '/') g[i][j] = 0;
            else g[i][j] = 1;
        }

    int ans = 0;
    for (int j = 0; j < m; j++) {
        if (!visited[0][j]) {
            solve(0, j, 0, 0);
            ans = max(ans, tmp);
        }
        if (!visited[n - 1][j]) {
            solve(n - 1, j, 1, 0);
            ans = max(ans, tmp);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i][0]) {
            solve(i, 0, 3, 0);
            ans = max(ans, tmp);
        }
        if (!visited[i][m - 1]) {
            solve(i, m - 1, 2, 0);
            ans = max(ans, tmp);
        }
    }

    if (mark) cout << -1 << endl;
    else cout << ans << endl;
}