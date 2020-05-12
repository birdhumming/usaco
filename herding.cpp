#include <iostream>
#include <fstream>
using namespace std;

bool herded(int A, int B, int C) {
    if (B-A==1 && C-B==1) return true;
    return false;
}
int find_min(int A, int B, int C, int moves) {
    if (herded(A, B, C)) {
        cout<<moves;
        return 0;
    }
    int ld, rd; //left distance, right distance
    ld=B-A, rd=C-B;
    if (ld==2 || rd==2) {
        cout<<moves+1;
        return 0;
    }
    cout<<moves+2;
    return 0;
}

int find_max(int A, int B, int C, int moves) {
    if (herded(A, B, C)) 
    { 
        cout<<moves<<'\n';
        return 0;
    }
    int ld, rd;
    ld=B-A, rd=C-B;
    if (ld>=rd) {
        moves++;
        find_max(A, B-1, B, moves);
    }
    if (rd>ld) {
        moves++;
        find_max(B, B+1, C, moves);
    }
    return -1;
}

int main() {
    ifstream fin ("herding.in");
    //freopen("herding.out", "w", stdout);
    cout<<"46\n";
    int A, B, C;
    fin>>A>>B>>C;
    find_min(A, B, C, 0);
    cout<<'\n';
    find_max(A, B, C, 0);
}

