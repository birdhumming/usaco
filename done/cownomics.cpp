#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int N, M;
string spot[501];
string plain[501];
bool track[334]={false};

int str_int(char a, char b, char c) {
    int ans=0;
    
    if (a=='C') ans+=100;
    if (a=='G') ans+=200;
    if (a=='T') ans+=300;
    if (b=='C') ans+=10;
    if (b=='G') ans+=20;
    if (b=='T') ans+=30;
    if (c=='C') ans+=1;
    if (c=='G') ans+=2;
    if (c=='T') ans+=3;

    return ans;
}
void reset() {
    for (int i=0; i<334; i++) track[i]=false;
}

int main()
{
    cin>>N>>M;
    for (int i=0; i<N; i++) cin>>spot[i];
    for (int i=0; i<N; i++) cin>>plain[i];

    int ans=0;
    for (int i=0; i<M; i++) {
        for (int j=i+1; j<M; j++) {
            for (int k=j+1; k<M; k++) {
                reset();
                ans++;
                for (int c=0; c<N; c++) {
                    int t=str_int(spot[c][i], spot[c][j], spot[c][k]);
                    track[t]=true;
                }
                for (int c=0; c<N; c++) {
                    int t=str_int(plain[c][i], plain[c][j], plain[c][k]);
                    if (track[t]) {
                        //cout<<"breaking at i = "<<i<<", j = "<<j<<", k = "<<k<<" because cow "<<c<<" overlaps at "<<t<<'\n';
                        ans--;
                        break;
                    }
                }
            }
        }
    }
    cout<<ans<<'\n';
}