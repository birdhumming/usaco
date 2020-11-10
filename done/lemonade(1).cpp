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
vector<int> w;

bool comp(int a, int b) { return a > b; }

int main() {
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    scanf("%d", &n); w.rs(n);
    FOR(n) scanf("%d", &w[i]);

    sort(w.begin(), w.end(), comp);
    int in_line = 0;
    FOR(n) {
        if (w[i] >= in_line) in_line++;
    }
    cout<<in_line<<endl;
    return 0;
}