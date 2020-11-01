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

const int N = 3010;
int n, m;
int a[N], b[N], p[N], order[N];

int find(int x) {
    //cout<<x<<endl;
    if (p[x] != x) {
        //cout<<"searching"<<endl;
        p[x] = find(p[x]);
    }
    return p[x];
}
void merge(int x, int y) { p[find(x)] = find(y); }
bool query(int c, int d) { 
    //cout<<"QUERYING "<<c<<' '<<d<<endl;
    return find(c) == find(d);
}


int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) scanf("%d%d", &a[i], &b[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &order[i]);
        p[i] = i;
    }
    order[0] = -1;
    //puts("40");

    int last_removed = order[n];

    for (int i = 0; i < n; i++) {
        for (int i = 1; i <= n; i++) p[i] = i; //reset p

        int re = order[i];
        for (int i = 0; i < m; i++) {
            //remove ith barn
            if (a[i] == re || b[i] == re) a[i] = -1, b[i] = -1;
            else if (a[i] != - 1 && b[i] != -1) merge(a[i], b[i]);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (query(i, last_removed)) ans++;
        }
        if (ans == n - i) puts("YES");
        else puts("NO");
    }

    /*for (int i = 0; i < m; i++) {
        //cout<<"i = "<<i<<endl;
        int x = a[i], y = b[i];
        merge(x, y);
    }
    //puts("47");
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        //cout<<"i = "<<i<<endl;
        if (query(i, last_removed)) {
            ans++;
        }
    }
    if (ans == n) puts("YES");
    else puts("NO");*/

    return 0;
}