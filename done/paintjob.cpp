#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

int a, b, n, p;
vector <int> paints;
vector <bool> visited;

int main()
{
    cin>>a>>b>>n>>p;
    paints.resize(n);
    visited.resize(p+1);

    for (int i=0; i<n; i++) cin>>paints[i];

    queue <ii> q;
    q.push(make_pair(a, 0));
    while (!q.empty()) {
        int pa=q.front().first;
        int ind=q.front().second;
        if (pa==b) {
            cout<<ind<<'\n';
            return 0;
        }
        for (int i=0; i<n; i++) {
            int ap=(pa*paints[i]) % p;
            if (!visited[ap]) {
                q.push(make_pair(ap, ind+1));
                visited[ap]=true;
            }
        }
        q.pop();
    }
    cout<<-1<<'\n';
}