#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int N;
vector<string> traits[26];
vector<string> all_traits;
bool crossing(int a, int b)
{
    int A=0, B=0, AB=0;
    for (int i=0; i<N; i++)
    {
        vector <string> v=traits[i];
        bool has_a=false, has_b=false;
        for (int j=0; j<v.size(); j++)
        {
            if (v[j]==all_traits[a]) has_a=true;
            if (v[j]==all_traits[b]) has_b=true;
        }
        if (has_a && has_b) { AB++; }
        else if (has_a) { A++; }
        else if (has_b) { B++; }
    }
    return AB>0 && A>0 && B>0;
}

int main()
{
    ifstream fin ("evolution.in");
    ofstream fout ("evolution.out");
    fin>>N;
    string s;
    for (int i=0; i<N; i++)
    {
        int K; fin>>K;
        for (int j=0; j<K; j++)
        {
            fin>>s;
            traits[i].push_back(s);
            bool found=true;
            for (int k=0; k<all_traits.size(); k++)
                if (all_traits[k]==s) { found=false;}
            if (found) { all_traits.push_back(s); }
        }
    }
    int size=all_traits.size();
    bool works=true;
    for (int i=0; i<size; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (crossing(i, j)) works=false;
        }
    }
    if (works) { fout<<"yes"; }
    else { fout<<"no"; }
}