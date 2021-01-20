/*
ID: drayale1
LANG: C++
TASK: humble
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
const int K = 110, N = 100000;
int k, n, p[K];

struct d {
    int v, p, k;
    bool operator< (const d& t) const {
        return v > t.v;
    }
};

int main()
{
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);
    int n, k;
    cin >> k >> n;
    n++;

    vector<int> q(1, 1);
    priority_queue<d> heap;

    while (k--) {
        int p; cin >> p;
        heap.push({p, p, 0});
    }


    while (q.size() < n) {
        auto t = heap.top();
        heap.pop();

        q.push_back(t.v);
        heap.push({t.p * q[t.k + 1], t.p, t.k + 1});

        while (heap.top().v == t.v) {
            auto r = heap.top();
            heap.pop();
            heap.push({r.p * q[r.k + 1], r.p, r.k + 1});
        }
    }

    cout << q.back() << endl;
}