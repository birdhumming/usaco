#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int a, b, x, y;

int solve(int start, int end, int x, int y) {
    int d1 = abs(start - x) + abs(end - y);
    int d2 = abs(start - y) + abs(end - x);

    int ans = min(abs(start - end), min(d1, d2));
    return ans;
}

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    scanf("%d%d%d%d", &a, &b, &x, &y);
    printf("%d\n", solve(a, b, x, y));
    return 0;
}