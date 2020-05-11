#include <iostream>
#include <fstream>
using namespace std;
 
int N, incoming[101], outgoing[101];
 
int main(void)
{
    ifstream fin ("factory.in");
    ofstream fout ("factory.out");
    fin>>N;
    for (int i=0; i<N-1; i++)
    {
        int a, b;
        fin>>a>>b;
        outgoing[a]++;
        incoming[b]++;
    }
    int ans=-1;
    for (int i=1; i<=N; i++)
    {
        if (outgoing[i]==0 && ans!=-1) { ans=-1; break; }
        if (outgoing[i]==0) { ans=i; }
    }
    fout<<ans;
}  
