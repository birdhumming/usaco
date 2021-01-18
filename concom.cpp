/*
ID: drayale1
LANG: C++
TASK: concom
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110;
int n = 100, m, w[N][N];
bool g[N][N];

void dfs(int x, int y) {
    if (g[x][y]) return;
    g[x][y] = true;

    for (int i = 1; i <= n; i++) w[x][i] += w[y][i];
    for (int i = 1; i <= n; i++)
        if (g[i][x])
            dfs(i, y);
    for (int i = 1; i <= n; i++)
        if (w[x][i] > 50)
            dfs(x, i);
}

int main() {
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
    cin >> m;
    for (int i = 1; i <= n; i++) g[i][i] = true;
    while (m--) {
        int a, b, p; cin >> a >> b >> p;
        for (int i = 1; i <= n; i++) {
            if (g[i][a]) {
                w[i][b] += p;
                if (w[i][b] > 50) dfs(i, b);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && g[i][j])
                cout << i << " " << j << endl;
}