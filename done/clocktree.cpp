#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;

const int N = 2510;
int n, set[N], dist[N];
bool adj[N][N];
unordered_map<int, vector<int> > e;

/*void calc(int u, int val) {
    for (int i = 1; i <= n; i++)
        if (dist[i] == -1 && adj[u][i]) {
            dist[i] = val;
            calc(i, val + 1);
        }
}*/

void calc(int u, int val) {
    for (int i : e[u])
        if (dist[i] == -1 && adj[u][i]) {
            dist[i] = val;
            calc(i, val + 1);
        }
}

bool check(int u) {
    //cout << "u = " << u << endl;
    memset(dist, -1, sizeof dist);
    dist[u] = 0;
    calc(u, 1);

    int s1 = 0, s2 = 0;
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] % 2) s1 += set[i], c1++;
        else s2 += set[i], c2++;
    }

    if ((s1 % 12) == (s2 % 12)) return true;
    if ((s2 % 12) == (s1 + 1) % 12) return true;

    return false;
}

int main() {
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> set[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a][b] = true;
        adj[b][a] = true;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        //cout << "i = "<<i<<endl;
        if (check(i)) ans++;
    }

    cout << ans << endl;
}