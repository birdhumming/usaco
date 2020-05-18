#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<pair<pair<int, int>, int> > swaps; //shell, shell, guess

int main() {
    ifstream fin ("shell.in");
    ofstream fout ("shell.out");
    int N; fin>>N;
    pair<pair<int, int>, int> temp;
    for (int i=0; i<N; i++) {
        fin>>temp.first.first>>temp.first.second>>temp.second;
        swaps.push_back(temp);
    }
    int shells[4]={0, 0, 0, 0}; //indices 0, 1, 2, 3
    int ans=0, temp_ans=0;
    int a, b, g;
    for (int i=1; i<=3; i++) {
        shells[i]=1; //set each shell (1, 2, 3) to have pebble
        for (int j=0; j<N; j++) {
            a=swaps[j].first.first, b=swaps[j].first.second, g=swaps[j].second;
            if (shells[a]) { //shell a has pebble
                shells[b]=1; shells[a]=0; //b now has pebble, a doesn't
            }
            else if (shells[b]) { //b has pebble
                shells[a]=1; shells[b]=0;
            }
            if (shells[g]) { //guessed shell has pebble
                temp_ans++; 
            }
        }
        if (temp_ans>ans) ans=temp_ans; //finding max
        for (int j=0; j<4; j++) shells[j]=0; //reset
        temp_ans=0;
    }
    fout<<ans;
}