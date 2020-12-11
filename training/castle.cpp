/*
ID: drayale1
LANG: C++
TASK: castle
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dx[2] = {-1, 0}, dy[2] = {0, 1};
int dw[2] = {2, 4};

const int N = 55, M = N * N;

int n, m;
int g[N][N];
int p[M], sz[M];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    
    for (int i = 0; i < n * m; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    int cnt = n * m, max_area = 1;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            for (int u = 0; u < 2; u++) {
                if (!(g[i][j] & dw[u])) {
                    int x = i + dx[u], y = j + dy[u];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    int a = i * m + j, b = x * m + y;
                    a = find(a), b = find(b);
                    if (a != b) {
                        cnt--;
                        sz[b] += sz[a];
                        p[a] = b;
                        max_area = max(max_area, sz[b]);
                    }
                }
            }
    
    cout << cnt << endl << max_area << endl;

    max_area = 0;
    int rx, ry, rw;
    for (int j = 0; j < m; j++) 
        for (int i = n - 1; i >= 0; i--)
            for (int u = 0; u < 2; u++)
                if (g[i][j] & dw[u]) {
                    int x = i + dx[u];
                    int y = j + dy[u];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    int a = i * m + j;
                    int b = x * m + y;
                    a = find(a), b = find(b);
                    if (a != b) {
                        int area = sz[a] + sz[b];
                        if (area > max_area) {
                            max_area = area;
                            rx = i, ry = j, rw = u;
                        }
                    }
                }
    
    cout << max_area << endl;
    cout << rx + 1 << ' ' << ry + 1 << ' ' << (rw ? 'E' : 'N') << endl;

    return 0;
}