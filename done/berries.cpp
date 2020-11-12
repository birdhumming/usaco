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

int n, k;
vi b;

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    scanf("%d%d", &n, &k); b.rz(n);
    int max_b = 0;
    FOR(n) {
        scanf("%d", &b[i]);
        max_b = max(max_b, b[i]);
    }

    int ans = 0;
    for (int i = 1; i <= max_b; i++) {
        //cout<<"i = "<<i<<endl;
        vi tmp;

        int num = 0;
        for (int j = 0; j < n; j++) {
            num += b[j] / i;
        }
        //cout<<"num = "<<num<<endl;
        if (num >= k) {
            ans = max(ans, i * k / 2);
            continue;
        }
        if (num < k / 2) break;

        else {
            int tmp_ans = 0;
            tmp_ans = (num - (k / 2)) * i;
            for (int j = 0; j < n; j++) tmp.pb(b[j] % i);
            sort(tmp.begin(), tmp.end(), greater<int>());
            //FOR(n) cout<<tmp[i]<<' ';
            //cout<<endl;

            int j = 0;
            while (j < n && num < k) {
                tmp_ans += tmp[j];
                num++; j++;
            }
            ans = max(ans, tmp_ans);
        }
        //cout<<"ans = "<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}