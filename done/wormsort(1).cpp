#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int n, m, q[N];
int h[N], e[N], w[N], ne[N], idx;
int p[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;;
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

bool check(int lim) {
    //cout << "lim = "<<lim<< endl;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = h[i]; j != -1; j = ne[j]) {
            int b = e[j], c = w[j];
            if (c >= lim) p[find(b)] = find(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (find(q[i]) != find(i)) return false;
    }

    return true;
}

bool is_sorted() {
    for (int i = 1; i <= n; i++) 
        if (q[i] != i)
            return false;
    return true;
}

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int max_w = 0;
    for (int i = 1; i <= n; i++) cin >> q[i];
    if (is_sorted()) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        add(a, b, c);
        max_w = max(c, max_w);
    }

    int l = 0, r = max_w;
    while (l < r) {
        //cout << "l = "<<l<<", r= "<<r<<endl;
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    cout << l << endl;
}