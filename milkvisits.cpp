#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
vector <int> AL[100010];
int label[100010];
int curLabel = 1;
string s; 

void flood(int n)
{
    label[n] = curLabel;
    for (int i=0; i<AL[n].size(); i++) {
        int next=AL[n][i];
        if (label[next]==0 && s[next-1]==s[n-1]) {
            flood(next);
        }
    }
}

int main()
{
    //freopen("milkvisits.in", "r", stdin);
    //freopen("milkvisits.out", "w", stdout);
    cin >> N >> M;
    cin >> s;
    for (int i = 0; i < N - 1; i++) {
        int x, y; cin >> x >> y;
        AL[x].push_back(y);
        //AL[y].push_back(x);
    }

    for (int i=1; i<=N; i++) {
        if (label[i]==0) {
            flood(i);
            curLabel++;
        }
    }

    for (int i=1; i<=N; i++) cout<<label[i]<<'\n';

    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        char c; cin>>c;
        if (label[a] != label[b]) {
            cout<<1;
        }
        else if (s[a-1]==c) cout<<1;
        else cout<<0;
    }
    cout<<'\n';
}