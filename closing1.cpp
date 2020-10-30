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

int n, m;
vector<int> a, b, order;

vector<int> place, p, height;
void init(int s) {
    for (int i = 0; i < s; i++) p[i] = i;
}

int union_query(int n) {
    int res = n;
    while (p[res] != res) res = p[res];
    int m;
    while (d[n] != n) {
        m = d[n]; 
        d[n] = res;
        n = m;
    }
    return res;
}

void init() {
    for (int i = 0; i < n; ++i) {
        p[i] = i;
        h[i] = 0;
    }
}

int find(int node) {
    if (p[node] != node) {
        p[node] = find(p[node]);
    }
    return p[node];
}

void unite(int A, int B) {
    int rootA = find(A);
    int rootB = find(B);
    if (h[rootA] > h[rootB]) {
        p[rootB] = rootA;
        h[rootA] = max(h[rootA], h[rootB] + 1);
    } else {
        p[rootA] = rootB;
        h[rootB] = max(h[rootB], h[rootA] + 1);
    }
}

int main() {
    freopen("", "r", stdin);
    freopen("", "w", stdout);
    scanf("%d%d", &n, &m);
    a.resize(m), b.resize(m), order.resize(n + 1);
    p.resize(n + 1), place.resize(n + 1), h.resize(n + 1);

    for (int i = 0; i < m; i++) scanf("%d%d", &a[i], &b[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &order[i]);
        p[order[i]] = i;
    }
}