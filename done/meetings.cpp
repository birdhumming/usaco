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

int n, L, sum, t;
int ans;
int rate[50001];

struct node {
    int w;
    double x;
    int d, id;
} cows[50001];

bool cmp(node a, node b) {
    return a.x < b.x;
}

bool check(int mid) {
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = cows[i].x + (int)cows[i].d * mid;
        if (tmp <= 0) l++;
        if (tmp >= L) r++;
    }

    int tot = 0;
    for (int i = 1; i <= l; i++) 
        tot += cows[i].w;
    for (int i = 1; i <= r; i++)
        tot += cows[n - i + 1].w;

    if (tot * 2 >= sum) 
        return l;
    return 0;
}

int main() {
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
    scanf("%d%d", &n, &L);
    FOR1(n) {
        int w, x, d;
        scanf("%d%d%d", &w, &x, &d);
        sum += w;
        cows[i].w = w;
        cows[i].x = x;
        cows[i].d = d;
        cows[i].id = i;
    }
    sort(cows + 1, cows + n + 1, cmp);
    FOR1(n) {
        rate[cows[i].id] = i;
    }

    int l = 0, r = 1e9;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            t = mid;
        }
        else l = mid + 1;
    }

    FOR1(n) {
        if (cows[i].d == 1)
            cows[i].x += t + 0.1;
        else cows[i].x -= t;
        //cout<<"i = "<<i<<", cows[i].x = "<<cows[i].x<<endl;
    }

    sort(cows + 1, cows + n + 1, cmp);
    FOR1(n) {
        if (cows[i].d == 1) {
            ans += abs(rate[cows[i].id] - i);
            //cout<<"ans = "<<ans<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}