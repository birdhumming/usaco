/*
problem:
    cows spread infection via shaking hooves. we know:
    1. exactly one cow was initially infected ("patient zero")
    2. once a cow is infected, she passes the infection along with her next K hoof shakes
    3. after K hoof shakes, the cow realizes she's infected and washes her hooves. 
    after washing her hooves, she cannot infect any more cows, but she is still infected.
given: 
    int N = the number of cows (1-100)
    int T = the number of interactions between cows (1-250)
    string of length N that tells us which cows are infected (1) and uninfected (0)
    T triplets (t, x, y) describing interactions where t is the time, x is one cow, and y is the other
do:
    find x, y, and z where:
    x is the number of cows who could've been patient zero
    y is the smallest possible value of K
    z is the largest possible value of K
    K can be 0. K can also be Infinity if there is no deducible upper bound.
note:
    1. a cow, once infected, cannot become uninfected.
    she can stop transmitting it to others, but she is still infected.
    2. by starting with a patient zero and a K, we can simulate the spread of infection by using the triplets.
    patient zero can only be one of the cows, and K can maximally be N. therefore, we can loop through
    all possible patient zeros and Ks and see if the infection pattern after all infections is equal to the
    given one.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int N, T;
string cows;
vector < pair <int, pair <int, int> > > interactions; //time, cow one, cow two

vector <int> patient_zeros;
vector <int> Ks;

int compare_strings(string x, string y); //used in both infect_cows and is_infinite
int infect_cows(int patient_zero, int K); //simulates infection spread
int is_infinite(int patient_zero); //tells whether infinity is a possible K

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
    
    int infinite = 0; //stores the result of is_infinite, tells us whether infinity is a valid K

    for (int i = 0; i < N; i++) //patient zeros
    {
        int been_pushed_back = 0; //i can work for many different js, but we only want to log i once

        for (int j = 0; j < N+1; j++) //Ks
        {
            if (cows[i] == '1')
            {
                //cout << "patient zero: " << i << endl;
                //cout << "K = " << j << endl;
                if (infect_cows(i, j) == 0 && been_pushed_back == 1)
                //i has already been logged for a previous j
                {
                    Ks.push_back(j);
                }
                else if (infect_cows(i, j) == 0 && been_pushed_back == 0)
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
    
    if (Ks.size() == 0) //no possible Ks or patient zeros
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

int infect_cows(int patient_zero, int K) //start with original infected cow and K
{
    string cows_copy (N, '0');
    cows_copy[patient_zero] = '1';

    int shake_count[101] = {0}; //shake_count[c] counts how many hooves cow c has shaken so far

    if (K == 0) //patient_zero can't infect any other cows
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
        int time = interactions[i].first;

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
                    //cout << firstcow + 1 << " infected " << secondcow + 1 << " at " << time << endl;
                    shake_count[firstcow]++; //first cow has shaken hooves with one more cow
                    //cout << "shake count of first cow: " << shake_count[firstcow] << endl;
                    //cout << "shake count of second cow: " << shake_count[secondcow] << endl;
                }
            }
            else if (cows_copy[secondcow] == '1' && cows_copy[firstcow] == '0') 
            //second cow infected, first cow healthy
            {
                if (shake_count[secondcow] < K)
                {
                    cows_copy[firstcow] = '1'; //first cow now infected
                    //cout << secondcow+1<< " infected " << firstcow +1<< " at " << time <<endl;
                    shake_count[secondcow]++; //second cow has shaken hooves with one more cow
                    //cout << "shake count of first cow: " << shake_count[secondcow] << endl;
                    //cout << "shake count of second cow: " << shake_count[firstcow] << endl;
                }
            }
            else //both cows are infected, infection status will not change
            //only the number of shakes will change
            {
                if (shake_count[firstcow] < K)
                {
                    shake_count[firstcow]++;
                }
                if (shake_count[secondcow] < K)
                {
                    shake_count[secondcow]++;
                }
            }
        }
    }

    //cout << cows_copy << endl;

    if (compare_strings(cows_copy, cows) == 0) //infection spread is identical to the one given
    {
        //cout << "WORKED" << endl;
        return 0;
    }
    else
    {
        return 1;
    }
}


int is_infinite(int patient_zero) //exactly the same as infect_cows except there's no K
//cows just keep infecting
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

int compare_strings(string x, string y)
{
    for (int i = 0; i < N; i++)
    {
        if (x[i] != y[i])
        return 1;
    }
    return 0;
}