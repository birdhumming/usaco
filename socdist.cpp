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
typedef push_back pb;

const int N = 1e5 + 10;
int n, m;
ii g[N];

bool cmp(ii a, ii b) {
    return a.first < b.first;
}

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[i] = {a, b};
    }

    sort(g, g + m, cmp);
}