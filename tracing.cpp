#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int N, T;
string cows;
vector < pair <int, pair <int, int> > > interactions;

vector <int> patient_zeros;
vector <int> Ks;

int compare_strings(string x, string y);
int infect_cows(int patient_zero, int K);
int is_infinite(int patient_zero);

int main()
{
    ifstream fin ("tracing.in");
    ofstream fout ("tracing.out");

    fin >> N >> T >> cows;
    for (int i = 0; i < T; i++)
    {
        pair <int, pair <int, int> > temp;
        int t, x, y;
        fin >> t >> x >> y;
        temp.first = t;
        temp.second.first = x;
        temp.second.second = y;
        interactions.push_back(temp);
    }
    sort (interactions.begin(), interactions.end());
    
    int infinite = 0;
    for (int i = 0; i < T; i++)
    {
        fout << interactions[i].first << " " << interactions[i].second.first << " " << interactions[i].second.second << endl;
    }

    for (int i = 0; i < N; i++)
    {
        int been_pushed_back = 0;
        for (int j = 0; j < N; j++)
        {
            if (cows[i] == '1')
            {
                cout << "patient zero: " << i << endl;
                cout << "K = " << j << endl;
                if (infect_cows(i, j) == 0 && been_pushed_back ==0)
                {
                    patient_zeros.push_back(i);
                    Ks.push_back(j);
                    been_pushed_back = 1;
                }
                if (is_infinite(i) == 0)
                {
                    infinite = 1;
                }
            }
        }
    }
    
    if (Ks.size() == 0)
    {
        fout << 0 << " " << 0 << " " << 0 << endl;
        return 0;
    }
    sort(Ks.begin(), Ks.end());
    int smallest_K = Ks[0];
    int biggest_K = Ks[Ks.size()-1];

    if (infinite == 1)
    {
        fout << patient_zeros.size() << " " << smallest_K << " " << "Infinity" << endl;
    }
    else
    {
        fout << patient_zeros.size() << " " << smallest_K << " " << biggest_K << endl;  
    }
}

int compare_strings(string x, string y)
{
    for (int i = 0; i < N; i++)
    {
        if (x[i] != y[i])
        return 1;
    }
    return 0;
}

int infect_cows(int patient_zero, int K)
{
    string cows_copy (N, '0');
    cows_copy[patient_zero] = '1';
    int shake_count[101] = {0};

    if (K == 0)
    {
        if (compare_strings(cows_copy, cows) == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    for (int i = 0; i < T; i++)
    {
        pair <int, int> temp;
        temp = interactions[i].second;
        int firstcow = temp.first - 1;
        int secondcow = temp.second - 1;
        //cout << firstcow << " " << secondcow << endl;

        if (cows_copy[firstcow] == '1' || cows_copy[secondcow] == '1') 
        //at least one of the cows interacting is infected
        {
            if (cows_copy[firstcow] == '1' && cows_copy[secondcow] == '0')
            //first cow infected, second cow healthy
            {
                if (shake_count[firstcow] < K)
                //after shaking hooves more than K times, firstcow washes hooves
                {
                    cows_copy[secondcow] = '1'; //second cow is now infected
                    cout << firstcow << " infected " << secondcow << endl;
                    cout << "shake count of first cow: " << shake_count[firstcow] << endl;
                    shake_count[firstcow]++; 
                }
            }
            else if (cows_copy[secondcow] == '1' && cows_copy[firstcow] == '0') 
            {
                if (shake_count[secondcow] < K)
                {
                    cows_copy[firstcow] = '1';
                    cout << secondcow<< " infected " << firstcow << endl;
                    cout << "shake count of second cow: " << shake_count[secondcow] << endl;
                    shake_count[secondcow]++;
                }
            }
            else
            {
                if (shake_count[firstcow] < K && shake_count[secondcow] < K)
                {
                    shake_count[firstcow]++;
                    shake_count[secondcow]++;
                    cout << "both infected " << firstcow << " " << secondcow<< endl;
                }
            }
        }
    }
    cout << cows_copy << endl;
    if (compare_strings(cows_copy, cows) == 0)
    {
        cout << "WORKED" << endl;
        return 0;
    }
    else
    {
        return 1;
    }
}


int is_infinite(int patient_zero)
{
    string cows_copy (N, '0');
    cows_copy[patient_zero] = '1';

    for (int i = 0; i < T; i++)
    {
        pair <int, int> temp;
        temp = interactions[i].second;
        int firstcow = temp.first - 1;
        int secondcow = temp.second - 1;
        //cout << firstcow << " " << secondcow << endl;

        if (cows_copy[firstcow] == '1' || cows_copy[secondcow] == '1') 
        //at least one of the cows interacting is infected
        {
            if (cows_copy[firstcow] == '1' && cows_copy[secondcow] == '0')
            //first cow infected, second cow healthy
            {
                cows_copy[secondcow] = '1'; //second cow is now infected
            }
            else if (cows_copy[secondcow] == '1' && cows_copy[firstcow] == '0') 
            {
                cows_copy[firstcow] = '1';
            }
        }
    }
    if (compare_strings(cows_copy, cows) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}