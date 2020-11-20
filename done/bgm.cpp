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

int n;
ll num[256][7];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("bgm.in", "r", stdin);
    freopen("bgm.out", "w", stdout);
    cin >> n;

    FOR(n) {
        char c; int x;
        cin >> c >> x;
        num[c][(x % 7 + 7) % 7]++;
    }

    ll res = 0;
    for (int B = 0; B < 7; B++) 
    for (int E = 0; E < 7; E++)
    for (int S = 0; S < 7; S++)
    for (int I = 0; I < 7; I++)
    for (int G = 0; G < 7; G++)
    for (int O = 0; O < 7; O++)
    for (int M = 0; M < 7; M++) {
        if (((B + E + S + S + I + E) * (G + O + E + S) * (M + O + O)) % 7 == 0) {
            res += num['B'][B] * num['E'][E] * num['S'][S] * num['I'][I] * num['G'][G] * num['O'][O] * num['M'][M];
        }
    }
    
    cout<<res<<endl;
    return 0;
}