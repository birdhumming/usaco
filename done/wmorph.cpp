#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
typedef pair<string, int> si;

string start;
string last;
unordered_map<string, int> dict;
unordered_map<string, bool> visited;
string alphabet="abcdefghijklmnopqrstuvwxyz";

string make_string(string s, int pos, char c) {
    s[pos]=c;
    return s;
}

int main()
{
    cin>>start>>last;
    int len=start.length();
    int i=0; string temp;
    while (!cin.eof()) {
        cin>>temp;
        if (temp.length()==len) {
            dict[temp]=i;
            i++;
            visited[temp]=false;
        }
    }

    queue <si> q;
    q.push(make_pair(start, 0));
    visited[start]=false;
    while (!q.empty()) {
        string cs=q.front().first;
        int moves=q.front().second;
        if (cs==last) {
            cout<<moves<<'\n';
            return 0;
        }
        q.pop();
        for (i=0; i<len; i++) {
            for (int j=0; j<26; j++) {
                if (cs[i] != alphabet[j]) {
                    string ns=make_string(cs, i, alphabet[j]);
                    if (dict.contains(ns) && !visited[ns]) {
                        q.push(make_pair(ns, moves+1));
                        visited[ns]=true;
                    }
                }
            }
        }
    }
}