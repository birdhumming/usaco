#include <iostream>
#include <string>
using namespace std;

int main()
{
    int closed_so_far=0, track=0;
    int ans=0;
    string s; cin>>s;

    for (int i=0; i<s.size(); i++) {
        char c=s[i];
        if (c=='(') {
            track++;
        }
        if (c==')') {
            //cout<<i<<'\n';
            track--;
            closed_so_far++;
        }
        if (track<0) {
            //cout<<i<<'\n';
            ans=closed_so_far;
            track+=2;
        }
    }

    closed_so_far=0; track=0;
    for (int i=s.size()-1; i>=0; i--) {
        char c=s[i];
        if (c==')') {
            track++;
        }
        if (c=='(') {
            track--;
            closed_so_far++;
        }
        if (track<0) {
            ans+=closed_so_far;
            track+=2;
        }
    }
    cout<<ans<<'\n';
}