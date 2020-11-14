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

int n, m, r;
vi cows, rentals;
vector<ii> stores;

int solve() {
    ll ans = 0;
    int cows_sold = 0;

    int milk = 0;
    for (auto x : cows) milk += x;
    
    int i = 0, j = 0;
    while ((i < m || j < r ) && cows_sold < n) {
        int p = stores[i].ff, q = stores[i].ss;
        int r_price = rentals[j];
        if (p * min(q, milk) > r_price) {
            
        }
    }
}

int main() {
    //freopen("rental.in", "r", stdin);
    //freopen("rental.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &r); 
    cows.rz(n), stores.rz(m), rentals.rz(r);
    FOR(n) scanf("%d", &cows[i]);
    FOR(m) scanf("%d%d", &stores[i].ss, &stores[i].ff);
    FOR(r) scanf("%d", &rentals[i]);

    sort(n.begin(), n.end(), greater<int>());
    sort(stores.begin(), stores.end(), greater<int>());
    sort(r.begin(), r.end(), greater<int>());

    ll ans = solve();
}