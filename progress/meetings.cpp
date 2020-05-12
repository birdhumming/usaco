#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
int N, L;
vi w, x, d;
int find_time() {
    vi left, right;
    for (int i=0; i<N; i++){
        if (d[i] == -1) { left.push_back(x[i]); }
        else { right.push_back(x[i]); }
    }
    vpi v;
    for (int i=0; i<left.size(); i++) { v.push_back(make_pair(left[i], w[i])); }
    for (int i=0; i<right.size(); i++) { v.push_back(make_pair(L-right[i], w[left.size()+i])); }
    sort(v.begin(), v.end());
    int total = 0;
    for (int i=0; i<v.size(); i++) { total+=v[i].second; }
    for (int i=0; i<v.size(); i++) {
        total-= 2*v[i].second;
        cout << "weight = " << v[i].second << '\n';
        if (total<=0) return v[i].first;
    }
}

int main()
{
    ifstream fin("meetings.in");
    ofstream fout("meetings.out");
    fin>>N>>L;
    w.resize(N), x.resize(N), d.resize(N);
    for (int i=0; i<N; i++){
        fin>>w[i]>>x[i]>>d[i];
    }
    int T = find_time();


	vi inds(N); iota(all(inds),0);
	sort(all(inds),[](int a, int b) { return x[a] < x[b]; });
	vi W,X,D;
	trav(t,inds) {
		W.pb(w[t]);
		X.pb(x[t]);
		D.pb(d[t]);
	}
	swap(w,W), swap(x,X), swap(d,D);
}

}
