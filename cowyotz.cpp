#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int N, S, E;
int exp[21][10];
int ans=0;

void input()
{
    for (int i=0; i<E; i++) {
        string s; cin>>s;
        cout<<s<<'\n';
        int pair_count=0;
        for (int j=0; j<s.length(); j++) {
            if (s[j]=='x') pair_count++;
        }
        if (pair_count==1) {
            //int w=find_first(s);
            //int n=find_second(s);
        }
        else {
            bool flag=true;
            int w=0, n=0;
            int ind=0;
            for (int j=0; j<pair_count; j++) {
                string t;
                while (s[ind] != '+') {
                    cout<<ind<<'\n';
                    t+=s[ind];
                    ind++;
                }
                cout<<t<<'\n';
                ind++;
            } 
        }  

    }
}

/*bool valid(string s) 
{

}

int solve(int ind, string s) 
{
    if (ind==N) {
        if (valid(s)) {
            ans++;
        }
    }
    for (int i=1; i<=S; i++) {
        s[ind]=char(i);
        solve(ind+1);
    }
}*/


int main()
{
    cin>>N>>S>>E;
    input();

    /*for (int i=0; i<E+1; i++) {
        for (int j=1; j<S+1; j++) {
            cout<<exp[i][j]<<' ';
        }
        cout<<'\n';
    }*/

    
}