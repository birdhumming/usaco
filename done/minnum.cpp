#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

int L, N;
string s;
string nums[21];
int coords[11];
vector <string> what;
int m=0;
int c=0;

bool in_nums(string b)
{
    for (int i=0; i<N; i++) {
        if (nums[i]==b) return true;
    }
    return false;
}

bool composable(string a, int len)
{
    if (len==0) {
        m=1;
        return true;
    }
    for (int i=0; i<=len; i++) {
        string b=a.substr(0, i);
        if (in_nums(b)) {
            composable(a.substr(i, len-i), len-i);
        } 
    }
    return false;
}

void gen(string s, int ind)
{
    if (ind == c) {
        what.push_back(s);
        return;
    }
    s[coords[ind]]='1';
    gen(s, ind+1);
    s[coords[ind]]='0';
    gen(s, ind+1);
}

bool a_small_b(string a, string b) {
    for (int i=L-1; i>=0; i++) {
        if (a[i]=='0' && b[i]=='1') {
            return true;
        }
    }
    return false;
}


int main()
{
    //ifstream fin ("minnum.in");
    cin>>L>>N>>s;
    for (int i=0; i<N; i++) cin>>nums[i];
    for (int i=0; i<L; i++) {
        if (s[i]=='?') {
            coords[c]=i;
            c++;
        }
    }
   
    gen(s, 0);
    string ans=what[0];
    int hh=0;
    for (int i=0; i<what.size(); i++) {
        if (composable(what[i], L) || m==1) {
            hh++;
            if (a_small_b(what[i], ans)) {
                ans=what[i];
            }
        }
        m=0;
    }
    if (hh==0) {
        cout<<"NO SOLUTION";
        return 0;
    }
    cout<<ans<<'\n';
    
    //else cout<<"Nope\n";
}
