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

int k, n;

int solve(int x) {
    int up = 0, down = 0;
    int time = 0;
    int cur_speed = 1;

    while (true) {
        up += cur_speed;
        time++;

        if (up + down >= k) return time;

        if (cur_speed >= x) {
            down += cur_speed;
            time++;
            if (up + down >= k) return time;
        }

        cur_speed++;
    }
}

int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    cin >> k >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}