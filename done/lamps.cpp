#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <iterator>
using namespace std;

int N, C;
int on[101];
int off[101];
set <string> ans;

int main()
{
    cin>>N>>C;
    int x;
    while (true) {
        cin>>x;
        if (x==-1) break;
        on[x-1]=1;
    }
    while (true) {
        cin>>x;
        if (x==-1) break;
        off[x-1]=1;
    }
    
    for (int m1=0; m1<2; m1++) {
        for (int m2=0; m2<2; m2++)  {
            for (int m3=0; m3<2; m3++) {
                for (int m4=0; m4<2; m4++) {
                    string start;
                    for (int i=0; i<N; i++) start+='1';
                    int m=m1+m2+m3+m4;
                    int flag=true;

                    if (m <= C && (C-m)%2==0) {
                        for (int i=0; i<N; i++) {
                            if (m1) {
                                if (start[i]=='0') start[i]='1';
                                else if (start[i]=='1') start[i]='0';
                            }
                            if (m2 && i%2==0) {
                                if (start[i]=='0') start[i]='1';
                                else if (start[i]=='1') start[i]='0';
                            }
                            if (m3 && i%2==1) {
                                if (start[i]=='0') start[i]='1';
                                else if (start[i]=='1') start[i]='0';
                            }
                            if (m4 && i%3==0) {
                                if (start[i]=='0') start[i]='1';
                                else if (start[i]=='1') start[i]='0';
                            }
                        }

                        for (int i=0; i<N; i++) {
                            if (on[i]==1 && start[i]=='0') flag=false;
                            
                            if (off[i]==1 && start[i]=='1') {
                                flag=false;
                            }
                        }
                        if (flag) {
                            ans.insert(start);
                        }
                    }
                }
            }
        }
    }
    if (set.size()==0) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    set <string>::iterator iter;

    
    for (iter=ans.begin(); iter != ans.end(); iter++) {
        string cur=*iter;
        cout<<cur<<'\n';
    }
}