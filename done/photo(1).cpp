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

const int N = 1010;
int n;
int a[N], b[N];
bool st[N];

int main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) scanf("%d", &b[i]);

    for (int start = 1; start <= n; start++) {
        memset(st, false, sizeof st);
        memset(a, 0, sizeof a); 

        a[0] = start;
        st[start] = true;
        bool flag = true;

        for (int j = 1; j < n; j++) {
            int x = b[j - 1] - a[j - 1];
            if (st[x] || x < 1 || x > n) { //pay attention
                flag = false; 
                break;
            }
            a[j] = x;
            st[x] = true;
        }

        if (flag) {
            for (int i = 0; i < n; i++) {
                if (i == n - 1) cout << a[i];
                else cout << a[i] << " ";
            }
            return 0;
        }
    }
}