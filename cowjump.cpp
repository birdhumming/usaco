#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 10;
int n;
struct line {
    ll x1, y1, x2, y2;
} lines[N];

bool cmp(pair<ii, int> a, pair<ii, int> b) {
    return a.first.second < b.first.second;
}

bool in_line(line a, line b) {
    if (a.y1 == a.y2 && b.y1 == b.y2 && a.y2 == b.y2) return true;
    if (a.x1 == a.x2 && b.x1 == b.x2 && a.x2 == b.x2) return true;
    return false;
}

bool crosses(line a, line b) {
    if (in_line(a, b)) return true;

    ii a1 = make_pair(a.x1, a.y1);
    ii a2 = make_pair(a.x2, a.y2);
    ii b1 = make_pair(b.x1, b.y1);
    ii b2 = make_pair(b.x2, b.y2);
    
    if (a1 == b1 || a1 == b2 || a2 == b1 || a2 == b2) return true;

    vector<pair<ii, int> > v;
    v.push_back(make_pair(a1, 1));
    v.push_back(make_pair(a2, 1));
    v.push_back(make_pair(b1, 2));
    v.push_back(make_pair(b2, 2));

    sort(v.begin(), v.end(), cmp);

    ii A = v[0].first; int id_A = v[0].second;
    ii B = v[1].first; int id_B = v[1].second;
    ii C = v[2].first; int id_C = v[2].second;
    ii D = v[3].first; int id_D = v[3].second;

    if (A.first > B.first) {
        swap(A, B); swap(id_A, id_B);
    }

    if (D.first > C.first) {
        swap(D, C); swap(id_D, id_C);
    }
    
    if (id_A == 1 && id_B == 2 && id_C == 1 && id_D == 2) return true;
    if (id_A == 2 && id_B == 1 && id_C == 2 && id_D == 1) return true;

    return false;
}

int main() {
    //freopen("cowjump.in", "r", stdin);
    //freopen("cowjump.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x2 < x1) {
            swap(x1, x2);
            swap(y1, y2);
        }

        lines[i].x1 = x1, lines[i].y1 = y1;
        lines[i].x2 = x2, lines[i].y2 = y2;
    }

    if (crosses(lines[0], lines[1])) cout << "true\n";
    else cout << "false\n";

}