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

int n;
int first_seen[10];

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    scanf("%d", &n);
    memset(first_seen, -1, sizeof first_seen);

    if (n == 1) {
        int x; scanf("%d", &x);
        if (x % 7 == 0) puts("1");
        else puts("0");
        return 0;
    }

    int last = 0, cur = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        
        cur = (last + x) % 7;
        last = cur;
        if (first_seen[cur] != -1) {
            int first = first_seen[cur];
            ans = max(ans, i - first);
        } 
        else first_seen[cur] = i;
    }

    printf("%d\n", ans);

    return 0;
}