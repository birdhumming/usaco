#include <iostream>
#include <algorithm>
using namespace std;

int N, B, f[251], s[251], d[251];
int best=1000000;
int visited[251][251];

int dfs(int b, int p, int dis)
{
   //cout<<b<<' '<<p<<' '<<dis<<'\n';
   if (b > best || p>N || (b == B-1 && p!=N)) return 1000000;
   if (p==N) {
      best=min(best, dis);
      //cout<<"END\n";
      return best;
   }
   if (visited[b][p]!=0) return visited[b][p];
   else {
      visited[b][p]=dis;
      for (int i=b+1; i<B; i++) {
         if (s[i] >= f[p]) {
            dfs(i, p, dis+(i-b)); 
         }
      }
      for (int i=1; i<=d[b]; i++) {
         if (p+i <= N) {
            if (f[p+i] <= s[b]) {
               dfs(b, p+i, dis);
            }
         }
      }
      return dis;
   }
}

int main()
{
   cin>>N>>B;
   for (int i=0; i<N; i++) cin>>f[i];
   for (int i=0; i<B; i++) cin>>s[i]>>d[i];
   int ans = dfs(0, 0, 0);
   cout<<best<<'\n';
}