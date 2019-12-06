/*
NAME: drayale1
TASK: sort3
LANG: C++
*/

/*
    in: int N (1-1000) size of array
        for next N lines:
        a 1, 2, or 3
    out: number of swaps required to sort the array
    
    description: numbers will be given to you. sort them with an extra step: minimum 
    swaps required to completely sort array.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int N; //size of array
int nums[1001]; //numbers
int temp[1001]; //will contain sorted numbers

bool compare(int a, int b);
int solve(int ones, int twos, int threes);

int main()
{
    int ones = 0; //number of ones
    int twos = 0; //number of twos
    int threes = 0; //number of threes
    ifstream input1;
    input1.open("sort3.in");
    input1>>N;
    for (int i = 0; i < N; i++)
    {
        int x;
        input1>>x;
        if (x == 1)
        {
            ones++;
        }
        if (x == 2)
        {
            twos++;
        }
        if (x == 3)
        {
            threes++;
        }
        nums[i] = x;
        temp[i] = x;
    }
    
    sort(temp, temp + N, compare);


/*    for (int i = 0; i < N; i++)
    {
        cout<<nums[i]<<endl;
    }

    cout<<endl<<ones<<' '<<twos<<' '<<threes<<endl<<endl;

    
    for (int i = 0; i < N; i++)
    {
        cout<<temp[i]<<endl;
    }
*/
    int res = solve(ones, twos, threes);
    ofstream outfile("sort3.out");
    outfile<<res<<endl;

}

bool compare(int a, int b)
{
    if (a < b)
    {
        return true;
    }
    return false;
}

int solve(int ones, int twos, int threes)
//here, we will compare the sorted array to the original array to find the minimun swaps 
//this function can be divided into two parts: direct swapping and indirect swapping
{
    int s_count = 0; //swap count

    int twino, thino; //twos in ones section, threes in one; one in one is in correct location
    int ointw, thintw; //and doesn't need to be counted
    int ointh, twinth;
    twino = thino = ointw = thintw = ointh = twinth = 0;
    
    int i;
    for (i = 0; i < ones; i++)
    {
        if (nums[i] == 2)
        {
            twino++;
        }
        if (nums[i] == 3)
        {
            thino++;
        }
    }
    for (i = ones; i < ones + twos; i++)
    {
        if (nums[i] == 1)
        {
            ointw++;
        }
        if (nums[i] == 3)
        {
            thintw++;
        }
    }
    for (i = ones + twos; i < N; i++)
    {
        if (nums[i] == 1)
        {
            ointh++;
        }
        if (nums[i] == 2)
        {
            twinth++;
        }
    }

    //direct swapping
    s_count = min(twino, ointw) + min(twinth, thintw) + min(thino, ointh); 
    //compare twos in one and ones in two. these can be directly swapped into their correct positions
    //with only one swap. the amount of swaps is equal to the smaller of the two

    //indirect swapping
    s_count += (abs(twino - ointw) + abs(twinth - thintw) + abs(ointh - thino))/3 * 2;
    //now all that's left are the leftovers from the direct swapping. any trio of 1, 2, and 3
    //all in the wrong place can be swapped in with two swaps. divide leftovers into trios and 
    //mulitply by two.

    //divisible by 3?
    // | ones section 2 2 | | twos section 3 3 | | threes section 1 1 |
    //because each misplaced number NEEDS to swap in, the number of misplacements in each section
    //will be the same. (3c is divisible by 3)
    //the ones section is missing 2 ones, which means that two other numbers are there, 
    //which means the other sections are missing those numbers.
    
    return s_count;
}
