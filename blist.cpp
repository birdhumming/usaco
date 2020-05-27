#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, int> c;
vector<c> m;
int t[101] = {0};

int fill_chain(int ind) { //given a starting index in vector m, 
//build a chain of non-overlapping milkings
    int buckets=0;
    for (int i=ind; i<N; i++) {}

}

int main() {
    ifstream fin ("blist.in");
    ofstream fout ("blist.out");
    int N; fin>>N;
    m.resize(N);
    for (int i=0; i<N; i++) {
        fin>>m[i].first.first>>m[i].first.second>>m[i].second;
    }
    sort(m.begin(), m.end());
    for (int i=0; i<N; i++) {

    }
}