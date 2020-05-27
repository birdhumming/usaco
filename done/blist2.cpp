#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
 
int N;
int S[101], T[101], B[101]; //start, end, buckets
 
int main(void) {
    ifstream fin ("blist.in");
    ofstream fout ("blist.out");
    fin>>N;
    for (int i=1; i<=N; i++) {
        fin>>S[i]>>T[i]>>B[i];
    }
    int max_buckets=0;
    for (int t=1; t<=1000; t++) { //time
        int buckets_at_time=0;
        for (int i=1; i<=N; i++) {
            if (S[i] <= t && t <= T[i]) {
                buckets_at_time+=B[i];
            }
        }
        max_buckets=max(max_buckets, buckets_at_time); //finding max
    }
    fout<<max_buckets;
}
