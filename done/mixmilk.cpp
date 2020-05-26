#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int a, b, c, ac, bc, cc;
    ifstream fin ("mixmilk.in");
    ofstream fout ("mixmilk.out");
    fin>>ac>>a>>bc>>b>>cc>>c;
    for (int i=1; i<=100; i++) {
        if (i%3 == 1) {
            if (a+b <= bc) { //a into b
                b=b+a;
                a=0;
            }
            else {
                a=a-(bc-b);
                b=bc;
            }
        }
        if (i%3 == 2) { //b into c
            if (b+c <= cc) {
                c=c+b;
                b=0;
            }
            else {
                b=b-(cc-c);
                c=cc;
            }
        }
        if (i%3 == 0) { //c into a
            if (a+c <= ac) {
                a=a+c;
                c=0;
            }
            else {
                c=c-(ac-a);
                a=ac;
            }
        }
    }
    fout<<a<<'\n'<<b<<'\n'<<c<<'\n';
}