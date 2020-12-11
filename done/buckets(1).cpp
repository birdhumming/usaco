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

const int N = 11;
char g[N][N];
bool visited[N][N];
int lx, ly, bx, by, rx, ry; //lake(x, y), barn(x, y), rock(x, y)
struct node{
    int x, y, d;
};

int bfs() {
    queue<node> q;
    node start = {lx, ly, 0};
    q.push(start);
    visited[lx][ly] = true;

    while (q.size()) {
        auto t = q.front();
        q.pop();
        int x = t.x, y = t.y, d = t.d;

        //cout << "x = "<<x<<", y = "<<y<<", d = "<<d<<endl;
        if (x == bx && y == by) return d;

        //visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            node tmp = {nx, ny, d + 1};
            if (in_bounds(nx, ny, 10, 10) && !visited[nx][ny] && !(nx == rx && ny == ry)) {
                visited[nx][ny] = true;
                q.push(tmp);
            }
        }
    }
}

int main() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'L') lx = i, ly = j;
            if (g[i][j] == 'B') bx = i, by = j;
            if (g[i][j] == 'R') rx = i, ry = j;
        }
    
    cout << bfs() - 1 << endl;

    return 0;
}