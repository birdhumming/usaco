#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

int N;
string names[50002];
vector <string> min_names;
vector <string> max_names;

bool comp(char a, char b) { return a>b; }
/*int min_in_maxes(string low, string high, string name) {

}*/

int main()
{
    cin>>N;
    min_names.resize(N); max_names.resize(N);
    string s;
    for (int i=0; i<N; i++) {
        cin>>s;
        names[i]=s;
        sort(s.begin(), s.end());
        min_names[i]=s;
        sort(s.begin(), s.end(), comp);
        max_names[i]=s;
    }
    sort(min_names.begin(), min_names.end());
    sort(max_names.begin(), max_names.end());

    vector <string>::iterator low, upp;
    for (int i=0; i<N; i++) {
        s=names[i];
        sort(s.begin(), s.end());
        low=lower_bound(max_names.begin(), max_names.end(), s);
        sort(s.begin(), s.end(), comp);
        upp=upper_bound(min_names.begin(), min_names.end(), s);
        cout<<low-max_names.begin()+1<<' '<<upp-min_names.begin()<<'\n';
    }
}