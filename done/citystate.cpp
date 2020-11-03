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

int n;
unordered_map<string, int> cnt;

int main() {
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string city, state;
        cin >> city >> state;
        
        string init = city.substr(0, 2);
        string code = init + state;
        string reverse = state + init;
        //cout<<"code = "<<code<<endl;
        //cout<<"reverse = "<<reverse<<endl;
        //cout<<"cnt[reverse] = "<<cnt[reverse]<<endl;
        if (init != state) ans += cnt[reverse];
        cnt[code]++;
    }
    cout<<ans<<endl;
    return 0;
}