#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long x, y;

string make_string(int d, int len) 
{
    string ans="";
    string ds=to_string(d);
    for (int i=0; i<len; i++) {
        ans = ans+ds;
    }
    return ans;
}

char int_to_char(int x) 
{
    if (x==0) return '0';
    if (x==1) return '1';
    if (x==2) return '2';
    if (x==3) return '3';
    if (x==4) return '4';
    if (x==5) return '5';
    if (x==6) return '6';
    if (x==7) return '7';
    if (x==8) return '8';
    if (x==9) return '9';
}

int main()
{
    cin>>x>>y;
    string xs, ys;
    xs=to_string(x);
    ys=to_string(y);
    int ans=0;
    for (int i=3; i<=ys.length(); i++) {
        for (int m=1; m<=9; m++) {
            for (int s=0; s<=9; s++) {
                if (s != m) {
                    for (int pos=0; pos<i; pos++) {
                        string z=make_string(m, i);
                        if (!(pos==0 && s==0)) {
                            char c= int_to_char(s);
                            z[pos]=c;
                            long zi=stol(z);
                            if (x<=zi && y>=zi) {
                                ans++;
                                cout<<zi<<'\n';
                            }
                        }
                    }
                }
            }
        }
        for (int s=1; s<=9; s++) { //m=0
            long z=s * pow(10, i-1);
            if (x<=z && y>=z) {
                cout<<z<<'\n';
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}