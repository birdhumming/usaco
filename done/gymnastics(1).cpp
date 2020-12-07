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

const int N = 25;
int k, n;
int cows[N];
int better[N][N];
//0 false 1 true 2 contradiction

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    cin >> k >> n;
    while (k--) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &cows[i]);
            for (int j = 0; j < i; j++) {
                if (better[cows[i]][cows[j]]) {
                    better[cows[i]][cows[j]] = 2;
                    better[cows[j]][cows[i]] = 2;
                }
                else better[cows[j]][cows[i]] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (better[i][j] == 1) {
                //cout << "i = "<<i<<", j = "<<j<<endl;
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}