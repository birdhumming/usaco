#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

int a, b, c;
vector <ii> ap; vector<ii> bp; vector<ii> cp;




int main()
{
    cin>>a>>b>>c;
    ap.resize(a); bp.resize(b); cp.resize(c);
    for (int i=0; i<a; i++) cin>>ap[i].first>>ap[i].second;
    for (int i=0; i<b; i++) cin>>bp[i].first>>bp[i].second;
    for (int i=0; i<c; i++) cin>>cp[i].first>>cp[i].second;



}

