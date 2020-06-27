#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
 
int L,N,rf,rb;
 
int x[100000];
int c[100000];
bool isMax[100000];
 
int main()
{
    ifstream fin ("reststops.in");
    ofstream fout ("reststops.out");
	fin >> L >> N >> rf >> rb;
	for(int i=0;i<N;i++)
		fin >> x[i] >> c[i];
	int mx = 0;
	for(int i=N-1;i>=0;i--)
		if(c[i] > mx)
		{
			isMax[i] = 1;
			mx = c[i];
		}
	long long ans = 0;
	long long tf = 0;
	long long tb = 0;
	int lastx = 0;
	for(int i=0;i<N;i++) if(isMax[i])
	{
		tf += (x[i] - lastx)*((long long)rf);
		tb += (x[i] - lastx)*((long long)rb);
		ans += (tf - tb)*((long long)c[i]);
		tb = tf;
		lastx = x[i];
	}
	fout << ans << '\n';
}
