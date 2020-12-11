/*
ID: drayale1
LANG: C++
TASK: frac1
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

void dfs(int a, int b, int c, int d) {
    if (b + d > n) return;
    dfs(a, b, a + c, b + d);
    printf("%d/%d\n", a + c, b + d);
    dfs(a + c, b + d, c, d);
}
int main() {
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    cin >> n;
    puts("0/1");
    dfs(0, 1, 1, 1);
    puts("1/1");
    return 0;
}