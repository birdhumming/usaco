#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define pb push_back
#define all(v) v.begin(), v.end()

#define FOR(n) for (int i = 0; i < n; i++)
#define FOR1(n) for (int i = 1; i <= n; i++)

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int ddy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

int n, k, b;
vector<int> broken;
unordered_map<int, bool> is_broken;

//sliding window

int main() {
    //freopen("maxcross.in", "r", stdin);
    //freopen("maxcross.out", "w", stdout);
    scanf("%d%d%d", &n, &k, &b);
    FOR(b) {
        int x; scanf("%d", &x);
        broken.pb(x);
        is_broken[x] = true;
    }
    sort(broken.begin(), broken.end());

    vector<int> window;
    int sum = 0;
    for (int i = 1; i <= k; i++) sum += is_broken[i];
}