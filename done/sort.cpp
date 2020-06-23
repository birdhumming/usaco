#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;



struct Entry {
    int ind;
    int val;
};
Entry entries[100000];

bool comp(Entry i, Entry j) {
    return i.val<j.val || (i.val==j.val && i.ind<j.ind);
}

int main()
{
    ifstream fin ("sort.in");
    ofstream fout ("sort.out");
    int n; fin>>n;
    for (int i=0; i<n; i++) {
        entries[i].ind=i;
        fin>>entries[i].val;
    }

    sort(entries, entries+n, comp);
    for (int i=0; i<n; i++) {
        entries[i].val=i;
    }
    int ans=0;
    for (int i=0; i<n; i++) {
        ans=max(ans, entries[i].ind-entries[i].val);
    }

    fout<<ans+1<<'\n';
}