#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <string> cows;

string merge_strings(string a, string b) 
{
    bool valid; int i;
    int al=a.length(); int bl=b.length();
    int start=max(0, al-bl);
    for (i=start; i<al; i++) {
        for (int j=i; j<al; j++) {
            valid= (a[j]==b[j-i]);
            if (!valid) break;
        }
        if (valid) break;
    }
    return a+b.substr(al-i);
}

int stringthing(vector <int> order) 
{
    string ans=cows[order[0]];
    for (int i=1; i<order.size(); i++) {
        ans=merge_strings(ans, cows[order[i]]);
    }
    return ans.length();
}

int main()
{
    cin>>N;
    cows.resize(N);
    for (int i=0; i<N; i++) cin>>cows[i];
    vector <int> permus; 
    int x;
    int ans=50;
    for (int i=0; i<N; i++) permus.push_back(i);
    do {
    x = stringthing(permus);
    ans=min(ans, x);
    } while (next_permutation(permus.begin(), permus.end()));

    cout<<ans<<'\n';
}
