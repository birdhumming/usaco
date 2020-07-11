#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n; cin>>n;
    long long arr[3]={0, 0, 0};
    for (int i=0; i<n; i++) {
        char c; cin>>c;
        if (c=='C') arr[0]++;
        if (c=='O') arr[1]+=arr[0];
        if (c=='W') arr[2]+=arr[1];
    }
    cout<<arr[2]<<'\n';
}