#include <iostream>
#include <string>
using namespace std;

int N, M;
char puzzle[52][52];
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int check_moo(char m, char o) {
    int ans=0;
    if (m==o || m=='M' || o=='O') { return -1; }
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (puzzle[i][j]==m) {
                for (int c=0; c<8; c++) {
                    int x1=dx[c];
                    int y1=dy[c];
                    if (i+x1 < N && i+x1 >= 0 && j+y1 < M && j+y1 >= 0 && i+2*x1 < N && i+2*x1 >= 0 && j+2*y1 < M && j+2*y1 >= 0){
                        if (puzzle[i+x1][j+y1]==o && puzzle[i+2*x1][j+2*y1]==o) {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    cin>>N>>M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin>>puzzle[i][j];
        }
    }
    int ans=0;
    for (int i=0; i<26; i++) { //i is m
        for (int j=0; j<26; j++) { //j is o
            char m=alphabet[i];
            char o=alphabet[j];
            int temp = check_moo(m, o);
            ans=max(ans, temp);
        }
    }
    cout<<ans<<'\n';
}