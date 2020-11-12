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
#define f first
#define s second

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
vi cows, spaces;

bool cows_bunched_up_at_one_end() {
    if (cows[n - 2] - cows[0] == n - 2 && cows[n - 1] - cows[n - 2] > 2) 
        return true;
    if (cows[n - 1] - cows[1] == n - 2 && cows[1] - cows[0] > 2)
        return true;
    return false;
}

int solve() {
    if (cows_bunched_up_at_one_end()) return 2;
    int ans = 0, j = 0;
    FOR(n) {
        while (j < n - 1 && cows[j + 1] - cows[i] <= n - 1) 
            j++;
        ans = max(ans, j - i + 1);
    }
    return n - ans;
}

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    scanf("%d", &n); cows.rz(n);
    FOR(n) scanf("%d", &cows[i]);
    sort(cows.begin(), cows.end());

    int min_ans = solve();
    int max_ans = max(cows[n - 1] - cows[1], cows[n - 2] - cows[0]) - (n - 2);
    cout<<min_ans<<endl<<max_ans<<endl;
    return 0;
}