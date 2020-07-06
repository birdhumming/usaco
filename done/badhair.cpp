#include <iostream>
#include <stack>
using namespace std;

int N;

int main()
{
    cin>>N;
    long ans=0, h;
    stack <int> st;
    for (int i=0; i<N; i++) {
        cin>>h;
        while (st.size() && st.top() <= h) st.pop();
        ans+=st.size();
        st.push(h);
    }
    cout<<ans<<'\n';
}