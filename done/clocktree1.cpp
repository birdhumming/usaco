#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;

const int N = 2510;
int n, set[N], dist[N];
bool visited[N];

unordered_map<int, vector<int> > e;

/*void calc(int u, int val) {
    for (int i = 1; i <= n; i++)
        if (dist[i] == -1 && adj[u][i]) {
            dist[i] = val;
            calc(i, val + 1);
        }
}*/

int dfs(int u) {
    if (visited[u]) return 0;
    visited[u] = true;
    int ans = set[u];
    for (int x : e[u]) ans += dfs(x);
    return 12 - (ans % 12);
}

int main() {
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> set[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof visited);
        int res = dfs(i);
        //cout << "res = "<< res << endl;
        if (res % 12 == 0) ans++;
        else if ((res + 1) % 12 == 0) ans++;
    }

    cout << ans << endl;
}