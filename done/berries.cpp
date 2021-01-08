#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1010;
int n, k, b[N];

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    cin >> n >> k;
    int max_b = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        max_b = max(b[i], max_b);
    }

    int ans = 0;
    
    for (int i = 1; i <= max_b; i++) {
        priority_queue<int> heap;
        for (int i = 0; i < n; i++) heap.push(b[i]);

        for (int i = 0; i < k / 2; i++) {
            if (heap.empty()) continue;
            int next = heap.top();
            heap.pop();
            if (next < i) continue;
            if (next > i) heap.push(next - i); //can still use
        }

        int bessie = 0, cnt = 0;
        while (heap.size() && cnt < k / 2) {
            int next = heap.top();
            heap.pop();
            cnt++;

            if (next > i) {
                bessie += i;
                heap.push(next - i);
            }
            else bessie += next; //take entire bush
        }

        ans = max(bessie, ans);
    
    cout << ans << endl;
}