#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef pair<string, int> si;
const int N = 1e5 + 10;
int w, n;
int son[N][26], cnt[N], idx;
vector<si> words;

void insert(string str) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        cnt[p]++;
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
        cnt[p]++;
    }
}

int query(string str) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    freopen("auto.in", "r", stdin);
    freopen("auto.out", "w", stdout);
    cin >> w >> n;
    for (int i = 0; i < w; i++) {
        string word; cin >> word;
        words.push_back(make_pair(word, i));
    }

    sort(words.begin(), words.end());

    for (int i = 0; i < n; i++) {
        int k; string pref;
        cin >> k >> pref;
        int m = pref.size();
        //cout << "pref = " << pref << endl;

        int l = 0, r = w - 1;
        while (l < r) {
            //cout << "l = " << l <<", r = " << r << endl;
            int mid = (l + r) >> 1;
            if (words[mid].first.substr(0, m) >= pref) r = mid;
            else l = mid + 1;
        }

        int pos = l + k - 1;
        if (pos < w && words[pos].first.substr(0, m) == pref)
            cout << words[pos].second + 1<< endl;
        else cout << -1 << endl;
    }
}