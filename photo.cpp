/*
problem: Farmer John is shooting his cows. 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector <int> b;

int tracker[1001] = {0};

void clear_tracker();

int main()
{
    ifstream fin ("photo.in");
    ofstream fout ("photo.out");

    fin >> N;
    int temp;
    for (int i = 0; i < N-1; i++)
    {
        fin >> temp;
        b.push_back(temp);
    }

    vector <int> a;

    int start, next;

    for (int i = 1; i < N+1; i++)
    {
        start = i;
        tracker[i] = 1;
        a.push_back(start);
        //cout << "start = " << start << endl;

        for (int j = 0; j < N-1; j++)
        {
            next = b[j] - start;
            //cout << "next = " << next << endl;

            if (next <= 0 || next > N || tracker[next] == 1)
            {
                a.clear();
                clear_tracker();
                //cout << "breaking" << endl;
                break;
            }

            start = next;
            tracker[next] = 1;
            a.push_back(next);
        }

        if (a.size() == N)
        {
            break;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i == N-1)
        {
            fout << a[i];
            return 0;
        }
        fout << a[i] << " ";
    }

}

void clear_tracker()
{
    for (int i = 0; i < 1001; i++)
    {
        tracker[i] = 0;
    }
}

