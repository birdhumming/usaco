#include <iostream>
#include <string>
using namespace std;

string S, T;

int main() 
{
    cin>>S>>T;
    string ans=""; string c;
    int lenS=S.length();
    int lenT=T.length();
    for (int i=0; i<lenS; i++) {
        c=S[i];
        ans.append(c);
        int lenA=ans.length();

        int count=0;
        if (lenA >= lenT) {
            for (int j=1; j<=lenT; j++) {
                if (ans[lenA-j] == T[lenT-j]) {
                    count++;
                }
                if (ans[lenA-j] != T[lenT-j]) {
                    break;
                }
            }
        }
        if (count==lenT) {
            ans.erase(ans.end()-lenT, ans.end());
        }
    }
    cout<<ans<<'\n';
}