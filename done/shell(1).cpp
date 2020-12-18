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
ii swaps[N];
int guesses[N];

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> swaps[i].ff >> swaps[i].ss >> guesses[i];

    int ans = 0;
    for (int s = 1; s <= 3; s++) {
        int tmp = 0, shell = s;
        for (int i = 0; i < n; i++) {
            int a = swaps[i].ff, b = swaps[i].ss;
            int g = guesses[i];
            if (a == shell) shell = b;
            else if (b == shell) shell = a;
            if (g == shell) tmp++;
        }
        ans = max(tmp, ans);
    }

    cout << ans << endl;

    return 0;
}