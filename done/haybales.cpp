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
#define ii pair<int, int>;
#define ll long long;

int n, q;
vector<int> h, pref; 

int solve(int limit) {
    if (h[0] > limit) return 0;
    int min = 0, max = h.size() - 1;
    while (min != max) {
        int mid = (min + max + 1) >> 1;
        if (h[mid] <= limit) min = mid;
        else max = mid - 1;
    }
    return min + 1;
}

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x); h.push_back(x);
    }
    sort(h.begin(), h.end());
    for (int i = 0; i < q; i++) {
        int a, b; scanf("%d%d", &a, &b);
        int res = solve(b) - solve(a - 1);
        printf("%d\n", res);
    }
    return 0;
}