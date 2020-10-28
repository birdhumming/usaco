#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;

const int N = 110, M = 20010;
int n, m;
int barn[N][N];
vector<ii> g[N][N];
bool visited[N][N], lit[N][N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool neighbors_visited(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx > 0 && nx <= n && ny > 0 && ny <= n && visited[nx][ny])
            return true;
    }
    return false;
}

void solve(int x, int y) {
    visited[x][y] = true;
    vector<ii> v = g[x][y];
    for (int i = 0; i < v.size(); i++) {
        int nx = v[i].first;
        int ny = v[i].second;
        lit[nx][ny] = true;

        if (!visited[nx][ny] && neighbors_visited(nx, ny))
            solve(nx, ny);
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx > 0 && nx <= n&& ny > 0 && ny <= n && lit[nx][ny])
            if (!visited[nx][ny] && lit[nx][ny])
                solve(nx, ny);
    }
}


int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y, a, b; 
        scanf("%d%d%d%d", &x, &y, &a, &b);
        g[x][y].push_back(make_pair(a, b));
    }

    lit[1][1] = true;
    solve(1, 1);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (lit[i][j]) ans++;
    cout<<ans<<endl;

    return 0;
}