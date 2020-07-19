#include <iostream>
#include <vector>
using namespace std;

int c[9];
int changes[9][9] = {
    {1, 1, 0, 1, 1, 0, 0, 0, 0}, //1 ABDE
    {1, 1, 1, 0, 0, 0, 0, 0, 0}, //2 ABC
    {0, 1, 1, 0, 1, 1, 0, 0, 0}, //3 BCEF
    {1, 0, 0, 1, 0, 0, 1, 0, 0}, //4 ADG
    {0, 1, 0, 1, 1, 1, 0, 1, 0}, //5 BDEFH
    {0, 0, 1, 0, 0, 1, 0, 0, 1}, //6 CFI
    {0, 0, 0, 1, 1, 0, 1, 1, 0}, //7 DEGH
    {0, 0, 0, 0, 0, 0, 1, 1, 1}, //8 GHI
    {0, 0, 0, 0, 1, 1, 0, 1, 1} //9 EFHI
};

vector <int> v, bestv;

bool valid()
{
    for (int i=0; i<9; i++) {
        if (c[i] != 0) return false;
    }
    return true;
}

int solve(int ind)
{
    cout<<ind<<'\n';
    if (v.size() >= bestv.size()) return 0;
    if (valid()) {
        cout<<"33\n";
        bestv.resize(v.size());
        for (int i=0; i<v.size(); i++) bestv[i]=v[i];
        return 0;
    }
    if (ind==9) {
        cout<<"38\n";
        return 0;
    }
    for (int i=0; i<4; i++) {
        for (int j=0; j<9; j++) {
            c[j]+= i*changes[ind][j];
            c[j] %= 4;
            //c[j]-= i*changes[ind][j];
        }
        for (int j=0; j<i; j++) v.push_back(ind);
        return solve(ind+1);
        for (int j=0; j<9; j++) {
            c[j]-= i*changes[ind][j];
        }
        for (int j=0; j<i; j++) v.pop_back();
    }
    return 0;
}

int main()
{
    for (int i=0; i<9; i++) {
        int x; cin>>x;
        if (x==3) c[i]=1;
        if (x==6) c[i]=2;
        if (x==9) c[i]=3;
        if (x==12) c[i]=0;
    }

    bestv.resize(1000);
    int x=solve(1);
    for (int i=0; i<bestv.size(); i++) {
        cout<<bestv[i]<<' ';
    }
    cout<<'\n';
}