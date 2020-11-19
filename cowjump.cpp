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

const int N = 1e5 + 10;
int n;
struct seg {
    ll a, b;
    ll x, y;
} segments[N];

bool cross(seg c, seg d) {
    if ()
}

int main() {
    //freopen("cowjump.in", "r", stdin);
    //freopen("cowjump.out", "w", stdout);
    scanf("%d", &n);
    FOR1(n) {
        int a, b, x, y; scanf("%d%d%d%d", &a, &b, &x, &y);
        if (a < x) {
            segments[i].a = a, segments[i].b = b;
            segments[i].x = x, segments[i].y = y;
        }
        else if (x < a) {
            segments[i].a = x, segments[i].b = y;
            segments[i].x = a, segments[i].y = b;
        }
        else if (x == a) {
            if (b < y) {
                segments[i].a = a, segments[i].b = b;
                segments[i].x = x, segments[i].y = y;
            }
            else {
                segments[i].a = x, segments[i].b = y;
                segments[i].x = a, segments[i].y = b;
            }
        }
    }


}