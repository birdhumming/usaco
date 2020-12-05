/*
ID: drayale1
LANG: C++
TASK: wormhole
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 12;
int n;
//two types of cycles: straight line, x-formation
int to1[N], to2[N];
bool st[N], used[N][2], cur[N][2];
int ans;

struct Point{
    int x, y;
    bool operator< (const Point& t) const {
        if (y != t.y) return y < t.y;
        return x < t.x;
    }
} q[N];

bool dfs_c(int a, int b) {
    if (cur[a][b]) return true;
    if (used[a][b]) return false;

    cur[a][b] = used[a][b] = true;
    bool res = false;

    if (!b) { //entry point
        if (dfs_c(to2[a], 1)) res = true;
    }
    else { //exit point
        if (to1[a] != -1 && dfs_c(to1[a], 0)) res = true;
    }

    cur[a][b] = false;
    return res;
}

bool check() {
    memset(used, 0, sizeof used);
    memset(cur, 0, sizeof cur);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            if (!used[i][j])
                if (dfs_c(i, j))
                    return true;
    return false;
}

void dfs(int u) {
    if (u == n / 2) {
        if (check()) ans++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!st[i]) {
            for (int j = i + 1; j < n; j++) {
                if (!st[j]) {
                    st[i] = st[j] = true;
                    to2[i] = j, to2[j] = i;
                    dfs(u + 1);
                    to2[i] = to2[j] = -1;
                    st[i] = st[j] = false;
                }
            }
            break;
        }
    }
}

int main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i].x >> q[i].y;
    sort(q, q + n);

    memset(to1, -1, sizeof to1);
    memset(to2, -1, sizeof to2);
    for (int i = 1; i < n; i++)
        if (q[i].y == q[i - 1].y)
            to1[i - 1] = i;
    
    dfs(0);

    cout << ans << endl;

    return 0;
}