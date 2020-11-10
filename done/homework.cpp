#include <bits/stdc++.h>
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
vi scores, rem, pref;
vector<pair<int, double> > ans;

int main() {
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
    scanf("%d", &n);
    FOR(n) {
        int x; scanf("%d", &x);
        scores.pb(x);
    }
    int m = scores.back();
    RFOR(n) {
        if (scores[i] < m) m = scores[i];
        rem.pb(m);
    }
    reverse(rem.begin(), rem.end());
    pref.rs(n + 1); pref[0] = 0;
    FOR1(n) {
        pref[i] = pref[i - 1] + scores[i - 1];
    }
    
    double big = 0;
    for (int k = 1; k <= n - 2; k++) {
        double score = pref[n] - pref[k] - rem[k];
        score /= (n - k - 1);
        big = max(big, score);
        ans.pb(mp(k, score));
    }

    FOR(ans.size()) {
        if (ans[i].second == big) {
            cout << ans[i].first << endl;
        }
    }
    return 0;
}