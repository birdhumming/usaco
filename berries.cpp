#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
 
int N, K, trees[1001];

int main()
{
	ifstream fin ("berries.in");
	ofstream fout ("berries.out");
	fin>>N>>K;
	for (int i=0; i<N; i++) fin>>trees[i];
	
}