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



const int N = 260;

int n, b;
ll ans = 1e9 + 10;
int steps[N];
ii boots[N];

int f[N][N];

void find(int tile, int boot, int val) {
   f[tile][boot] = val;

   if (tile == n - 1) {
      ans = min((ll)val, ans);
   }

   else {
      for (int j = 1; j < min(boots[boot].ss + 1, n - tile + 1); j++) {
         if (steps[tile + j] <= boots[boot].ff && f[tile + j][boot] == 0) {
            find(tile + j, boot, val);
         }
      }

      for (int i = boot + 1; i < b; i++) {
         if (steps[tile] <= boots[i].ff && f[tile][i] == 0)
            find(tile, i, val + 1);
         else val++;
      }
   }
   
}

int main() {
   freopen("snowboots.in", "r", stdin);
   freopen("snowboots.out", "w", stdout);
   scanf("%d%d", &n, &b);
   FOR(n) scanf("%d", &steps[i]);
   FOR(b) scanf("%d%d", &boots[i].ff, &boots[i].ss);

   find(0, 0, 0);
   cout<<ans<<endl;
   return 0;
}