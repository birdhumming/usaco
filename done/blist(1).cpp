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

const int N = 110;
int n;
struct cow{
    int s, t, b;
    bool operator< (const cow& tmp) const {
        return s < tmp.s;
    }
} cows[N];
int pref[1010];

bool check(int x) {
    for (int i = 0; i < 1010; i++) {
        x += pref[i];
        if (x < 0) return false;
    }
    return true;
}

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> cows[i].s >> cows[i].t >> cows[i].b;
    sort(cows, cows + n);

    for (int i = 0; i < n; i++) {
        int s = cows[i].s;
        int t = cows[i].t;
        int b = cows[i].b;
        pref[s] += -1 * b;
        pref[t] += b;
    }

    int l = 0, r = 1010;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << r << endl;
    
    return 0;
}