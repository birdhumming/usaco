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
vector<int> c;
vector<bool> s;

int main() {
    //freopen("cbarn.in", "r", stdin);
    //freopen("cbarn.out", "w", stdout);
    scanf("%d", &n); c.resize(n + 1); s.resize(n + 1);
    
    int max = -1, ind;
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        if (c[i] > max) ind = i, max = c[i];
    }


    for (int i = 0; i < n; i++) {
        int j = (i + ind) % n;
        
    }
}