#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define pb push_back
#define rs resize
#define mp make_pair

#define FOR(n) for (int i = 0; i < n; i++)
#define FOR1(n) for (int i = 1; i <= n; i++)
#define RFOR(n) for (int i = n - 1; i >= 0; i--)

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int ddy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

int n;
vector<ii> a;

//find max distance moved by element
int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    scanf("%d", &n); a.rs(n);
    FOR(n) {
        int x; scanf("%d", &x);
        a[i] = mp(x, i);
    }

    sort(a.begin(), a.end());
    int ans = 0;
    FOR(n) {
        int start = a[i].second;
        if (start > i) ans = max(ans, start - i + 1);
    }

    if (ans == 0) ans = 1;
    //moo always outputted at least once (see pseudo in prob)
    cout << ans << endl;
    return 0;
}