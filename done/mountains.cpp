#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define pb push_back
#define rz resize
#define mp make_pair
#define f first
#define s second

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

const int N = 1e5 + 10;
int n;
vector<ii> peaks;
vi sub, add, label;

bool comp(int a, int b) {
    if (sub[a] == sub[b])
        return add[a] > add[b];
    return sub[a] < sub[b];
}

int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    scanf("%d", &n); peaks.rz(n);
    FOR(n) {
        int a, b; scanf("%d%d", &a, &b);
        peaks[i].f = a, peaks[i].s = b;
        sub.pb(a - b);
        add.pb(a + b);
        label.pb(i);
    }

    sort(label.begin(), label.end(), comp);

    int x_pos = -1, ans = 0;
    FOR(n) {
        int j = label[i];
        if (add[j] > x_pos) {
            x_pos = add[j];
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}