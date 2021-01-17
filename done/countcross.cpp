#include <iostream>
using namespace std;

typedef pair<int, int> ii;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

const int N = 110;
int n, k, r;
int g[N][N];
bool visited[N][N];
ii cows[N];

int p[N * N];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void floodfill(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > n || visited[x][y]) return;
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !visited[nx][ny])
            if (((g[x][y] >> i) & 1) == 0) {
                int a = (x - 1) * n + y;
                int b = (nx - 1) * n + ny;
                p[find(b)] = find(a);
                floodfill(nx, ny);
            }   
    }

}

int main() {
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    for (int i = 0; i < N * N; i++) p[i] = i;
    cin >> n >> k >> r;
    for (int i = 0; i < r; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        //1 west, 2 east
        if (x1 == x2 && y1 < y2) {
            g[x1][y1] |= 1 << 3;
            g[x2][y2] |= 1 << 1;
        }

        //1 east, 2 west
        if (x1 == x2 && y1 > y2) {
            g[x1][y1] |= 1 << 1;
            g[x2][y2] |= 1 << 3;
        }

        //1 north, 2 south
        if (y1 == y2 && x1 < x2) {
            g[x1][y1] |= 1 << 2;
            g[x2][y2] |= 1 << 0;
        }

        //1 south, 2 north
        if (y1 == y2 && x1 > x2) {
            g[x1][y1] |= 1 << 0;
            g[x2][y2] |= 1 << 2;
        }

    }

    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) 
            cout << g[i][j] << " ";
        cout << endl;
    }*/

    for (int i = 0; i < k; i++) 
        cin >> cows[i].first >> cows[i].second;
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            if (!visited[i][j])
                floodfill(i, j);
    
    int ans = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < i; j++) {
            int a = (cows[i].first - 1) * n + cows[i].second;
            int b = (cows[j].first - 1) * n + cows[j].second;
            if (find(a) != find(b)) ans++;
        }
    }
    cout << ans << endl;

}

