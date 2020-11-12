#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define pb push_back
#define rz resize
#define mp make_pair

#define FOR(n) for (int i = 0; i < n; i++)
#define FOR1(n) for (int i = 1; i <= n; i++)
#define RFOR(n) for (int i = n - 1; i >= 0; i--)
#define DFOR(n, m) FOR(n) for (int j = 0; j < m; j++)

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int ddy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

bool in_bounds(int x, int y, int n, int m) {
    if (x >= 0 && x < n && y >= 0 && y < m) return true;
    return false;
}



int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int n = 6;
    vector<int> nums;
    nums = {}
    vector<char> sub;
        for (int j = 0; j < n; j++) {
            if (g[i][j] != 0) sub.pb(g[i][j]);
        }
        for (int j = 0; j < n - sub.size(); j++) g[i][j] = '0';
        for (int j = n - sub.size(), k = 0; j < n; j++, k++) g[i][j] = sub[k];
        for (int j = 0; j < n; j++) cout<<g[i][j]<<' ';
        cout<<endl;
    }
}

#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100000
 
int N;
int x[MAXN], y[MAXN];
int pos[MAXN], neg[MAXN];
int cid[MAXN];
 
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
 
int N, A[100000];
 
int solve_min(void)
{
  if (A[N-2]-A[0] == N-2 && A[N-1]-A[N-2]>2) return 2;
  if (A[N-1]-A[1] == N-2 && A[1]-A[0]>2) return 2;
  int i, j=0, best=0;
  for (i=0; i<N; i++) {
    while (j<N-1 && A[j+1]-A[i]<=N-1) j++;
    best = max(best, j-i+1);
  }
  return N-best;
}
 
int main(void)
{
  ifstream fin ("herding.in");
  fin >> N; 
  for (int i=0; i<N; i++) fin >> A[i];
  sort (A, A+N);
 
  ofstream fout ("herding.out");
  int answer_min = solve_min();
  int answer_max = max(A[N-2]-A[0], A[N-1]-A[1]) - (N-2);
  fout << answer_min << "\n" << answer_max << "\n";
  return 0;
}


