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
unordered_map<int, vi> cnt;

int main()
{
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    scanf("%d", &n);
    FOR(n - 1) {
        int a, b; scanf("%d%d", &a, &b);
        cnt[a].pb(b);
        cnt[b].pb(a);
    }

    int max_deg = 0;
    for(auto x : cnt) {
        vi v = x.second;
        int size = v.size();
        max_deg = max(max_deg, size);
    }
    cout<<max_deg + 1<<endl;
    return 0;
}