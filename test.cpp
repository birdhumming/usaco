#include <iostream>
using namespace std;

const int N = 55;
int f[N];
bool st[100];

bool mod[100];

int check(int x) {
    int res = 1;
    for (int i = 1; i < x; i++) {
        if ((x + i) % 7) res++;
    }
    return res;
}

int check2(int x) {
    for (int start = 0; start < 7; start++) {
        
    }
}

int main() {
    for (int i = 1; i <= 50; i++) {
        f[i] = max(f[i - 1], check(i));
    }

    for (int i = 0; i <= 50; i++) cout << f[i] << endl;

    return 0;
}

 
#include <iostream>
#include <algorithm>
using namespace std;
 
bool usedCow[100];
bool usedPos[100];
int pos[100];
 
 
int nCows, M, nFixed;
 
int ord[100];
 
int cFixed[101];
int pFixed[101];
 
bool works()
{
	for(int i=0;i<nCows;i++)
		usedCow[i] = usedPos[i] = 0;
	for(int i=0;i<nFixed;i++)
	{
		if(usedCow[cFixed[i]] && pos[cFixed[i]] == pFixed[i]) continue;
		if(usedCow[cFixed[i]]) return 0;
		if(usedPos[pFixed[i]]) return 0;
		usedCow[cFixed[i]] = 1;
		usedPos[pFixed[i]] = 1;
		pos[cFixed[i]] = pFixed[i];
	}
	int j = 0;
	for(int i=0;i<M;i++)
	{
		int cow = ord[i];
		if(usedCow[cow])
		{
			if(j > pos[cow]) return 0;
			j = pos[cow];
			continue;
		}
		while(usedPos[j])
		{
			j++;
			if(j == nCows)
				return 0;
		}
		usedPos[j] = 1;
		pos[cow] = j;
	}
	return 1;
}
 
int main()
{
	cin >> nCows >> M >> nFixed;
	for(int i=0;i<M;i++)
	{
		cin >> ord[i];
		ord[i]--;
	}
	for(int i=0;i<nFixed;i++)
	{
		cin >> cFixed[i] >> pFixed[i];
		cFixed[i]--, pFixed[i]--;
	}
	nFixed++;
	for(int i=0;i<nCows;i++)
	{
		cFixed[nFixed-1] = 0;
		pFixed[nFixed-1] = i;
		if(works())
		{
			cout << i+1 << '\n';
			return 0;
		}
	}
}