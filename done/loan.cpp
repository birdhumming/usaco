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

ll n, k, m;

int works(ll x, ll k) {
    ll milk_left = n;

    while (k > 0 && milk_left >= 0) {
    ll y = milk_left / x;
    if (y < m) {
      ll stu = (milk_left + m - 1) / m;
      return stu <= k;
    }

    ll ma = n - x * y;
    ll days = (ma - milk_left) / y + 1;
    if (days > k) days = k;
    milk_left -= y * days;
    k -= days;
  }
  return milk_left <= 0;
}
 

int main() {
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &k, &m);
    //cout<<"n = "<<n<<endl;

    ll l = 1, r = 1e12;
    while (l < r) {
        //cout<<"l = "<<l<<", r = "<<r<<endl;
        long long mid = l + r + 1 >> 1;
        if (works(mid, k)) l = mid;
        else r = mid - 1;
    }
    cout<<l<<endl;
    return 0;
}