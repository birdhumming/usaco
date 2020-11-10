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

int n;
vector<pair<int, ii> > a;

bool comp(pair<int, ii> a, pair<int, ii> b) {
    if (a.second.first == b.second.first) 
        return a.first < b.first;
    return a.second.first < b.second.first;
}

ll solve() {
    ll ans = 0, end_time;
    int next = 1;
    priority_queue<ii, vector<ii>, greater<ii>> waiting;

    end_time = a[0].second.first + a[0].second.second;
    while (next < n || waiting.size() > 0) {
        while (next < n && a[next].second.first <= end_time) {
            waiting.push(make_pair(a[next].first, next));
            next++;
        }
        if (waiting.empty() && next < n) {
            end_time = a[next].second.first + a[next].second.second;
            next++;
        }
        else if (waiting.size()) {
            auto t = waiting.top();
            waiting.pop();
            ans = max(ans, end_time - a[t.second].second.first);
            end_time += a[t.second].second.second;
        }
    }
    return ans;
}

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    scanf("%d", &n); a.rz(n);
    FOR(n) {
        scanf("%d%d", &a[i].second.first, &a[i].second.second);
        a[i].first = i;
    }

    sort(a.begin(), a.end(), &comp);

    ll ans = solve();
    cout<<ans<<endl;
    return 0;
}