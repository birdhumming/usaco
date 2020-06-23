#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int cow[100001];

int main()
{
    ifstream fin ("lemonade.in");
    ofstream fout ("lemonade.out");
    int N; fin>>N;
    int w, g=0, c=0;
    for (int i=1; i<=N; i++) {
        fin>>w;
        if (w>=N-1) g++; //can wait behind too many cows, must be included
        else {
            c++; cow[c]=w;
        }
        //cout<<"i = "<<i<<", w = "<<w<<'\n';
    }
    if (g==N) {
        fout<<N<<'\n'; 
        return 0;
    }
    //cout<<"g = "<<g<<", c = "<<c<<'\n';
    sort(cow, cow+c+1);
    //for (int i=1; i<=c; i++) cout<<cow[i]<<" ";
    //cout<<'\n';

    for (int i=c; i>=1; i--) {
        if (g <= cow[i]) {
            //cout<<"current w: "<<cow[i]<<'\n';
            g++;
            //cout<<"g = "<<g<<'\n';
        } //cow i joins the line
        else break;
    }
    fout<<g<<'\n';
}