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



int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int n = 6;
    vector<int> nums;
    nums = {}
    vector<char> sub;
        for (int j = 0; j < n; j++) {
            if (g[i][j] != 0) sub.pb(g[i][j]);
        }
        for (int j = 0; j < n - sub.size(); j++) g[i][j] = '0';
        for (int j = n - sub.size(), k = 0; j < n; j++, k++) g[i][j] = sub[k];
        for (int j = 0; j < n; j++) cout<<g[i][j]<<' ';
        cout<<endl;
    }
}

#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100000
 
int N;
int x[MAXN], y[MAXN];
int pos[MAXN], neg[MAXN];
int cid[MAXN];
 
