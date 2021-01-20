#include <iostream>
using namespace std;

const int N = 2510;
int n, set[N], dist[N];
bool adj[N][N];

void calc(int u, int val) {
    for (int i = 1; i <= n; i++)
        if (dist[i] == -1 && adj[u][i]) {
            dist[i] = val;
            calc(i, val + 1);
        }
}

bool check(int u) {
    cout << "u = " << u << endl;
    memset(dist, -1, sizeof dist);
    dist[u] = 0;
    calc(u, 1);
    for (int i = 1; i <= n; i++) {
        cout << "i = " <<i<<", dist[i] = " << dist[i] << endl;
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] % 2) sum += set[i];
        else sum -= set[i];
    }

    cout << "sum = " << sum << endl;

    sum = abs(sum);
    if (sum % 12 == 0 || sum % 12 == 1) return true;

    return false;
}

int main() {
    //freopen("clocktree.in", "r", stdin);
    //freopen("clocktree.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> set[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a][b] = true;
        adj[b][a] = true;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        //cout << "i = "<<i<<endl;
        if (check(i)) ans++;
    }

    cout << ans << endl;
}