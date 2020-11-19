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

const int N = 2 * 1e5 + 10;
int n, m;
char milk_type[N];
int h[N], e[N], ne[N], idx;
int track[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void floodfill(int u, char id, int new_id) {
    //cout<<"u = "<<u<<", id = "<<id<<", new_id = "<<new_id<<endl;
    if (track[u] != -1 || milk_type[u] != id) return;
    track[u] = new_id;

    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        floodfill(j, id, new_id);
    }
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", milk_type + 1);
    memset(h, -1, sizeof h);
    FOR(n - 1) {
        int a, b; scanf("%d%d", &a, &b);
        add(a, b); add(b, a);
    }

    memset(track, -1, sizeof track);
    int new_id = 0;
    FOR1(n) {
        if (track[i] == -1) floodfill(i, milk_type[i], new_id);
        new_id++;
    }

    FOR(m) {
        int start, end; char id;
        cin >> start >> end >> id;
        if (track[start] != track[end]) cout<<1;
        else {
            if (milk_type[start] == id) cout<<1;
            else cout<<0;
        }
    }
    cout<<endl;
    return 0;
}