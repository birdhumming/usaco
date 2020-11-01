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

int n, k;
vector<int> d;
int ans = INT_MIN;

void find(int l, int r) {
    int mid = (l + r) >> 1;
    int num = check(mid);
    if (num > ans) {
        ans = num;
        find()
    }
}

int main() {
    //freopen("diamond.in", "r", stdin);
    //freopen("diamond.out", "w", stdout);
    scanf("%d%d", &n, &k); d.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &d[i]);

    

}