#include <iostream>
using namespace std;
typedef pair <int, int> ii;

int N, Q;
int cows1[100002]; 
int cows2[100002]; 
int cows3[100002]; 
ii qs[100002];

int main()
{
    cows1[0]=0; cows2[0]=0; cows3[0]=0;
    cin>>N>>Q;
    int x;
    for (int i=1; i<=N; i++) {
        cin>>x;
        if (x==1) {
            cows1[i]++;
        }
        if (x==2) {
            cows2[i]++;
        }
        if (x==3) {
            cows3[i]++;
        }
        cows1[i]+=cows1[i-1];
        cows2[i]+=cows2[i-1];
        cows3[i]+=cows3[i-1];
    }
    for (int i=0; i<Q; i++) {
        int a, b;
        cin>>a>>b;
        if (a>b) {
            cout<<cows1[a]-cows1[b-1]<<" "<<cows2[a]-cows2[b-1]<<" "<<cows3[a]-cows3[b-1];
        }
        if (b>=a) {
            cout<<cows1[b]-cows1[a-1]<<" "<<cows2[b]-cows2[a-1]<<" "<<cows3[b]-cows3[a-1];
        }
        cout<<'\n';
    }
    
}
