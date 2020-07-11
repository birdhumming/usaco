#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef pair<int, pair<int, int> > iii;

int N, G;
bool comp (iii a, iii b) {
    return a.first < b.first;
}

int main() 
{
    cin>>N>>G;
    iii changes[100001];
    for (int i=0; i<N; i++) {
        cin>>changes[i].first>>changes[i].second.first;
        char c; cin>>c;
        int x; cin>>x;
        if (c=='+') changes[i].second.second=x;
        if (c=='-') changes[i].second.second=-1*x;
    }
    sort (changes, changes+N, comp);

}