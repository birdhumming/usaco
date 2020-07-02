#include <iostream>
#include <algorithm>
using namespace std;
typedef pair <long, long> ii;

long N, A, B, C, D, E, F, G, H, M;
ii cows[1500002];

long compute_w(long a, long b, long c, long d, long i) {
    long i1=1;
    for (int j=0; j<5; j++) {
        i1 = (i1 * (i % d)) % d;
    }
    long term1=((a % d) * i1) % d;
    long i2=((i % d) * (i % d)) % d;
    long term2=((b % d) * i2) % d;
    long term3=c % d;
    long ans=(term1+term2+term3) % d;
    return ans;
}

long compute_u(long e, long f, long g, long h, long i) {
    long i1=1;
    for (int j=0; j<5; j++) {
        i1 = (i1 * (i % h)) % h;
    }
    long term1=((e % h) * i1) % h;
    long i2=((i % h) * (i % h) * (i % h)) % h;
    long term2=((f % h) * i2) % h;
    long term3=g % h;
    long ans=(term1+term2+term3) % h;
    return ans;
}

bool comp(ii x, ii y) {
    if (x.first > y.first) return true;
    if (x.first == y.first) {
        return x.second < y.second;
    }
    return false;
}

int main()
{
    cin>>N>>A>>B>>C>>D>>E>>F>>G>>H>>M;
    for (long i=0; i<3*N; i++) {
        long w=compute_w(A, B, C, D, i);
        long u=compute_u(E, F, G, H, i);
        cows[i].first=u;
        cows[i].second=w;
    }
    
    sort(cows, cows+3*N, comp);

    long sum=0;
    for (int i=0; i<N; i++) {
        sum+=cows[i].second;
        sum=sum % M;
    }
    cout<<sum<<'\n';
}