#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <set>
using namespace std;
 
typedef pair<int, int> ii;
typedef long long ll;

const int N = 2 * 1e5 + 10;
int x, n, p[N], tmp[N];
priority_queue<ll> heap;
set<ll> lights;
vector<ll> ans;
 
int main() {
    cin >> x >> n;
    lights.insert(0); lights.insert(x);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        tmp[i] = p[i];
        lights.insert(p[i]);
    }
    
    sort(tmp, tmp + n);
    for (int i = 1; i < n; i++) heap.push(tmp[i] - tmp[i - 1]);
    heap.push(tmp[0]);
    heap.push(x - tmp[n - 1]);
    ans.push_back(heap.top());
    
    for (int i = n - 1; i >= 0; i--) {
        //cout << "p[i] = "<<p[i]<<endl;
        auto upper = lights.upper_bound(p[i]);
        auto lower = lights.lower_bound(p[i]);
        lower--;
        lights.erase(lights.find(p[i]));
        ll dist = *upper - *lower;
        heap.push(dist);
        if (i) ans.push_back(heap.top());
    }

    reverse(ans.begin(), ans.end());
    for (int x : ans) cout << x << " ";
}

//do it backwards!