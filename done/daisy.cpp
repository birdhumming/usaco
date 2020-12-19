#include <iostream>
using namespace std;

const int N = 110;
int n, p[N], sum[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];

    for (int i = 1; i <= n; i++) sum[i] = p[i] + sum[i - 1];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int total_sum = sum[i] - sum[j - 1];
            int num_flowers = i - j + 1;
            if (total_sum % num_flowers) continue;
            int average = total_sum / num_flowers;
            for (int k = j; k <= i; k++) {
                if (p[k] == average) {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}