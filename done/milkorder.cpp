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
int n, m, k;
bool used_cows[N], used_pos[N];
int pos[N], order[N];
int fixed_cows[N], fixed_pos[N];

bool works() {
    memset(used_cows, 0, sizeof used_cows);
    memset(used_pos, 0, sizeof used_pos);

    for (int i = 0; i < k; i++) {
        if (used_cows[fixed_cows[i]] && pos[fixed_cows[i]] == fixed_pos[i]) continue;
        if (used_cows[fixed_cows[i]]) return false;
        if (used_pos[fixed_pos[i]]) return false;
        used_cows[fixed_cows[i]] = true;
        used_pos[fixed_pos[i]] = true;
        pos[fixed_cows[i]] = fixed_pos[i];
    }

    int j = 0;
    for (int i = 0; i < m; i++) {
        int cow = order[i];
        if (used_cows[cow]) {
            if (j > pos[cow]) return false;
            j = pos[cow];
            continue;
        }
        while (used_pos[j]) {
            j++;
            if (j == n) return false;
        }
        used_pos[j] = true;
        pos[cow] = j;
    }
    return true;
}

int main() {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
       cin >> order[i];
       order[i]--;
    }

    for (int i = 0; i < k; i++) {
        cin >> fixed_cows[i] >> fixed_pos[i];
        fixed_cows[i]--, fixed_pos[i]--;
    }

    k++;

    for (int i = 0; i < n; i++) {
        fixed_cows[k - 1] = 0;
        fixed_pos[k - 1] = i;
        if (works()) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << "END\n";

    return 0;
}   