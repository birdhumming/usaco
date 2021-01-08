#include <iostream>
#include <algorithm>
using namespace std;

const int N = 50010;
int n, k;
int d[N], track_min[N], track_max[N];

int from_min(int len) {
    int sum = 0, start = d[0], i = 0;
    int ans = 0; 
    while (i < n && d[i] - start <= len) sum++, i++;
    track_min[0] = sum;
    if (i == n) return sum;

    for (int j = 1; j < n; j++) {
        start = d[j];
        sum--;
        while (i < n && d[i] - start <= len) sum++, i++;
        track_min[j] = sum;
        ans = max(sum, ans);
    }
    return ans;
}

int from_max(int len) {
    int sum = 0, start = d[n - 1], i = n - 1;
    int ans = 0;
    while (i >= 0 && start - d[i] <= len) sum++, i--;
    track_max[n - 1] = sum;
    if (i <= 0) return sum;
    
    for (int j = n - 2; j >= 0; j--) {
        start = d[j];
        sum--;
        while (i >= 0 && start - d[i] <= len) sum++, i--;
        track_max[j] = sum;
        ans = max(sum, ans);
    }
    return ans;
}

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> d[i];
    sort(d, d + n);

    from_min(k);
    from_max(k);

    /*for (int i = 0; i < n; i++) cout << track_min[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << track_max[i] << " ";
    cout << endl;*/

    for (int i = 1; i < n; i++) track_max[i] = max(track_max[i], track_max[i - 1]);
    for (int i = n - 2; i >= 0; i--) track_min[i] = max(track_min[i], track_min[i + 1]);

    int ans = track_min[0];
    for (int i = 1; i < n; i++) ans = max(track_min[i] + track_max[i - 1], ans);

    cout << ans << endl;

}