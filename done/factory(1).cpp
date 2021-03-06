#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <cstring>

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

const int N = 110;
int n;
int h[N], e[N], ne[N], idx;
bool reached[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void solve(int u) {
    reached[u] = true;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!reached[j]) solve(j);
    }
}

int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        add(b, a);
    }

    for (int i = 1; i <= n; i++) {
        memset(reached, false, sizeof reached);
        
        solve(i);

        //cout << "i = "<<i<<endl;
        
        int res = 0;
        for (int j = 1; j <= n; j++)
            if (reached[j]) {
                res++;
                //cout << "j = "<<j<<endl;
            }
        
        if (res == n) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}