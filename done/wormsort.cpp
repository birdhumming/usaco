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

const int N = 1e5 + 10;
int n, m;
vi p;
vector<ii> adj[N];
bool visited[N];
//set<int> unpaired;
int unpaired[N];

void solve(int cow, int lim) {
    visited[cow] = true;
    //if (unpaired.count(cow) > 0) unpaired.erase(cow);
    if (unpaired[cow] > 0) unpaired[cow] = 0;
    //else unpaired.insert(cow);
    else unpaired[cow] = 1;
    //if (unpaired.count(p[cow]) > 0) unpaired.erase(p[cow]);
    if (unpaired[p[cow]] > 0) unpaired[p[cow]] = 0;
    //else unpaired.insert(p[cow]);
    else unpaired[p[cow]] = 1;

    for (int i = 0; i < adj[cow].size(); i++) {
        int next = adj[cow][i].first;
        int w = adj[cow][i].second;
        if (!visited[next] && w >= lim) 
            solve(next, lim);
    }
}

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    scanf("%d%d", &n, &m); p.rz(n + 1);
    FOR1(n) scanf("%d", &p[i]);
    FOR(m) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }

    int l = 1, r = 1e9 + 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        bool works = true;
        //unpaired.clear();
        memset(unpaired, 0, sizeof unpaired);
        memset(visited, false, sizeof visited);

        FOR(n) {
            if (!visited[i]) {
                solve(i, mid);
                FOR1(n) {
                    if (unpaired[i] > 0) {
                        works = false;
                        break;
                    }
                }
            }
        }

        if (works) l = mid;
        else r = mid - 1;
    }

    if (l == 1e9 + 1) {
        cout<<-1<<endl;
        return 0;
    }
    cout<<l<<endl;
    return 0;
}