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

int n, m, c;
vi a;

//checks if cows can all arrive with max_time being max waiting time
bool check(int max_time) {
    int buses = 0;
    int i = 0;
    while (i < n) {
        int count = 0;
        int start = a[i];
        while (i < n && count < c) {
            if (a[i] - start <= max_time) {
                count++;
                i++;
            }
            else {
                break;
            }
        }
        buses++;
    }
    
    return buses <= m;
}

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &c); a.rz(n);
    FOR(n) scanf("%d", &a[i]);
    sort(a.begin(), a.end());

    //bsearch for smallest possible max
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout<<l<<endl;
    return 0;
}