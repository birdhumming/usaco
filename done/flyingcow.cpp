#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

int N, low, upp;
vector <bool> visited;


int main()
{
    cin>>N;
    low=1; upp=N+2;
    visited.resize(N+3);
    queue <ii> q;
    q.push(make_pair(1, 0));
    while (!q.empty()) {
        if (q.front().first == N) { 
            cout<<q.front().second<<'\n'; 
            return 0;
        }
        int x=q.front().first-1;
        int y=q.front().first+1;
        int z=q.front().first*3;
        int ind=q.front().second+1;
        if (x >= 1 && x <= N+2 && !visited[x]) {
            q.push(make_pair(x, ind));
            visited[x]=true;
        }
        if (y>= 1 && y <= N+2 && !visited[y]) {
            q.push(make_pair(y, ind));
            visited[y]=true;
        }
        if (z >= 1 && z <= N+2 && !visited[z]) {
            q.push(make_pair(z, ind));
            visited[z]=true;
        }
        q.pop();
    }
}