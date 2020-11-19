#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vii vector<ii>
#define pb push_back
#define sz size
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

int l, n, rf, rb;
vii stops;
priority_queue<ii, vii> heap;

int main() {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    scanf("%d%d%d%d", &l, &n, &rf, &rb); stops.rz(n);
    FOR(n) {
        scanf("%d%d", &stops[i].ff, &stops[i].ss);
        heap.push(mp(stops[i].ss, stops[i].ff));
    }
    sort(stops.begin(), stops.end());

    unsigned ll reached = 0, ans = 0;
    unsigned ll tf = 0, tb = 0;
    while (heap.sz()) {
        auto t = heap.top();
        heap.pop();
        int x = t.ss, c = t.ff;
        if (x < reached) continue;
        
        int d = x - reached;
        tf += d * (ll)rf;
        tb += d * (ll)rb;
        ans += (tf - tb) * (ll)c;
        tb = tf;
        reached = x;
    }
    
    cout<<ans<<endl;
    return 0;
}