#include <iostream>
using namespace std;

int adjmat[58][58];

int remove(int node)
{
    if (node==0 || node==25) return 0;
    for (int i=0; i<58; i++) {
        if (adjmat[node][i] > 0) return 0;
    }
    for (int i=0; i<58; i++) {
        if (adjmat[i][node] > 0) {
            adjmat[i][node]=0;
            remove(i);
        }
    }
    return 0;
}

int reduce(int node)
{
    if (node==0 || node==25) return 0;
    int p=-1, c=-1;
    for (int i=0; i<58; i++) {
        if (adjmat[i][node]) {
            if (p >= 0) return 0;
            p=i;
        }
        if (adjmat[node][i]) {
            if (c >= 0) return 0;
            c=i;
        }
    }
    if (p==-1 || c==-1) return 0;
    adjmat[p][c] += min(adjmat[p][node], adjmat[node][c]);
    adjmat[p][node]=0; adjmat[node][c]=0;
    reduce(p);
    reduce(c); 
    return 0;
}

void print()
{
    for (int i=0; i<58; i++) {
        for (int j=0; j<58; j++) {
            cout<<adjmat[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"END\n";
}

int main()
{
    int N; cin>>N;
    for (int i=0; i<N; i++) {
        char a, b; cin>>a>>b;
        int c; cin>>c;
        int ia=a-65; int ib=b-65;
        cout<<a<<' '<<b<<'\n';
        cout<<ia<<' '<<ib<<'\n';
        adjmat[ia][ib]+=c;
    }
    cout<<"63\n";
    for (int i=0; i<58; i++) {
        remove(i);
    }
    for (int i=0; i<58; i++) {
        reduce(i);
    }
    //print();
    cout<<adjmat[0][25]<<'\n';
}