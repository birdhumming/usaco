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

vector<int> c, d;
unordered_set<int> track;


void solve4(int tank, vector<int>& a, vector<int>& b) {
    for (int i = 0; i < b.size(); i++) {
        track.insert(tank + b[i]);
    }
}

void solve3(int tank, vector<int>& a, vector<int>& b) {
    for (int i = 0; i < a.size(); i++) {
        vi a1 = a;
        vi b1 = b;
        a1.erase(a1.begin() + i);
        b1.pb(a[i]);
        solve4(tank - a[i], a1, b1);
    }
}

void solve2(int tank, vector<int>& a, vector<int>& b) {
    for (int i = 0; i < b.size(); i++) {
        vi a1 = a, b1 = b;
        b1.erase(b1.begin() + i);
        a1.pb(b[i]);
        solve3(tank + b[i], a1, b1);
    }
}

void solve1(int tank, vector<int>& a, vector<int>& b) {
    for (int i = 0; i < a.size(); i++) {
        vi a1 = a, b1 = b;
        a1.erase(a1.begin() + i);
        b1.pb(a[i]);
        solve2(tank - a[i], a1, b1);
    }
}

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    int x;
    for (int i = 0; i < 10; i++) cin >> x, c.pb(x);
    for (int i = 0; i < 10; i++) cin >> x, d.pb(x);

    solve1(1000, c, d);

    cout << track.size() << endl;

    return 0;
}