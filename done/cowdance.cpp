#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define pb push_back
#define all(v) v.begin(), v.end()

#define FOR(n) for (int i = 0; i < n; i++)
#define FOR1(n) for (int i = 1; i <= n; i++)

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int ddy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

int n, t;
vi d;

bool check(int k) {
    vector<int> f(k + 1);
    priority_queue<ii, vector<ii>, greater<ii> > heap;

    for (int i = 1; i <= k; i++) {
        int x = d[i];
        heap.push(make_pair(x, i));
        f[i] = x;
    }

    for (int i = k + 1; i <= n; ) {
        int cnt = 0;
        while (i <= n && cnt < k) {
            auto t = heap.top();
            heap.pop();
            int val = t.first, idx = t.second;
            //cout<<"val = "<<val<<", idx = "<<idx<<endl;
            f[idx] += d[i];
            //cout<<"i = "<<i<<endl;
            heap.push(make_pair(f[idx], idx));
            i++, cnt++;
        }
    }
    int ans = 0;
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        //cout<<".first = "<<t.first<<endl;
        ans = max(ans, t.first);
    }

    if (ans <= t) return true;
    return false;

}


int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    scanf("%d%d", &n, &t);
    d.push_back(0);
    FOR(n) { 
        int x; scanf("%d", &x); 
        d.push_back(x);
    }
    
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        //cout<<"mid = "<<mid<<endl;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    //cout<<"l = "<<l<<" r = "<<r<<endl;
    cout<<l<<endl;
    return 0;
}