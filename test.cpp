#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, edges[N];

int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        edges[a]++, edges[b]++;
    }

    int max_edges = 0;
    for (int i = 1; i <= n; i++) 
        max_edges = max(edges[i], max_edges);
    
    cout << max_edges + 1 << endl;
}