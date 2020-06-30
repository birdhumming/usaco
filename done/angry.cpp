#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N, K;
int bales[50001];

bool cover(int r)
{
    int c=1;
    int b=bales[0]+2*r;
    for (int i=0; i<N; i++) {
        if (bales[i] > b) {
            c++;
            b=bales[i]+2*r;
        }
    }
    //cout<<c<<'\n';
    if (c>K) return false;
    return true;
}

int bin_search(int low, int mid, int hi)
{
    //cout<<mid<<'\n';
    if (cover(mid) && !cover(mid-1)) {
        //cout<<mid<<" "<<mid-1<<'\n';
        return mid;
    }
    if (cover(mid)) return bin_search(low, (low+mid)/2, mid);
    else return bin_search(mid+1, (mid+1+hi)/2, hi);

}

int main()
{
    //ifstream fin ("angry.in");
    cin>>N>>K;
    for (int i=0; i<N; i++) cin>>bales[i];
    sort(bales, bales+N);
    int r = bin_search(1, (bales[0]+bales[N-1])/2, bales[N-1]-bales[0]);
    //if (cover(1)) cout<<"39\n";
    cout<<r<<'\n';
}
