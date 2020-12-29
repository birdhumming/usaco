#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

struct p {
    int start, end;
    int id;
    bool operator< (const p& t) const {
        if (start != t.start) return start < t.start;
        return end < t.end;
    }
};

const int N = 2 * 1e5 + 10;
int n;
p a[N];
priority_queue<ii, vector<ii>, greater<ii> > heap;
int track[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].start >> a[i].end;
        a[i].id = i;
    }
    
    sort(a, a + n);

    int k = 1;
    heap.push(make_pair(a[0].end, k));
    track[0] = k;

    for (int i = 1; i < n; i++) {
        cout << "a[i].start = "<<a[i].start<<endl;
        cout << "a[i].end = "<<a[i].end << endl;
        if (a[i].start <= heap.top().first) {
            cout <<"NEW ROOM \n";
            k++;
            heap.push(make_pair(a[i].end, k));
            track[a[i].id] = k;
            cout << "k = "<<k<<endl;
        }
        else {
            ii t = heap.top();
            cout << "ADDING TO ROOM "<<t.second << ", end = "<<t.first << endl;
            heap.pop();
            heap.push(make_pair(a[i].end, t.second));
            track[a[i].id] = t.second;
        }
    }

    cout << heap.size() << endl;
    for (int i = 0; i < n; i++) cout << track[i] << " ";
    cout << endl;
}