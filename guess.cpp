#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int track[101][101];
vector<string> traits;

int in_traits(string t) {
    for (int i=0; i<traits.size(); i++) {
        if (traits[i]==t) return i;
    }
    return -1;
}

int main() {
    ifstream fin ("guess.in");
    ofstream fout ("guess.out");
    int N, K; fin>>N;
    string t;
    for (int i=0; i<N; i++) {
        fin>>t>>K;
        for (int j=0; j<K; j++) {
            fin>>t;
            int x=in_traits(t);
            if (x==-1) {
                x=traits.size();
                traits.push_back(t);
            }
            track[i][x]=1;
        }
    }
    int ans=0, tans=0;
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            //cout<<"comparing "<<i<<" and "<<j<<'\n';
            for (int k=0; k<101; k++) {
                if (track[i][k] && track[j][k]) {
                    //cout<<"both have trait "<<traits[k]<<'\n';
                    tans++;
                }
            }
            //cout<<tans<<'\n';
            if (tans>ans) ans=tans;
            tans=0;
        }
    }
    fout<<ans+1;
}