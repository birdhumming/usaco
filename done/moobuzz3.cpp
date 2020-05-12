#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi; 
vi stor; // first 8 numbers
 
bool ok(int x) { return x%3 && x%5; } // not fizz or buzz

int fizzbuzz(int N) 
{
	int num = (N-1)/8;
	return stor[N-8*num-1]+15*num;
}
 
int main() {
    ifstream fin ("moobuzz.in");
    ofstream fout ("moobuzz.out");
    for (int i = 1; i < 16; i++)
    {
        if (ok(i)) { stor.push_back(i); }
    }
	int N; 
    fin >> N;
	fout << fizzbuzz(N) << "\n";
}
