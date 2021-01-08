#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int N = 1e5 + 10, mod = 1e9 + 7;
int n;
ii a[N];
unordered_map<int, vector<int> > x_line_of_y, y_line_of_x;
unordered_map<int, unordered_map<int, ll> > y_x_len, x_y_len;

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        x_line_of_y[a[i].second].push_back(a[i].first);
        y_line_of_x[a[i].first].push_back(a[i].second);
    }

    for (auto p : x_line_of_y) 
        sort(p.second.begin(), p.second.end());
    for (auto p : y_line_of_x)
        sort(p.second.begin(), p.second.end());

    for (auto p : x_line_of_y) {
        int y = p.first;
        vector<int> v = p.second;
        int size = v.size();

        ll sum = 0;
        for (int i = 1; i < size; i++) 
            sum += v[i] - v[0];
        //store sum_0
        y_x_len[y][v[0]] = sum;
        for (int i = 1; i < size; i++) {
            ll sum_i = sum;
            int c = i - 1, d = size - i - 1;
            sum_i += (c - d) * (v[i] - v[i - 1]);
            y_x_len[y][v[i]] = sum_i;
            sum = sum_i;
        }
    }

    for (auto p : y_line_of_x) {
        int x = p.first;
        vector<int> v = p.second;
        int size = v.size();

        ll sum = 0;
        for (int i = 1; i < size; i++) 
            sum += v[i] - v[0];
        x_y_len[x][v[0]] = sum;
        for (int i = 1; i < size; i++) {
            ll sum_i = sum;
            int c = i - 1, d = size - i - 1;
            sum_i += (c - d) * (v[i] - v[i - 1]);
            x_y_len[x][v[i]] = sum_i;
            sum = sum_i;
        }
    }
    
    /*for (auto p : y_x_len) {
        cout << "Y = "<<p.first<<endl;
        for (auto p1 : p.second) {
            cout << "x = "<<p1.first<<endl;
            cout << "len = "<<p1.second<<endl;
        }
    }

    for (auto p : x_y_len) {
        cout << "X = "<<p.first<<endl;
        for (auto p1 : p.second) {
            cout << "y = "<<p1.first<<endl;
            cout << "len = "<<p1.second<<endl;
        }
    }*/

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i].first, y = a[i].second;
        ll sum = y_x_len[y][x] * x_y_len[x][y];
        sum %= mod;
        ans += sum;
        ans %= mod;
    }
    cout << ans << endl;
}