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

const int N = 1e5 + 10;
int n, m, r;
int cows[N], rentals[N];
ii stores[N];
ll f[N], g[N]; //f selling, g renting

void fill_g() {
    g[1] = (ll)rentals[0];
    for (int i = 2; i <= n; i++) {
        g[i] = g[i - 1] + (ll)rentals[i - 1];
    }
}

void fill_f() {
    ll tot_milk = 0;
    int j = 0;
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        tot_milk += cows[i - 1];
        while (j < m && tot_milk > 0) {
            ll sold = min(tot_milk, (ll)stores[j].ss);
            f[i] += (ll)sold * stores[j].ff;
            tot_milk -= sold;
            stores[j].ss = max(stores[j].ss - sold, (ll)0);
            if (stores[j].ss == 0) j++;
        }
    }
}

ll solve() {
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ll tmp = f[i] + g[n - i];
        ans = max(ans, tmp);
    }
    return ans;
}

bool comp(ii a, ii b) {
    if (a == b) return a.ss > b.ss;
    return a.ff > b.ff;
}

int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &r); 
    FOR(n) scanf("%d", &cows[i]);
    FOR(m) scanf("%d%d", &stores[i].ss, &stores[i].ff);
    FOR(r) scanf("%d", &rentals[i]);

    sort(cows, cows + n, greater<int>());
    sort(stores, stores + m, comp);
    sort(rentals, rentals + r, greater<int>());

    fill_g();
    fill_f();

    cout<<solve()<<endl;
    return 0;
}