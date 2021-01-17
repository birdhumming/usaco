#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 50010;
int n, g, b, d;
ii stations[N];

int main() {
    cin >> n >> g >> b >> d;
    for (int i = 0; i < n; i++) cin >> stations[i].first >> stations[i].second;

    sort(stations, stations + n);

    ll spent = 0, dist = 0;

    if (stations[0].first > b) {
        cout << -1 << endl;
        return 0;
    }

    int i = 0;
    set<ii> track;
    while (i < n && stations[i].first - stations[0].first <= g) {
        i++;
        track.insert(make_pair(stations[i].second, stations[i].first));
    }

    for (int j = 0; j < n; j++) {
        cout << "j = " << j << endl;
        if (j != 0) {
            while (i < n && stations[i].first - stations[j].first <= g) {
                i++;
                track.insert(make_pair(stations[i].second, stations[i].first));
            }
        }

        auto it = track.begin();
        ii t = *it;
        int x = t.second, cost = t.first;

        /*if (t == stations[j]) {

        }
        else {*/
            ll lack = (x - stations[j].first) - b;
            cout << "lack = " << lack << endl;
            if (lack > 0) {
                spent += (lack * cost);
                b += (x - stations[j].first);
            }
            cout << " ok\n";
            auto cur = track.find(make_pair(stations[j].second, stations[j].first));
            cout << "i want \n";
            track.erase(cur);
            cout <<"to die \n"<<endl;
        //}
    }

    
}