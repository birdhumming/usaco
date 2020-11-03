#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define pb push_back
#define rs resize
#define all(v) v.begin(), v.end()

#define FOR(n) for (int i = 0; i < n; i++)
#define FOR1(n) for (int i = 1; i <= n; i++)

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int ddy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

int n; vc g;
vi h, p, s;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    scanf("%d", &n);
    FOR(n) {
        char c; scanf(" %c", &c); g.pb(c);
        //cout<<"c = "<<c<<endl;
    }
    h.rs(n + 1); p.rs(n + 1); s.rs(n + 1);

   for (int i = 1; i <= n; i++) {
        char c = g[i - 1];

        int hd, pd, sd; hd = pd = sd = 0;
        if (c == 'H') hd = 1;
        if (c == 'P') pd = 1;
        if (c == 'S') sd = 1;
        h[i] = h[i - 1] + hd;
        p[i] = p[i - 1] + pd;
        s[i] = s[i - 1] + sd;
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int sum1 = h[i] + p[n] - p[i];
        ans = max(ans, sum1);
        int sum2 = h[i] + s[n] - s[i];
        ans = max(ans, sum2);
        int sum3 = p[i] + h[n] - h[i];
        ans = max(ans, sum3);
        int sum4 = p[i] + s[n] - s[i];
        ans = max(ans, sum4);
        int sum5 = s[i] + h[n] - h[i];
        ans = max(ans, sum5);
        int sum6 = s[i] + p[n] - p[i];
        ans = max(ans, sum6);
        //cout<<"an = "<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}