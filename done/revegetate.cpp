#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> pastures[101];

int main() {
    ifstream fin ("revegetate.in");
    ofstream fout ("revegetate.out");
    int N, M, a, b;
    fin>>N>>M;
    for (int i=0; i<M; i++) {
        fin>>a>>b;
        pastures[a].push_back(b);
        pastures[b].push_back(a);
    }
    vector<int> ans(N + 1, -1);
    for (int i=1; i <= N; i++) {
        int grass[5]={0, 0, 0, 0, 0};
        vector<int> v=pastures[i];
        if (v.size()==0) ans[i]=1;
        else {
            for (int j=0; j<v.size(); j++) {
                if (ans[v[j]] != -1) {
                    int x = ans[v[j]];
                    grass[x]=1;
                }
            }
            for (int j=1; j<5; j++) {
                if (grass[j]==0){
                    ans[i]=j;
                    break;
                }
            }
        }
    }
    for (int i=1; i<=N; i++)
    {
        fout<<ans[i];
    }
}