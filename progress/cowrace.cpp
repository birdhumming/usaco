#include <iostream>
using namespace std;

const int N = 1010;
int n, m;
int b_speed[N], b_time[N], e_speed[N], e_time[N];
int ttime = 0;

int main() {
    freopen("cowrace.in", "r", stdin);
    freopen("cowrace.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int s, t; cin >> s >> t;
        b_speed[i] = s, b_time[i] = t;
        ttime += t;
    }
    for (int i = 0; i < m; i++) {
        int s, t; cin >> s >> t;
        e_speed[i] = s, e_time[i] = t;
    }

    int ans = 0;
    int b_idx = 0, e_idx = 0;
    int bt = 0, et = 0;
    int b_dist = 0, e_dist = 0;
    int front = -1; //0 bessie, 1 elsie
    for (int i = 0; i < ttime; i++) {
        //cout << "i = " << i << endl;
        bt++, et++;
        b_dist += b_speed[b_idx];
        e_dist += e_speed[e_idx];
        //cout << "bt = " << bt << ", b_dist = " << b_dist << endl;
        //cout << "et = " << et << ", e_dist = " << e_dist << endl;
        if (b_dist > e_dist && front != 0) {
            front = 0;
            ans++;
        }
        if (e_dist > b_dist && front != 1) {
            front = 1;
            ans++;
        }
        //cout << "ans = " << ans << endl;
        if (bt == b_time[b_idx]) {
            bt = 0;
            b_idx++;
        }
        if (et == e_time[e_idx]) {
            et = 0;
            e_idx++;
        }
    }

    cout << ans - 1 << endl;
}