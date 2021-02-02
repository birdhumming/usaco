#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>

using namespace std;

typedef pair<int, int> ii;

const int N = 1e5 + 10, K = 2 * N;
int n, k;
unordered_set<int> A[N];
ii swaps[K];
int cows[N], pos[N], cnt[N];
bool visited[N];

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        //cout << a << " " << b << endl;
        swaps[i].first = a, swaps[i].second = b;
    }

    for (int i = 1; i <= n; i++) A[i].insert(i), cows[i] = i;

    //simulate swaps once
    for (int j = 0; j < k; j++) {
        int a = swaps[j].first, b = swaps[j].second;
        int cow1 = cows[a];
        int cow2 = cows[b];
        A[cow1].insert(b);
        A[cow2].insert(a);
        swap(cows[a], cows[b]);
    }

    for (int i = 1; i <= n; i++) pos[cows[i]] = i;

    for (int i = 1; i <= n; i++) {
        //cout << "i = " << i << endl;
        if (visited[i]) continue;
        vector<int> nodes;
        unordered_set<int> track = A[i];

        int start = i, cur = pos[i];
        visited[start] = true;
        nodes.push_back(start);
        
        while (cur != start) {
            visited[cur] = true;
            nodes.push_back(cur);
            for (int x : A[cur]) track.insert(x);
            cur = pos[cur];
        }

        int sz = track.size();
        for (int node : nodes) cnt[node] = sz;
    }

    for (int i = 1; i <= n; i++) cout << cnt[i] << endl;
}
