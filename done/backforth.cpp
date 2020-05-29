#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int poss_ans[2000];

void friday(int b1milk, vector<int> b1, vector<int> b2) 
{
    for (int i=0; i<b2.size(); i++) {
        int x=b2[i];
        poss_ans[b1milk+x]=1;
    }
}

void thursday(int b1milk, vector<int> b1, vector<int> b2) 
{
    for (int i=0; i<b1.size(); i++) {
        int x=b1[i];
        vector<int> new_b2=b2; new_b2.push_back(x);
        vector<int> new_b1=b1; new_b1.erase(new_b1.begin()+i);
        friday(b1milk-x, new_b1, new_b2);
    }
}

void wednesday(int b1milk, vector<int> b1, vector<int> b2) 
{
    for (int i=0; i<b2.size(); i++) {
        int x=b2[i];
        vector<int> new_b1=b1; new_b1.push_back(x);
        vector<int> new_b2=b2; new_b2.erase(new_b2.begin()+i);
        thursday(b1milk+x, new_b1, new_b2);
    }
}

void tuesday(int b1milk, vector<int> b1, vector<int> b2)
{
    for (int i=0; i<b1.size(); i++) {
        int x=b1[i];
        vector<int> new_b2=b2; new_b2.push_back(x);
        vector<int> new_b1=b1; new_b1.erase(new_b1.begin()+i);
        wednesday(b1milk-x, new_b1, new_b2);
    }
}

int main()
{
    int n, ans=0;
    vector<int> b1, b2;
    ifstream fin ("backforth.in");
    ofstream fout ("backforth.out");
    for (int i=0; i<10; i++) { fin>>n; b1.push_back(n); }
    for (int i=0; i<10; i++) { fin>>n; b2.push_back(n); }

    tuesday(1000, b1, b2);

    for (int i=0; i<2000; i++) {
        ans+=poss_ans[i];
    }
    fout<<ans;
}

