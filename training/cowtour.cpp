/*
ID: drayale1
LANG: C++
TASK: cowtour
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

typedef pair<int, int> ii;
typedef pair<double, double> dd;

const int N = 160;
int n; 
dd cows[N];
bool adj[N][N];

int p[N];
unordered_set<int> parents;
vector< vector<int> > pastures;

double dist[N][N];
double maxd[N];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

double calc_dist(dd a, dd b) {
    float dist1 = abs(a.first - b.first);
    float dist2 = abs(a.second - b.second);
    double ans = sqrt(dist1 * dist1 + dist2 * dist2);
    return ans;
}
int main() {
    for (int i = 0; i < N; i++) p[i] = i;
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> cows[i].first >> cows[i].second;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            if (c == '1') adj[i][j] = true;
            else adj[i][j] = false;
        }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else if (adj[i][j]) dist[i][j] = calc_dist(cows[i], cows[j]);
            else dist[i][j] = 1e9;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (adj[i][j]) 
                p[find(i)] = find(j);

    for (int i = 0; i < n; i++) parents.insert(p[i]);

    for (int x : parents) {
        vector<int> t;
        for (int i = 0; i < n; i++)
            if (p[i] == x)
                t.push_back(i);
        pastures.push_back(t);
    }

    double d1 = 1e9, d2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (dist[i][j] < 1e9 / 2)
                maxd[i] = max(maxd[i], dist[i][j]);
        d2 = max(d2, maxd[i]);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist[i][j] > 1e9 / 2)
                d1 = min(d1, maxd[i] + calc_dist(cows[i], cows[j]) + maxd[j]);

    printf("%lf\n", max(d1, d2));

}