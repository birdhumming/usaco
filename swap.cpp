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

int n, k;
int a1, a2, b1, b2;

int pos_calc(int i) {
    if (a1 <= i && i <= a2) i = a1 + a2 - i;
    if (b1 <= i && i <= b2) i = b1 + b2 - i;
    return i;
}

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    cin >> n >> k;
    cin >> a1 >> a2 >> b1 >> b2;

    for (int i = 1; i <= n; i++) {
        int x = i;
        for (int j = 0; j < k; j++) x = pos_calc(x);
        cout << x << endl;
    }
    return 0;
}