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

const int N = 2 * 1e5 + 10;
int n, m;
int p[N];

int find (int x) {
    if (p[x] == -1) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (a >= n) swap(a, b);
    p[b] = a;
}

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    scanf("%d%d", &n, &m);
    memset(p, -1, sizeof p);

    FOR(m) {
        int a, b; char c;
        cin >> c >> a >> b;
        a--, b--;
        if (a > b) swap(a, b);

        if (c == 'S') {
            merge(a, b);
            merge(a + n, b + n);
        }
        else {
            merge(a, b + n);
            merge(b, a + n);
        }
    }

    int cnt = 0;
    FOR(n) {
        if (find(i) == find(i + n)) {
            printf("0");
            return 0;
        }
    }

    FOR(n) 
        merge(i, i + n);
    
    printf("1");
    FOR(n) {
        if (i == find(i)) printf("0");
    }
    cout<<endl;
    return 0;
}