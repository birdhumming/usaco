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

const int N = 2005;
int n;
string s;
int ans = -1;
bool g[N][N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

/*void floodfill(int x, int y) {
    cout<<"ans = "<<ans<<endl;
    cout<<x<<", "<<y<<endl;
    //g[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !g[nx][ny]) {
            //cout<<"nx "<<nx<<", ny "<<ny<<endl;
            g[nx][ny] = true;
            floodfill(nx, ny);
        }
    }
}*/

void bfs(int x, int y) {
    queue<ii> q;
    q.push(make_pair(x, y));
    g[x][y] = true;

    while (q.size()) {
        int a = q.front().first;
        int b = q.front().second;
        g[a][b] = true;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !g[nx][ny]) {
                g[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    cin >> n >> s;

    memset(g, false, sizeof g);
    int x = 1002, y = 1002;
    int xdir, ydir;

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'N') xdir = -1;
        if (c == 'S') xdir = 1;
        if (c == 'E') ydir = -1;
        if (c == 'W') ydir = 1;

        for (int j = 0; j < 2; j++) {
            x += xdir;
            y += ydir;
            g[x][y] = true;
        }

        xdir = 0; ydir = 0;
    }

    //cout<<"71\n";
    //int ans = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!g[i][j]) {
                ans++;
                bfs(i, j);
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}