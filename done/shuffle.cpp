#include <iostream>
#include <vector>
using namespace std;

int N;
vector <int> indegrees;
vector <int> out;

int dead=0;

void run(int i)
{
    if (indegrees[i] != 0) return;
    dead++;
    indegrees[i]=-1;
    indegrees[out[i]]--;
    if (indegrees[out[i]]==0) {
        run(out[i]);
    } 
}

int main()
{
    cin>>N;
    indegrees.resize(N+1);
    out.resize(N+1);
    for (int i=1; i<=N; i++) {
        int x; cin>>x;
        indegrees[x]++;
        out[i]=x;
    }

    for (int i=1; i<=N; i++) {
        if (indegrees[i]==0) {
            run(i);
        }
    }
    cout<<N-dead<<'\n';
}