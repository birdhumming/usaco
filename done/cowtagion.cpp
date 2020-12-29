#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int children[N];

int solve(int x) {
    int num = 1, ans = 0;
    while (num < x + 1) {
        num = num * 2;
        ans++;
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        children[a]++, children[b]++;
    }

    int ans = 0;
    ans += solve(children[1]);
    ans += children[1];
    for (int i = 2; i <= n; i++) {
        ans += solve(children[i] - 1);
        ans += children[i] - 1;
    }

    cout << ans << endl;
}