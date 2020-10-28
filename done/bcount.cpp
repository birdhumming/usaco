#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;

int n, q;
vector<int> h, g, j;

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    scanf("%d%d", &n, &q);
    h.resize(n + 10, 0), g.resize(n + 10, 0), j.resize(n + 10, 0);

    for (int i = 1; i <= n; i++) {
        int id; scanf("%d", &id);
        if (id == 1) h[i] = 1;
        if (id == 2) g[i] = 1;
        if (id == 3) j[i] = 1;
    }

    vector<int> ph(n + 10, 0), pg(n + 10, 0), pj(n + 10, 0);
    for (int i = 1; i <= n; i++) {
        ph[i] = ph[i - 1] + h[i];
        pg[i] = pg[i - 1] + g[i];
        pj[i] = pj[i - 1] + j[i];
    }

    while (q--) {
        int a, b; scanf("%d%d", &a, &b);
        int nh = ph[b] - ph[a - 1];
        int ng = pg[b] - pg[a - 1];
        int nj = pj[b] - pj[a - 1];
        cout<<nh<<' '<<ng<<' '<<nj<<endl;
    }

    return 0;
}