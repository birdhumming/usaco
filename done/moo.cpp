#include <iostream>
#include <string>
using namespace std;

int find_length(int k)
{
    if (k==0) { return 3; }
    return k+3+(2*find_length(k-1));
}

char find_moo(int n)
{
    if (n <= 3) {
        if (n == 1) return 'm';
        if (n == 2) return 'o';
        if (n == 3) return 'o';
    }
    int c=0;
    while (find_length(c) < n) {
        c++;
    }
    if (n == find_length(c-1)+1) return 'm' ;
    if (n <= find_length(c-1)+c+3) return 'o';
    return find_moo(n-(find_length(c-1)+c+3));
}

int main() 
{
    int N;
    cin>>N;
    char ans = find_moo(N);
    cout<<ans<<'\n';
}